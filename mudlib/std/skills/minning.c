//TLNY2020 fully remade
#include "/adm/include/clock.h"

#define MINER ({  "eog", "eonmite", "iysaughton", "laen", \
"mabril", "platnite", "mithril", "elrodnite", "inniculmoid", \
"raysorite", "catoetine", "javednite", "davistone", "neorolite", "mcgrail", "boernerine", \
"steel", "iron"\
 })


inherit "/std/skills/skill.c";

string type;

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(10);
    set_fast_dev_cost(27);
    set_property("no target", 1);
}

void info() {
message("help",
"This skill is used to obtain minerals from the ground.  It must be used "
"on the world map, and you must be wielding some sort of pick.  "
"\n"
"Usage: use minning at <mineral type>\n\n"
"see help minerals for different types of minerals. It is highly advised that you get the prospecting skill as well to find minerals out in the wild.",
	this_player());
}


void skill_func(object from, object at, string arg) {
  object *weap;
  int i, flag;
  int S, E;



 if(!arg) {
    message("info", "You must use this skill at a mineral type. Example: use minning at iron", from);
    remove();
    return;
  }


 arg = lower_case(arg);
if(member_array(arg, MINER) >= 0) {


  if((time() - (int)from->query_last_use("minning")) / MINUTE < 1)
    {
    message("info", "You may only use this skill once every 1 mud minutes.", from);
    remove();
    return;
  }

  if(sscanf(base_name(environment(this_player())),
	    "/d/damned/virtual/room_%d_%d.world", E, S) != 2) {
    write("You can only mine outside.");
    return;
    }
/*
  if(!environment(from)->query_terrain() ||
    lower_case((string)(environment(from)->query_terrain())) != "f") {
    message("info", "You must use this skill in the forest.", from);
    remove();
    return;
  }
*/
/*
  i = sizeof(weap = (object *)from->query_wielded());
  flag = 0;
  while(i--) if((string)weap[i]->query_type() == "pick" ||
      (string)weap[i]->query_type() == "two handed polearm") flag = 1;
  if(!flag) {
    message("info", "You must wield an pick or or shovel to use this skill.", from);
    remove();
    return;
  }
*/
  from->set_last_use("minning");
  message("info", "%^CYAN%^%^BOLD%^You start digging in the ground.", from);
  message("info", "%^CYAN%^"+(string)from->query_cap_name() +
      " starts digging up the dirt.", environment(from),
      ({ from }));
  call_out("dig_up", 20, from, environment(from));
type = sprintf("%s", arg);
  return;
}
if(!member_array(arg, MINER) >= 0) {
    message("info", "You must use this skill at a specific mineral type see help minerals", from);
    remove();
   return;
}

}


void dig_up(object from, object env) {
  int z, chance, num;
  object ob;

  
  if(env != environment(from)) {
    message("info", "You have moved while attempting to dig up minerals.  "+
          "Your skill fails.", from);
    remove_call_out("dig_up");
    remove();
    return;
  }
  message("info", "%^CYAN%^"+(string)from->query_cap_name() +
      " finishes digging up the ground.", from);
  if(random(100) >= props["skill level"]) {
    message("info", "The survey of the ground fails to yield any quality minerals.", from);
from->add_exp2(5 * props["skill level"]+(this_player()->query_level()*100));
    remove(); 
    return;
  }

  env = environment(from);
  z = sizeof(MINER); 
  while(z--) {
  num = 0;
   chance = (int)env->query_mineral(type);
   while(chance - 100 > 0) {
        if(random(100) < 70) num++;
        chance -= 100;
      }
        if(random(100) < chance) { 
        num = 1;
        }
    if(num == 0) {
    message("info", "You dig and dig and are not able to find a sutable ore of "+type, from);
from->add_exp2(5 * props["skill level"]);
    remove();

    return;
    }

  message("info", "You find a vein of "+type+" and quickly dig it up and shape it into a ingot to be used.", from);
  seteuid(getuid());
ob = new("/std/diewarzau/obj/misc/ingot");
  //ob->set_metal(props["skill level"]/10);
  ob->set_value((props["skill level"]/10)*10);
  ob->set_weight((props["skill level"]/10)*4);
  if(random(100) < (props["skill level"]/11 + 1)) {
    message("info", "Upon inspection, you see that this mineral is cut from a rare "+type+" vein.", from);

  //ob->set_metal(props["skill level"]/5);
  ob->set_value((props["skill level"]/5)*10);
  ob->set_weight((props["skill level"]/5)*4);
}
    ob->set_material("metal/"+type);
    ob->move(from);
//TLNY2025 Move above here for Weight bug
if(!present(ob,from)) {
        message("info","%^CYAN%^You cannot carry anymore so the ingot falls to the ground.",
                from);
        ob->move(environment(from));
  }
from->add_exp2(15 * props["skill level"]+(this_player()->query_level()*100));
  return;
  }
}

 


          

