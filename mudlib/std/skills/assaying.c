#include <clock.h>
#define MINERALS ({ "diamond", "ruby","emerald", "sapphire", "jade", "obsidian", "amethyst", "turquoise", "onyx", "quartz" })

inherit "/std/skills/skill.c";

object shad, env;

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(11);
    set_fast_dev_cost(33);
    set_property("no target", 1);
}

void info() {
message("help",
"This skill is used to find gems in the underworld map in order "
"to mine them.  You simply 'use' the skill anywhere on the world map "
"and a report, whose accuracy depends on your skill, will be given.",
        this_player());
}

void skill_func(object from, object at, string arg) {
  int i, time;
  object ob;

  if(!archp(from))
    if((time() - (int)from->query_last_use("assaying")) / MINUTE < 10)
    {
      message("info", "You are weary of prospecting and must rest for a few
minutes.", from);
      remove();
      return;
    }
  
  env = environment(from);
  from->set_last_use("assaying");

  if(!environment(from)->query_terrain()) {
    message("info", "You must use this skill outside on the world map.",
from);
    remove();
    return;
  }

if(!present("magnifying glass", from) && !wizardp(from)){
    message("info", "You must be carrying a magnifying glass for this to work.", from);
    remove();
    return;
  }

  if(environment(from)->query_is_overworld()) {
    message("info", "You do not find any gems whatsoever here, and know you never will.",
from);
    remove();
    return;
  }

  time = 130 - props["skill level"];
  seteuid(getuid());
  ob = new("/std/spells/shadows/move_shadow");
  ob->set_move_func( (: call_other, this_object(), "int_skill" :) );
  ob->set_move_arg(from);
  ob->start_shadow(from);
  shad = ob;
  message("info", "%^ORANGE%^You begin digging up the ground, looking for any sign of gem deposits.", from);
  from->set("prospecting", 1);
  call_out("do_prospect", 30, from, time);
  return;
}

void do_prospect(object from, int left) {

  if(left > 0) {
    message("info", "%^ORANGE%^You continue digging up the ground for deposits of gems.", from);
    left = left - 30;
    call_out("do_prospect", 30, from, left);
  }
  else call_out("done_prospect", 1 , from);
  return;
}

void int_skill(object who) {
  if(!who || !objectp(who)) {
    remove();
    return;
  }
  remove_call_out("do_prospect");
  who->set("prospecting", 0);
  message("info", "%^ORANGE%^You interrupt your assaying efforts.", who);
  if(objectp(shad)) shad->external_destruct(shad);
  remove();
  return;
}

void done_prospect(object from) {   
  int i, error, x;
  string *descs;
  
  from->set("prospecting", 0);
  if(objectp(shad)) shad->external_destruct(shad);
  message("info", "%^ORANGE%^You finish digging up the ground for gem deposits.", from);
  message("info", "You find:", from);
  i = sizeof(MINERALS);
  descs = ({});
  while(i--) {
    error = random(130 - props["skill level"]);
    if(error < 0) error = 0;
    x = random(2);
    if(x == 0) error = -1 * error;

  switch((int)env->query_mineral(MINERALS[i]) + error)
  {
    case 0..2:
      break;
    case 3..5:
      descs += ({ "Traces of "+MINERALS[i] });
      break;
    case 6..10:
      descs += ({ "A few slivers of "+MINERALS[i] });
      break;
    case 11..20:
      descs += ({ "A small deposit of "+MINERALS[i] });
      break;
    case 21..35:
      descs += ({ "A decent deposit of "+MINERALS[i] });
      break;
    case 36..50:
      descs += ({ "A large deposit of "+MINERALS[i] });
      break;
    case 51..75:
      descs += ({ "A rather large deposit of "+MINERALS[i] });
      break;
    case 76..150:
      descs += ({ "A huge deposit of "+MINERALS[i] });
      break;
    case 151..10000:
      descs += ({ "The motherlode of "+MINERALS[i] });
      break;
    }
  }
  message("info", format_page(descs, 2), from);
  remove();
  return;
}
