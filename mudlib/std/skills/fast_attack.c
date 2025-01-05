#include "/adm/include/clock.h"

inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("constitution");
    set_dev_cost(10);
    set_fast_dev_cost(30);
    set_property("no target", 1);
}

void info() {
message("help",
"This skill may be used to gain multiple attacks.  When you 'use' it, you will "
"get an attack a time. The duration is based on your skill level. This is similar to haste. This skill may only be used once per half "
"hour (mud time, see 'help calendar').",
	this_player());
}

void skill_func(object from, object at, string arg) {
  object ob;
  
  if((time() - (int)from->query_last_use("fast attack")) < HOUR/4)
    {
    message("info", "You are too tired to use this skill again yet.", from);
    remove();
    return;
  }  
  from->set_last_use("fast attack");
  seteuid(geteuid(this_object()));
  ob = new("/std/spells/shadows/hste_attack_shadow");
  ob->start_shadow(from, props["skill level"]);
  message("info", "%^RED%^%^BOLD%^Your attack has been hastened!", from);
  message("info", from->query_cap_name() + " begins to attack faster!",
        environment(from), ({ from }));
  remove();
  return;
}
