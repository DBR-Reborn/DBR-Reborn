#include "/adm/include/clock.h"

inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("constitution");
    set_dev_cost(21);
    set_fast_dev_cost(50);
    set_property("no target", 1);
}

void info() {
message("help",
"This skill may be used to gain multiple attacks in a round.  When you 'use' it, you will "
"attack at an increased pace for a short time. Your skill impacts how long it lasts and how often you can use it.",
	this_player());
}

void skill_func(object from, object at, string arg) {
  object ob;
  
  if((time() - (int)from->query_last_use("whirlwind attack")) < (350 - props["skill level"]))
    {
    message("info", "You are too tired to use this skill again yet.", from);
    remove();
    return;
  }  
  from->set_last_use("whirlwind attack");
  seteuid(geteuid(this_object()));
  ob = new("/std/spells/shadows/whirlwind_shad");
  ob->start_shadow(from, props["skill level"]);
  message("info", "%^RED%^%^BOLD%^You begin to attack with great speed!", from);
  message("info", from->query_cap_name() + " begins to attack with great speed!",
        environment(from), ({ from }));
from->add_exp2(25 * props["skill level"]+(this_player()->query_level()*100));
  remove();
  return;
}
