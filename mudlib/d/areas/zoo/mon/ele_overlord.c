#include <std.h>
#include "../zoo.h"

inherit MONSTER;

string lore1;
string lore2;
string lore3;
string lore4;

void create() {
    ::create();
    
    switch(random(3)){
    case 0:lore1="nexus";break;
    case 1:lore1="aether";break;
    case 2:lore1="chaos";break;
    }
    
    switch(random(5)){
    case 0:lore2="plasma";break;
    case 1:lore2="vacid";break;
    case 2:lore2="nexus";break;
    case 3:lore2="aether";break;
    case 4:lore2="chaos";break;
    }
    
      switch(random(14)){
    case 0:lore3="air";break;
    case 1:lore3="water";break;
    case 2:lore3="earth";break;
    case 3:lore3="fire";break;
    case 4:lore3="cold";break;
    case 5:lore3="wind";break;
    case 6:lore3="ice";break;
    case 7:lore3="electricity";break;
    case 8:lore3="inertia";break;
    case 9:lore3="plasma";break;
    case 10:lore3="vacid";break;
    case 11:lore3="nexus";break;
    case 12:lore3="aether";break;
    case 13:lore3="chaos";break;
    }
    
      switch(random(14)){
    case 0:lore4="air";break;
    case 1:lore4="water";break;
    case 2:lore4="earth";break;
    case 3:lore4="fire";break;
    case 4:lore4="cold";break;
    case 5:lore4="wind";break;
    case 6:lore4="ice";break;
    case 7:lore4="electricity";break;
    case 8:lore4="inertia";break;
    case 9:lore4="plasma";break;
    case 10:lore4="vacid";break;
    case 11:lore4="nexus";break;
    case 12:lore4="aether";break;
    case 13:lore4="chaos";break;
    }
    
    set_name("elemental overlord");
    set_id(({ "overlord", "elemental overlord", "imposing overlord", "imposing elemental overlord", "elemental" }));
    set("race", "elemental");
    set_body_type("human");
    set_level(75);
    set_overall_ac(800);
    set_combat_chance(200);
    set_short("[75] %^BOLD%^%^RED%^An imposing %^BLUE%^"+lore1+" %^BOLD%^%^RED%^elemental overlord");
    set_long("Hovering a few inches above the ground which blows beneath it, this relatively large mage shaped elemental is by far the most staggering entity you have ever laid your eyes upon. Its entire body crackles with fierce bolts of highly active energy and spheres of pulsing power swirl in each of its hands, fitted with finger blades nearly six inches long. Its eyes flash for a split second as it covers itself completely in a dazzling aura, striking fear deep into your heart.");
	set_max_hp(1000);
    set_hp(1000);
    set_skill("attack", 400 + 75*6);
    set_skill("melee", 400 + 75*6);
    set_skill("martial arts", 250);
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_stats("strength", 150 + 60*6);
    set_stats("intelligence", 150 + 60*6);
    set_stats("wisdom", 150 + 60*6);
    set_skill("elemental magic", 200 + 25+6);
    add_spell("planar wrath", "$A");
    set_spell_level("planar wrath", 6);
    set_property("melee damage", ([ lore1 : 100, lore2 : 100, lore3 : 100, lore4 : 100 ]));
    set_money("gold", random(200)*6); 
    set_property("gang bang", 1);
    set_property("energy units", 2000000000);
	set_property("lore name", lore1);
	set_property("lore name 2", lore2);
	set_property("lore name 3", lore3);
	set_property("lore name 4", lore4);
	set_property("lore power", 100*(1+random(3)));
	set_property("lore power 2", 100*(1+random(3)));
	set_property("lore power 3", 100*(1+random(3)));
	set_property("lore power 4", 100*(1+random(3)));
	//set("aggressive",1);
    return;
}