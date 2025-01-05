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
"This skill allows a player to make the body of a mud golem. Mud golems
aren't too strong, but are probably better fighters then the caster at that
level. Keep in mind that this skill only creates the body of a mud golem,
and that it needs a life spell to bring it to life. This skill takes much
real time, and some mud. ",
        this_player());
}

int skill = 1;

void skill_func(object from, object at, string arg) {
  int time;

if(!at->id("mud")) {
      message("info", "You must use this skill on mud.", from);
      remove();
      return;
    }

skill = props["skill level"];
// Set when skill is fixed
  time = 1600 - (skill * 11);
  if(time < 600) time = 600;
  if(wizardp(this_player()))time = 1;
  message("info", "You begin to create the body.", from);
  set_work_message("You work on the body.");
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  string *wc_keys, *runes;
  mixed tmp;
  object ob;  

  from->set_last_use("construct mud golem");
  seteuid(geteuid(this_object()));
  ob = new("/std/tailwind/obj/mud_golem_body.c");
  ob->set_create_skill(skill);
  ob->move(environment(from));
  message("info", "You create the body!", from);
  message("info", from->query_cap_name() + " creates a body!",
        environment(from), ({ from }));
  at->remove();
  remove();
  return;
}

