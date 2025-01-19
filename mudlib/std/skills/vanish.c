#include "/adm/include/clock.h"

inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(25);
    set_fast_dev_cost(78);
    set_property("no target", 1);
    set_property("prereq", "invisibility art");
}

void info() {
    message("help",
        "Vanish instantly ends combat for everyone in the room. Your enemies are "
        "left bewildered, unable to track your movements as you vanish without a "
        "trace. This skill is the ultimate tool for those who strike from the "
        "shadows and disappear just as swiftly.\n"
        "    use vanish",
        this_player());
}

void do_vanish() {
    object *inv;
    int i;

    inv = all_inventory(environment(this_player()));
    for(i=0; i<sizeof(inv); i++) {
        if(!living(inv[i])) continue;
        inv[i]->cease_all_attacks();
    }
}

void skill_func(object from, object at, string arg) {
  object ob;

  if((time() - (int)from->query_last_use("vanish")) / MINUTE  < 2) {
    message("info", "You must wait a little longer before using this skill again.",
            from);
    return;
  }

  do_vanish();
  message("info", 
    "With a swift motion, you drop a small sphere to the ground. A loud BANG! " 
    "and a cloud of thick smoke engulf the area, obscuring you from view. "
    "Your figure fades into the smoke, vanishing without a trace.", from);
  message("info", 
    "A sudden BANG! deafens your ears as " + (string)from->query_cap_name() + 
    " hand flicks a small object to the ground. Smoke billows outward, "
    "obscuring everything in sight! When the smoke clears, " + 
    (string)from->query_cap_name() + " is gone, as if they were never there "
    "to begin with.", environment(from), ({ from, at }));
  seteuid(getuid());
  ob = new("/std/spells/shadows/stealth_shadow");
  from->set("stealth shad", ob);
  ob->set_my_skill("vanish");
  ob->set_hide_skill("vanish");
  ob->start_shadow(from);
  remove();
  return;
}

