#include <std.h>
#include "../zoo.h"

inherit MONSTER;
string lore1;
string lore2;
string lore3;

void create() {
    ::create();
    
    switch(random(3)){
    case 0:lore1="nexus";break;
    case 1:lore1="aether";break;
    case 2:lore1="chaos";break;
    }
    
    switch(random(4)){
    case 0:lore2="plasma";break;
    case 1:lore2="vacid";break;
    case 2:lore2="electricity";break;
    case 3:lore2="inertia";break;
    }
    
    switch(random(11)){
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
    }
    
    set_name("elemental dragon");
    set_id(({ "dragon", "elemental dragon", "ferocious dragon", "ferocious elemental dragon" }));
    set("race", "elemental");
    set_body_type("human");
    set_level(60);
    set_combat_chance(120);
    set_short("[60] A ferocious %^BLUE%^"+lore1+" %^RED%^elemental dragon");
    set_long("Standing tall before your stunned eyes is a ten foot tall dragon, covered from head to toe in sharp shimmering scales. Powerful flowing breath foams about its mouth and its bright white eyes seem to blind you from identifying its facial expressions that do not likely favor the weak");
    set_max_hp(10000 + (6 * 2000));
    set_hp(10000 + (6 * 2000));
    set_skill("attack", 250 + 60*6);
    set_skill("melee", 250 + 60*6);
    set_stats("strength", 100 + 50*6);
    set_stats("intelligence", 100 + 50*6);
    set_stats("wisdom", 100 + 50*6);
    set_skill("elemental magic", 150 + 15+6);
    add_spell("energy sphere", "$A");
    set_spell_level("energy sphere", 6);
    add_spell("elemental breath", "$A");
    set_spell_level("elemental breath", 6);
    set_property("melee damage", ([ lore1 : 75, lore2 : 75, lore3 : 75 ]));
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_skill("dodge", 33*6);
    set_skill("parry", 38*6);
    set_money("gold", random(200)*6); 
	set_property("gang bang", 1);
	set_property("energy units", 2000000000);
	set_property("lore name", lore1);
	set_property("lore name 2", lore2);
	set_property("lore name 3", lore3);
	set_property("lore power", 60*(1+random(4)));
	set_property("lore power 2", 60*(1+random(4)));
	set_property("lore power 3", 60*(1+random(4)));
	//set("aggressive",1);
    return;
}