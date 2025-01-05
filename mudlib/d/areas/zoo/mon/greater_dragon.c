#include <std.h>
#include "../zoo.h"

inherit MONSTER;

string mater;

void create() {
  
  int i, idx, *ac_values;
  mixed auto_crit;
  mapping tmp;
  string s_tmp, *ac_keys, nothing;
  int pow = 6;
  
  ::create();
  
  
   switch(random(13)){
    case 0:mater="Iysaughton";break;
    case 1:mater="Laen";break;
    case 2:mater="Mabril";break;
    case 3:mater="Platnite";break;
    //case 4:mater="Mithril";break;
    case 5:mater="Elrodnite";break;
    case 6:mater="Inniculmoid";break;
    case 7:mater="Raysorite";break;
    case 8:mater="Catoetine";break;
    case 9:mater="Javednite";break;
    case 10:mater="Davistone";break;
    case 11:mater="Eonmite";break;
    case 12:mater="Eog";break;
    //case 13:mater="Meteorite";break;
    }
    
  set_name("Greater Dragon");
  set_id(({ "greater dragon",  "dragon"}));
  set("race", "magical-creation");
  set_body_type("dragon");
  set_property("enhance criticals", -5);
  set_level(65);
  set_short("[65]%^BLUE%^"+mater+" %^BOLD%^%^RED%^Tarrasque");
  set_long("This gargantuan dragon-like creation stands 50 feet tall and 70 feet long. It is a quadruped with a long tail, reflective carapace and two large horns on its head.");
  set("gang bang", 1);
  //set("aggressive",1);
  set_stats("intelligence", 115);
  set_stats("dexterity", 115);
  set_stats("strength", 100 + 5*pow);
  set_stats("constitution", 115);
  set_stats("wisdom", 115);
  set_hp( 6000 + pow*80 + (int)prop("hardness")/2);
  set_mp( 6000 + pow*80);
  set_skill("melee", 225 + 5*pow + (int)prop("hit bonus"));
  set_melee_damage( (mapping)query_property("melee damage") + ([ "aether" : 55+(6*pow)+(int)prop("damage bonus")*(pow/2+1) ]) );  set_skill("dodge", 155 + 4*pow);
  set_skill("parry", 160 + 4*pow);
  set_stats("strength", 200 + 6 * pow);
  set_skill("concentrate", 200);
  force_me("use concentrate");
  set_overall_ac(25*pow + (int)prop("armour bonus")*2);
  
  tmp = ([]);
  
  auto_crit = (mixed)prop("auto critical");
  
  if(auto_crit && pointerp(auto_crit)) {
    i = sizeof(auto_crit);
    while(i--) {
      if((idx=strlen(auto_crit[i])) <= 2) continue;
      auto_crit[i] = auto_crit[i][0..idx-3];
      if(member_array(auto_crit[i], DAMAGE_TYPES) < 0)
        continue;
      tmp += ([ auto_crit[i] : 75 ]);
    }
  } else if(auto_crit && mapp(auto_crit)) {
    ac_keys = keys(auto_crit);
    ac_values = values(auto_crit);
    i = sizeof(ac_keys);
    while(i--) {
        sscanf(ac_keys[i], "%s %s", s_tmp, nothing);
        ac_keys[i] = s_tmp;
      if((idx=strlen(ac_keys[i])) <= 2) continue;
      if(member_array(ac_keys[i], DAMAGE_TYPES) < 0)
        continue;
      tmp += ([ ac_keys[i] : 30 * ac_values[i] ]);
    }
  }
  set_overall_ac((int)prop("armour bonus")*2 + 4*pow);
        
    switch(random(2)){
  case 0:
    set_casting_chance(80);
    set_skill("energy manipulation", 95+3*pow);
    add_spell("force shield", "$(ME)", 1, 245*pow);
    set_spell_level("force shield", pow);
    add_spell("armour of oblivion", "$(ME)", 1, 245*pow);
    set_spell_level("armour of oblivion", pow);
    if(!query_skill("prayer")) set_skill("prayer", 97+4*pow);
    add_spell("armour of faith", "$(ME)", 1, 184*(3+pow/2));
    set_spell_level("armour of faith", 3+pow/2);
    break;
     case 1:
    set_overall_ac(25*pow + (int)prop("armour bonus")*2);
    break;
  }
  
    switch(random(2)) {
  case 0:
    set_combat_chance(95);
    set_skill("conjuration", 105 + 4*pow);
    set_skill("energy manipulation", 105 + 4*pow);
    add_spell("annihilation", "$A");
    set_spell_level("annihilation", pow);
    add_spell("internal flame", "", 1);
    set_spell_level("internal flame", 2+pow/2);
    //add_spell("meteor storm", "", 1);
    //set_spell_level("meteor storm", 1+pow/3);
    add_spell("greater elemental strike", "$A");
    set_spell_level("greater elemental strike", pow);
    set_skill("elementalism", 107+3*pow);
    break;
     case 1:
    set_casting_chance(85);
    set_skill("prayer", 95+4*pow);
    set_spell_level("heal", 3+pow/2);
    add_spell("heal", "$(ME)");
    set_spell_level("true heal", 21+pow/5);
    add_spell("true heal", "$(ME)");
    break;
  }
  
   switch(random(2)){
  case 0:
    set_hp(1500 + 100*pow + (1+pow/2)*(int)prop("hardness") / 4);
    break;
  case 1:
    set_mp(1500 + 100*pow);
    break;
  }
      return;
}


  int id(string str) {
  return ::id(replace_string(str, query_property(mater)+" ", ""));
}

string query_element() {
  return ({ "vacid", "chaos", "aether", "nexus" })[random(4)];
}

void die(object ob){

	switch(random(4)) {
	case 0:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mater);
    ob->move(this_object());
break;
	case 1:
	set_money("gold", random(200)*6); 
break;
	case 2:
	set_money("mithril", random(100)*6); 
break;
	case 3:
	set_money("gold", random(200)*6); 
break;
    }
    
   ::die();
}
