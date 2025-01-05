#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("gravewyrm");
    set("race", "wyvern");
    set_combat_chance(120);
    set_id(({ "gravewyrm", "dragon", "wyvern", "undead" }));
    set_body_type("dragon");
    set_level(70);
    set_property("enhance criticals", -2);
    //set_property("nethermancer pet", 1);
    set_property("pet name", "gravewyrm");
    //set_property("energy units", 2000000000);
    //set_property("lore power", 250);
    set_overall_ac(500);
    set_short("[70]Gravewyrm");
    set_property("pet short", "Gravewyrm");
    //call_out("nether_form_check", 0);
    set_long("Hovering approximately four feet above the ground from the use of what can only be described as bladed wings, this awesomely feasome looking wyvern looks as if it is preparing to nastily tear apart an unsuspecting target and prey upon its fresh remains. With nearly six inch long nails on both its claws and its feet as well as three inch long teeth and a flashing light within its open mouth, it looks as if it can perform that deed rather effectively. You cannot help but wonder what elite type of magical powers could possibly have created this gruesome monster.");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    //call_out("element_func", 10);
    set_max_hp(13000 + 1300*6);
    set_hp(13000 + 1300*6);
    set_max_mp(11750 + 1175*6);
    set_mp(11750 + 1175*6);
    set_skill("attack", 74*6);
    set_skill("melee", 74*6);
    set_skill("dodge", 55*6);
    set_skill("parry", 66*6);
    //set_skill("elemental magic", 70*6);
    //add_spell("elemental breath", "$A");
    //set_spell_level("elemental breath", 6);
    set_property("melee damage", ([ "cutting" : 50 + (14 * 6), "acid" : 50 + (14 * 6), "radiation" : 50 + (14 * 6), "crushing" : 50 + (14 * 6) ]));
	set_property("gang bang", 1);
    set_money("gold", random(200)*6);
    set("aggressive",1);
return;
}
/*
void element_func() {
    int number;

    number = random(12) + 1;

    if(number == 1) set_property("lore name", "acid");
    if(number == 2) set_property("lore name", "cold");
    if(number == 3) set_property("lore name", "darkness");
    if(number == 4) set_property("lore name", "disruption");
    if(number == 5) set_property("lore name", "electricity");
    if(number == 6) set_property("lore name", "plasma");
    if(number == 7) set_property("lore name", "infernal");
    if(number == 8) set_property("lore name", "radiation");
    if(number == 9) set_property("lore name", "reflection");
    if(number == 10) set_property("lore name", "sonic");
    if(number == 11) set_property("lore name", "time");
    if(number == 12) set_property("lore name", "vacuum");
    call_out("element_func", 10);
}*/