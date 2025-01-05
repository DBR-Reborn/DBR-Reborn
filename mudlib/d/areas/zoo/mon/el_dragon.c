#include <std.h>
#include "../zoo.h"

inherit MONSTER;

string lore1;

void create() {
  ::create();

 switch(random(14)){
    case 0:lore1="air";break;
    case 1:lore1="water";break;
    case 2:lore1="earth";break;
    case 3:lore1="fire";break;
    case 4:lore1="cold";break;
    case 5:lore1="wind";break;
    case 6:lore1="ice";break;
    case 7:lore1="electricity";break;
    case 8:lore1="inertia";break;
    case 9:lore1="plasma";break;
    case 10:lore1="vacid";break;
    case 11:lore1="nexus";break;
    case 12:lore1="aether";break;
    case 13:lore1="chaos";break;
    }
    
  set_id(({ "elemental", "dragon", "elemental dragon" }));
  set("race", "elemental");
  set_body_type("winged-humanoid");
  set_name("elemental");
  set_short("[22]%^BLUE%^"+lore1+" %^RED%^Dragon");
  set_long("This greater elemental dragon glows with energy.");
  set_level(22);
  set_exp(400000);
  set_max_hp(1400 + 120*6);
  set_hp(1400 + 120*6);
  set_property("base hp regen", 22 + 5*6);
  set_skill("concentrate", 200);
  force_me("use concentrate");
  set_property("melee damage", ([ lore1 : 38 + 5*6 ]));
  set_skill("melee", 80 + 6 * 5);
  set_skill("parry", 75 + 6 * 5);
  set_skill("dodge", 70 + 6 * 5);
  set_skill("elementalism", 80);
  set_max_mp(1200 + 100 *6);
  set_mp(1200 + 100*6);
  set_property("base mp regen", 25 + 4 * 6);
  set_spell_level("elemental bolt", 6);
  add_spell("elemental bolt", "$A");
  set_spell_level("greater elemental bolt", 6);
  add_spell("greater elemental bolt", "$A");
  set_spell_level("elemental strike", 6);
  add_spell("elemental strike", "$A");
  set_combat_chance(100);
  set_overall_ac(20+5*6);
  set_money("gold", random(200)*6); 
  set_property("gang bang", 1);
  return;
}

string query_element() { return lore1; }