/* Add loop crap */
#include <clock.h>

inherit "/std/skills/long_term.c";

  int skill, number;
  string obpath,obname;

void create() {
    ::create();
    set_stat("constitution");
    set_dev_cost(7);
    set_fast_dev_cost(13);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"Since the normal Shaman spends much time in the dark, dark wilderness, they are able to make torches from boards of wood. You produce multiple torches depending on your skill level.\n", this_player());
}

void skill_func(object from, object at, string args) {
  int time;

if(!at->id("board")) {
      message("info", "You must use this skill on a wooden board.", from);
      remove();
      return;
    }

skill=this_player()->query_skill("torch-making") +1;

number=skill/20;

if(skill>39) {
obname="torches";
}
if(skill <= 39) {
obname="torch";
}


skill = props["skill level"];

 time = 300 - (skill);
 if(time < 180) time = 180;
 if(wizardp(from)) time=1;
  message("info", "You begin to cut the board up into the "+obname+".", from);
  set_work_message("You saw away at the board.");
  start_work(at, from, time);
  return;
}

void finish_work(object from, object at) {
  int i;
  string *wc_keys, *runes;
  mixed tmp;
  object ob;  

  message("info", "You have finished making the "+obname+"!", from);
  message("info", from->query_cap_name() + " finishes making the "+obname+"!", environment(from), ({ from }));
  seteuid(geteuid(this_object()));

for(i=0;i<number;i++) {
  ob = new("/std/obj/torch");
  ob->move(from);
}
  at->remove();
  remove();
  return;
}
