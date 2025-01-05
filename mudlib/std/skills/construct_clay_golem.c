#include <clock.h>

inherit "/std/skills/long_term.c";

int skill;

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
"This skill allows a player to make the body of a clay golem. Clay golems
aren't too strong, but are probably better fighters then the caster at that
level. Keep in mind that this skill only creates the body of a clay golem,
and that it needs a life spell to bring it to life. This skill takes much
real time, and some clay. ",
        this_player());
}

void skill_func(object from, object at, string arg) {
  int time;

if(!at->id("clay")) {
      message("info", "You must use this skill on clay.", from);
      remove();
      return;
    }


skill = props["skill level"];
// Set when skill is fixed
if(time < 600) time = 600;
  time = 1600 - (skill * 5);
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

  from->set_last_use("construct clay golem");
  seteuid(geteuid(this_object()));
  ob = new("/std/tailwind/obj/clay_golem_body.c");
  ob->set_create_skill(skill);
  ob->move(environment(from));
  message("info", "You create the body!", from);
  message("info", from->query_cap_name() + " creates a body!",
        environment(from), ({ from }));
  at->remove();
  remove();
  return;
}

