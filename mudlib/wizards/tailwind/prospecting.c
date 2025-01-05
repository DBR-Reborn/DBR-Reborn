#include <clock.h>
#define MINERALS ({ "iron", "eog","mithril", "elrodnite", \
       "platnite", "steel", "laen", "mabril", "javednite", \
        "iysaughton", "davistone", "catoetine" })

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
"This skill is used to find minerals around the world map in order "
"to mine them.  You simply 'use' the skill anywhere on the world map "
"and a report, whose accuracy depends on your skill, will be given.",
        this_player());
}

void skill_func(object from, object at, string arg) {
  int i, time;
  object ob;

  if(!archp(from)) 
    if((time() - (int)from->query_last_use("prospecting")) / MINUTE < 10)
    {
      message("info", "You are weary of prospecting and must rest for a few
minutes.", from);
      remove();
      return;
    }
  
  env = environment(from);
  from->set_last_use("prospecting");
  if(!environment(from)->query_terrain()) {
    message("info", "You must use this skill outside on the world map.",
from);
    remove();
    return;
  }
  if(!present("prospecting pan", from) && !present("prospecting shovel", from)){
    message("info", "You must be carrying a prospecting pan and a prospecting shovel to use this skill.", from);
    remove();
    return;
  }

  if(environment(from)->query_is_underworld()) {
    message("info", "You do not find any ingots whatsoever here, and know
you never will.",
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
  message("info", "%^ORANGE%^You begin searching the dirt for traces of minerals.", from);
  from->set("prospecting", 1);
  call_out("do_prospect", 30, from, time);
  return;
}

void do_prospect(object from, int left) {

  if(left > 0) {
    message("info", "%^ORANGE%^You continue searching the dirt for traces of minerals.", from);
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
  message("info", "%^ORANGE%^You interrupt your prospecting efforts.", who);
  if(objectp(shad)) shad->external_destruct(shad);
  remove();
  return;
}

void done_prospect(object from) {   
  int i, error, x;
  string *descs;
  
  from->set("prospecting", 0);
  if(objectp(shad)) shad->external_destruct(shad);
  message("info", "%^ORANGE%^You finish searching the dirt for traces of minerals.", from);
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
      descs += ({ "A few nuggets of "+MINERALS[i] });
      break;
    case 11..20:
      descs += ({ "A small amount of "+MINERALS[i] });
      break;
    case 21..35:
      descs += ({ "A decent amount of "+MINERALS[i] });
      break;
    case 36..50:
      descs += ({ "Quite a bit of "+MINERALS[i] });
      break;
    case 51..75:
      descs += ({ "A good deal of "+MINERALS[i] });
      break;
    case 76..150:
      descs += ({ "Lots of "+MINERALS[i] });
      break;
    case 151..10000:
      descs += ({ "Tons of "+MINERALS[i] });
      break;
    }
  }
  message("info", format_page(descs, 2), from);
  remove();
  return;
}
