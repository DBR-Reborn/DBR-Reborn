#include <clock.h>

inherit "/std/skills/long_term.c";

void create() {
    ::create();
    set_stat("constitution");
    set_dev_cost(21);
    set_fast_dev_cost(50);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill allows a player to make the body of a flesh golem. Flesh golems aren't too strong, but are probably better fighters then the caster at that level. Keep in mind that this skill only creates the body of a flesh golem, and that it needs a life spell to bring it to life. This skill takes much real time, and an organ. ",
	this_player());
}

void skill_func(object from, object at, string arg) {
  int time;
  int skill;

if(!at->id("organ")) {
      message("info", "You must use this skill on an organ.", from);
      remove();
      return;
    }
  
  if((time() - (int)from->query_last_use("construct flesh golem")) < HOUR/4)
    {
    message("info", "You are too tired to use this skill again yet.", from);
    remove();
    return;
  } 

skill = props["skill level"];
// Set when skill is fixed
// if(time < 500) time = 500;
  time = 1600 - (skill * 8);;
  message("info", "You begin to create the body.", from);
  set_work_message("You work on the body.");
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  string *wc_keys, *runes;
  mixed tmp;
  object ob;  

  from->set_last_use("construct flesh golem");
  seteuid(geteuid(this_object()));
  ob = new("/std/tailwind/obj/flesh_golem_body.c");
  ob->move(environment(from));
  message("info", "You create the body!", from);
  message("info", from->query_cap_name() + " creates a body!",
        environment(from), ({ from }));
  at->remove();
  remove();
  return;
}
