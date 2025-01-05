#include "/adm/include/clock.h"
#define MINERALS ({ "iron", "eog","mithril", "elrodnite", \
       "planite", "steel", "laen", "mabril", "javednite", \
        "iysaughton", "davistone", "catoetine" })

#define WOODS ({  "abachi", "aspen", "birch", "buckeye", \
"coachwood", "dogwood", "elm", "gum", "ironwood", \
"limba", "mahogany", "maple", "oak", "walnut", "willow", "pine" \
 })

#define TYPE ({ "mineral", "wood" })

inherit "/std/skills/skill.c";

string type;

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(11);
    set_fast_dev_cost(33);
    set_property("no target", 1);
}

void info() {
message("help",
"This skill is used to find minerals around the world map in order "
"to mine them.  You simply 'use' the skill anywhere on the world map "
"and a report, whose accuracy depends on your skill, will be given.",
	this_player());
}

void skill_func(object from, object at, string arg) {
  int i;
  object env;
  string *descs;

   if(!arg) {
    message("info", "You must use this skill at mineral or wood.\nExample: use prospecting at mineral", from);
    remove();
    return;
  }

  if(!archp(from))

  if((time() - (int)from->query_last_use("prospecting")) / MINUTE < 1)
    {
    message("info", "You are weary of prospecting and must rest for a few minutes.", from);
    remove();
    return;
  }
  env = environment(from);
  from->set_last_use("prospecting");
  if(!environment(from)->query_terrain()) {
    message("info", "You must use this skill outside on the world map.",
        from);
    remove();
    return;
  }
//ADD
   arg = lower_case(arg);
if(member_array(arg, TYPE) >= 0) {
  type = sprintf("%s", arg);
//END
if(arg == "mineral") {
from->add_exp2(11 * props["skill level"]+(this_player()->query_level()*100));
  message("info", "%^CYAN%^You begin searching the dirt for traces of minerals.", from);
  message("info", "You find:", from);
  i = sizeof(MINERALS);
  descs = ({});
  if(props["skill level"] > 100) props["skill level"] = 100;
  while(i--) {
//ADD TLNY2021
if(props["skill level"] >= 100){
  switch((int)env->query_mineral(MINERALS[i])) {
case -100..2:
      break;
    case 3..5:
      descs += ({ "Traces of "+MINERALS[i] });
      break;
    case 6..10:
      descs += ({ "A few traces of "+MINERALS[i] });
      break;
    case 11..20:
      descs += ({ "A small amount of "+MINERALS[i] });
      break;
    case 21..35:
      descs += ({ "A decent amount of "+MINERALS[i] });
      break;
    case 36..50:
      descs += ({ "Quite a bit of "+MINERALS[i] });
      break;
    case 51..75:
      descs += ({ "A good deal of "+MINERALS[i] });
      break;
    case 76..150:
      descs += ({ "Lots of "+MINERALS[i] });
      break;
    case 151..10000:
      descs += ({ "Tons of "+MINERALS[i] });
      break;
}
    }
//END
else
    switch((random(2)?(300-props["skill level"]*2):(random(props["skill level"]))) * (int)env->query_mineral(MINERALS[i])
          / 100 - 1) {
    case -100..2:
      break;
    case 3..5:
      descs += ({ "Traces of "+MINERALS[i] });
      break;
    case 6..10:
      descs += ({ "A few nuggets of "+MINERALS[i] });
      break;
    case 11..20:
      descs += ({ "A small amount of "+MINERALS[i] });
      break;
    case 21..35:
      descs += ({ "A decent amount of "+MINERALS[i] });
      break;
    case 36..50:
      descs += ({ "Quite a bit of "+MINERALS[i] });
      break;
    case 51..75:
      descs += ({ "A good deal of "+MINERALS[i] });
      break;
    case 76..150:
      descs += ({ "Lots of "+MINERALS[i] });
      break;
    case 151..10000:
      descs += ({ "Tons of "+MINERALS[i] });
      break;
    }
  }
  message("info", format_page(descs, 2), from);
  remove();
  return;
}
if(arg == "wood") {
from->add_exp2(11 * props["skill level"]+(this_player()->query_level()*100));
 message("info", "%^CYAN%^You begin searching the trees and as you pick up a few sticks.", from);
  message("info", "You find:", from);
  i = sizeof(WOODS);
  descs = ({});
  if(props["skill level"] > 100) props["skill level"] = 100;
  while(i--) {
//ADD TLNY2021
if(props["skill level"] >= 100){
  switch((int)env->query_mineral(WOODS[i])) {
case -100..2:
      break;
    case 3..5:
      descs += ({ "Traces of "+WOODS[i] });
      break;
    case 6..10:
      descs += ({ "A few traces of "+WOODS[i] });
      break;
    case 11..20:
      descs += ({ "A small amount of "+WOODS[i] });
      break;
    case 21..35:
      descs += ({ "A decent amount of "+WOODS[i] });
      break;
    case 36..50:
      descs += ({ "Quite a bit of "+WOODS[i] });
      break;
    case 51..75:
      descs += ({ "A good deal of "+WOODS[i] });
      break;
    case 76..150:
      descs += ({ "Lots of "+WOODS[i] });
      break;
    case 151..10000:
      descs += ({ "Tons of "+WOODS[i] });
      break;
}
    }
//END
else
    switch((random(2)?(300-props["skill level"]*2):(random(props["skill level"]))) * (int)env->query_mineral(WOODS[i])
          / 100 - 1) {
    case -100..2:
      break;
    case 3..5:
      descs += ({ "Traces of "+WOODS[i] });
      break;
    case 6..10:
      descs += ({ "A few traces of "+WOODS[i] });
      break;
    case 11..20:
      descs += ({ "A small amount of "+WOODS[i] });
      break;
    case 21..35:
      descs += ({ "A decent amount of "+WOODS[i] });
      break;
    case 36..50:
      descs += ({ "Quite a bit of "+WOODS[i] });
      break;
    case 51..75:
      descs += ({ "A good deal of "+WOODS[i] });
      break;
    case 76..150:
      descs += ({ "Lots of "+WOODS[i] });
      break;
    case 151..10000:
      descs += ({ "Tons of "+WOODS[i] });
      break;
    }
  }
  message("info", format_page(descs, 2), from);
  remove();
  return;
}

}
if(!member_array(arg, TYPE) >= 0) {
    message("info", "You must use this skill at mineral or wood.\nExample: use prospecting at mineral", from);
    remove();
   return;
}
}
