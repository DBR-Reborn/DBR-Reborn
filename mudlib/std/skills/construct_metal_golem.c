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
"This skill allows a player to make the body of a metal golem. Metal golems
vary in strength depending upon the metal you use. See the mineral list for
an idea of what each metal type will do for a golem. This skill requires a
block of chemically-fused metal. ",
        this_player());
}

void skill_func(object from, object at, string arg) {
  int time;

if(!at->id("block")) {
      message("info", "You must use this skill on a metal block.", from);
      remove();
      return;
    }


skill = props["skill level"];
// Set when skill is fixed
if(time < 1200) time = 1200;
  time = 1600 - (skill * 4);
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

  from->set_last_use("construct metal golem");
  seteuid(geteuid(this_object()));
  ob = new("/std/tailwind/obj/metal_golem_body");
  ob->set_create_skill(skill);
  ob->set_material(replace_string((string)at->query_material(),
          "/", "", 1));
  ob->set_short("A " + at->query_material() + " golem body.");
  ob->move(environment(from));
  message("info", "You create the body!", from);
  message("info", from->query_cap_name() + " creates a body!",
        environment(from), ({ from }));
  at->remove();
  remove();
  return;
}

