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
  
  switch(random(11)){
    case 0:mater="iysaughton";break;
    case 1:mater="laen";break;
    case 2:mater="mabril";break;
    case 3:mater="platnite";break;
    case 4:mater="mithril";break;
    case 5:mater="elrodnite";break;
    case 6:mater="inniculmoid";break;
    case 7:mater="raysorite";break;
    case 8:mater="catoetine";break;
    case 9:mater="javednite";break;
    case 10:mater="davistone";break;
    //case 11:mater="eonmite";break;
    //case 12:mater="eog";break;
    //case 13:mater="meteorite";break;
    }
  
  set_name("gargoyle");
  set_id(({ "gargoyle" }));
  set("race", "magical-creation");
  set_body_type("winged_humanoid");
  set_property("enhance criticals", -2);
  set_level(24);
  set_short("[24]%^BLUE%^"+mater+" %^BOLD%^%^RED%^Gargoyle");
  set_long("This gargoyle has and odd and elongated shape, it looks like a human sized bat");
  set_skill("concentrate", 200);
  force_me("use concentrate");
  set("gang bang", 1);
  //set("aggressive",1);
  set_stats("intelligence", 95);
  set_stats("dexterity", 95);
  set_stats("strength", 95);
  set_hp( 3500 + pow*80 + (int)prop("hardness")/2);
  set_mp( 3500 + pow*80);
  set_skill("melee", 150 + 5*pow + (int)prop("hit bonus"));
  set_skill("dodge", 85 + 4*pow);
  set_skill("parry", 90 + 4*pow);
  set_stats("strength", 210 + 6 * pow);
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
      tmp += ([ ac_keys[i] : 18 * ac_values[i] ]);
    }
  }
  set_overall_ac((int)prop("armour bonus")*2 + 4*pow);
  set_property("melee damage", tmp + ([ "crushing" : (30 + (5 * pow))
    + (int)prop("damage bonus")*(pow/2 + 1) ]) );
    
    switch(random(2)){
      case 1:
    set_melee_damage( (mapping)query_property("melee damage") +
     ([ "cutting" : 45+(6*pow)+(int)prop("damage bonus")*(pow/2+1) ]) );
    set_stats("strength", 100 + 5*pow);
    break;
    case 2:
    set_hp(800 + 100*pow + (1+pow/2)*(int)prop("hardness") / 4);
    break;
}
	switch(random(2)){
	case 1:
    set_combat_chance(80);
    set_skill("conjuration", 85 + 4*pow);
    add_spell("lightning bolt", "$A");
    set_spell_level("lightning bolt", pow);
    add_spell("explosive fireball", "", 1);
    set_spell_level("explosive fireball", 2+pow/2);
    add_spell("blizzard", "", 1);
    set_spell_level("blizzard", 1+pow/3);
    add_spell("greater elemental bolt", "$A");
    set_spell_level("greater elemental bolt", pow);
    set_skill("elementalism", 87+3*pow);
    break;
  case 2:
    set_casting_chance(70);
    set_skill("prayer", 75+4*pow);
    set_spell_level("cure critical wounds", 3+pow/2);
    add_spell("cure critical wounds", "$(ME)");
    set_spell_level("heal", 21+pow/5);
    add_spell("heal", "$(ME)");
    break;
}
	switch(random(2)){
  case 1:
    set_overall_ac(10*pow + (int)prop("armour bonus")*2);
    break;
  case 2:
    set_casting_chance(10);
    set_skill("elementalism", 75+3*pow);
    add_spell("elemental aegis", "$(ME)", 1, 245*pow);
    set_spell_level("elemental aegis", pow);
    set_skill("prayer", 77+4*pow);
    add_spell("armour of faith", "$(ME)", 1, 184*(3+pow/2));
    set_spell_level("armour of faith", 3+pow/2);
    break;
  }
  return;
}

int id(string str) {
  return ::id(replace_string(str, query_property(mater)+" ", ""));
}

string query_element() {
  return ({ "fire", "earth", "air", "water", "electricity", "ice", "wind" })[random(7)];
}

void die(object ob){

	switch(random(6)) {
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
	set_money("mithril", random(100)+24); 
break;
	case 3:
	set_money("gold", random(200)*6); 
break;
	case 4:
	set_money("gold", random(200)*6); 
break;
	case 5:
	set_money("gold", random(200)*6); 
break;
    }
    
   ::die();
}
