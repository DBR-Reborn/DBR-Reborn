#include "/adm/include/clock.h"

inherit "/std/skills/skill.c";

string type;
int lvl;

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(10);
    set_fast_dev_cost(27);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
message("help",
"This skill may be used to skin a corpse and obtain the hide for "
"leather.\n"
"Usage: use skin corpse at corpse 1",
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

  if(at->query_level() > 45) {
 if((int)from->query_skill("skin corpse") < 100 ) {
    message("info", "you need more skill to skin this corpse", from);
    remove();
    return;
    }
  }

  if(at->query_level() > 100) {
 if((int)from->query_skill("skin corpse") < 200 ) {
    message("info", "you need more skill to skin this corpse", from);
    remove();
    return;
    }
  }

  if(at->query_level() > 125) {
 if((int)from->query_skill("skin corpse") < 250 ) {
    message("info", "you need more skill to skin this corpse", from);
    remove();
    return;
    }
  }

  if(at->query_level() > 200) {
 if((int)from->query_skill("skin corpse") < 350 ) {
    message("info", "you need more skill to skin this corpse", from);
    remove();
    return;
    }
  }

  if(at->query_level() > 300) {
 if((int)from->query_skill("skin corpse") < 450 ) {
    message("info", "you need more skill to skin this corpse", from);
    remove();
    return;
    }
  }

  if(from->query("skinning corpse")) {
    message("info", "You can only do that once at a time!", from);
    remove();
    return;
  }


  i = sizeof(weap = (object *)from->query_wielded());
  flag = 0;
/*  
while(i--) if((string)weap[i]->query_type() == "knife") flag = 1;
  if(!flag) {
    message("info", "You must wield a knife to use this skill.", from);
    remove();
    return;
  }
*/
  message("info", "%^CYAN%^%^BOLD%^You start skinning the corpse.", from);
  message("info", "%^CYAN%^"+(string)from->query_cap_name() + " starts skinning a corpse.", environment(from), ({ from }));
  from->set("skinning corpse", 1);
  call_out("skin_corpse", 10, from, at);
  type=at->query_name();
  lvl=(int)at->query_level();
  return;
}

void skin_corpse(object from, object corpse) {
  object ob, at;

  from->set("skinning corpse", 0);
  if(!present(corpse, from) && !present(corpse, environment(from))) {
    message("info", "You have lost the corpse.  "+
          "Your skill fails.", from);
    remove_call_out("skin_corpse");
    remove();
    return;
  }

  message("info", "%^CYAN%^"+(string)from->query_cap_name() +
      " finishes skinning a corpse.", from);

    if(corpse->query_level() >= 28) {
    if(random(100)+35 >= props["skill level"]) {
    message("info", "The corpse fails to wield any quality skins.", from);
    remove();
    return;
    }
  }


    if(corpse->query_level() >= 45) {
    if(random(100)+55 >= props["skill level"]) {
    message("info", "The corpse fails to wield any quality skins.", from);
    remove();
    return;
    }
  }

    if(corpse->query_level() >= 100) {
    if(random(100)+155 >= props["skill level"]) {
    message("info", "The corpse fails to wield any quality skins.", from);
    remove();
    return;
    }
  }

    if(corpse->query_level() >= 150) {
    if(random(100)+255 >= props["skill level"]) {
    message("info", "The corpse fails to wield any quality skins.", from);
    remove();
    return;
    }
  }

    if(corpse->query_level() >= 200) {
    if(random(100)+355 >= props["skill level"]) {
    message("info", "The corpse fails to wield any quality skins.", from);
    remove();
    return;
    }
  }

    if(corpse->query_level() >= 300) {
    if(random(100)+455 >= props["skill level"]) {
    message("info", "The corpse fails to wield any quality skins.", from);
    remove();
    return;
    }
  }

    if(corpse->query_level() >= 400) {
    if(random(100)+555 >= props["skill level"]) {
    message("info", "The corpse fails to wield any quality skins.", from);
    remove();
    return;
    }
  }
  corpse->remove();

  if(random(100) >= props["skill level"]) {
    message("info", "The corpse fails to wield any quality skins.", from);
    remove();
    return;
  }
from->add_exp2(25 * props["skill level"]+(this_player()->query_level()*100));
  message("info", "You select a %^ORANGE%^leather%^RESET%^ swatch which will fashion fine armour.", from);
  seteuid(getuid());
  ob = new("/wizards/diewarzau/obj/misc/leather2");
//ADD TLNY2021
ob->set_material("leather/"+type);
ob->set_value(lvl);
ob->set_weight(lvl*2);
    ob -> set_property("new desc", "Level ["+lvl+"] "+type);
    ob -> set_property("extra long", "Level ["+lvl+"] "+type);
    ob -> set_short((string)ob->query_property("new desc"));
//TLNY2024 Move for weight bug
  ob->move(from);
//END  
  return;
}

          
