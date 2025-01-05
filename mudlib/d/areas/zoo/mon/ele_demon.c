#include <std.h>
#include "../zoo.h"

inherit MONSTER;
string lore1;
string lore2;

void create() {
    ::create();
    
    switch(random(5)){
    case 0:lore1="nexus";break;
    case 1:lore1="aether";break;
    case 2:lore1="chaos";break;
    case 3:lore1="plasma";break;
    case 4:lore1="vacid";break;
    }
    
    switch(random(14)){
    case 0:lore2="air";break;
    case 1:lore2="water";break;
    case 2:lore2="earth";break;
    case 3:lore2="fire";break;
    case 4:lore2="cold";break;
    case 5:lore2="wind";break;
    case 6:lore2="ice";break;
    case 7:lore2="electricity";break;
    case 8:lore2="inertia";break;
    case 9:lore2="plasma";break;
    case 10:lore2="vacid";break;
    case 11:lore2="nexus";break;
    case 12:lore2="aether";break;
    case 13:lore2="chaos";break;
    }
    
    set_name("elemental demon");
    set_id(({ "demon", "elemental demon", "fearsome demon", "fearsome elemental demon" }));
    set("race", "elemental");
    set_body_type("human");
    set_level(45);
    set_combat_chance(120);
    set_short("[45] A fearsome %^BLUE%^"+lore1+" %^RED%^elemental demon");
    set_long("This ferocious creature is a very powerful demon shaped elemental. It's hands come fitted with razor sharp pulsing claws and its enormous eyes flash several different colors as the beast lets out a shuddering roar.");
	set_max_hp(5000 + (6 * 1500));
    set_hp(5000 + (6 * 1500));
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_skill("attack", 150 + 40*6);
    set_skill("melee", 150 + 40*6);
    set_stats("strength", 50 + 50*6);
    set_stats("intelligence", 50 + 50*6);
    set_skill("elemental magic", 100 + 10+6);
    add_spell("energy sphere", "$A");
    set_spell_level("energy sphere", 6);
    set_property("melee damage", ([ lore1 : 50, lore2 : 50]));
    set_money("gold", random(200)*6); 
	set_property("gang bang", 1);
	set_property("energy units", 2000000000);
	set_property("lore name", lore1);
	set_property("lore name 2", lore2);
	set_property("lore power", 60*(1+random(4)));
	set_property("lore power 2", 60*(1+random(4)));
	//set("aggressive",1);
    return;
}