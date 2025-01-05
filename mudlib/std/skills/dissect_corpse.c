#include <clock.h>

inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(10);
    set_fast_dev_cost(27);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill may be used to dissect a corpse and obtain an organ for "
"alchemistic purposes. You need a knife to use this skill.\n"
"Usage: use dissect corpse at corpse 1",
        this_player());
}


void skill_func(object from, object at, string arg) {
  object *weap;
  int i, flag;
   
  if(!at->id("corpse")) {
    message("info", "You must use this skill on a corpse.", from);
    remove();
    return;
  }
  i = sizeof(weap = (object *)from->query_wielded());
  flag = 0;
  while(i--) if((string)weap[i]->query_type() == "knife") flag = 1;
  if(!flag) {
    message("info", "You must wield a knife to use this skill.", from);
    remove();
    return;
  }
  message("info", "You start dissecting the corpse.", from);

  message("info", ""+(string)from->query_cap_name() +
      " starts dissecting a corpse.", environment(from),
      ({ from }));
  call_out("chop_down", 10, from, at);
  return;
}

void chop_down(object from, object at) {
  object ob;
  
  if(!present(at, from) && !present(at, environment(from))) {
    message("info", "You have lost the corpse.  "+
          "Your skill fails.", from);
    at->remove();
    remove();
    return;
  }
  message("info", ""+(string)from->query_cap_name() +
      " finishes dissecting a corpse.", from);
/*
  if(random(100) >= 10) {

    message("info", "The corpse fails to provide any intact organs.", from);
    at->remove();
    remove();
    return;
  }
*/
  message("info", "You select an organ which will make a fine oil.", from);
  seteuid(getuid());
  ob = new("/std/tailwind/obj/organ");
  ob->set_level(at->query_level());
  ob->move(from);
  at->remove();
  remove();
  return;
}
