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
    
    
    set_name("elemental warrior");
    set_id(({ "warrior", "elemental warrior", "swift warrior", "swift elemental warrior" }));
    set("race", "elemental");
    set_body_type("human");
    set_level(30);
    set_short("[32] A swift %^BLUE%^"+lore1+" %^RED%^elemental warrior");
    set_long("This average sized elemental appears to be extremely nimble, standing only five feet tall but motioning its glowing body with the speed and fluency of a master martial artist. It forever serves its summoner and will give its very life for his or her cause."); 
    set_max_hp(3000 + (6 * 500));
    set_hp(3000 + (6 * 500));
    set_skill("attack", 100 + 25*6);
    set_skill("melee", 100 + 25*6);
    set_stats("strength", 50 + 25*6);
    set_property("melee damage", ([ lore1 : 40 ]));
    set_property("lore name", lore1);
    set_property("lore power", 60*(1+random(4)));
    set_money("gold", random(200)*6); 
    set_property("gang bang", 1);
    //set("aggressive",1);
    return;
}