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
"This skill allows a highly-skilled alchemist to make a complete alchemy lab. This skill takes much real time, 7000 gold, and an empty vial (symbolic of the entire lab). Be careful where you use this skill - the lab will appear on the floor when you are done! ",
	this_player());
}

void skill_func(object from, object at, string arg) {
  int time;
  int skill;

if(!at->id("vial")) {
      message("info", "You must use this skill on a vial.", from);
      remove();
      return;
    }

if(from->query_money("gold")<7000){
  message("info", "You don't have enough money. Skill aborted.", from);
  remove();
  return;
}

skill = props["skill level"];
// Set when skill is fixed
 if(time < 1600) time = 1600;
 time = 3200 - (skill * 8);;
  message("info", "You run out and buy the needed materials for the lab. You'll pay for them once you're done.", from);
  set_work_message("You work on the lab.");
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  string *wc_keys, *runes;
  mixed tmp;
  object ob;  

if(from->query_money("gold")<7000){
  message("info", "You don't have enough money! You have to give all the stuff back. No lab for you!", from);
  remove();
  return;
}
  seteuid(geteuid(this_object()));
  ob = new("/std/tailwind/obj/lab.c");
  ob->move(environment(from));
  message("info", "You have finished putting together the lab!", from);
  message("info", "You run to the store and pay them their 7000 gold for the supplies you used.", from);
  message("info", from->query_cap_name() + " finishes putting together a lab!",
        environment(from), ({ from }));
  from->add_money("gold",-7000);
  at->remove();
  remove();
  return;
}
