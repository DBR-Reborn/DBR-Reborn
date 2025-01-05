#include <std.h>
#include "../a1.h"
inherit MONSTER;

void create() {
int zlevel;
   object money;
   ::create();
    zlevel = (25+random(5));
   set_level(zlevel);
   set_short("["+zlevel+"]Dwarven Miner");
   set_overall_ac(zlevel+15);
    set_name("miner");
    set("gang bang", 1);
    set_id( ({ "miner","dwarf" }) );
    set("long", "This Miner is carrying some metal to be used by the blacksmiths back home.");
    set_gender("male");
    set("race", "dwarf");
    set_alignment(0);
    set_skill("two handed polearm", 190);
    set_skill("two handed blunt", 190);
    set_wielding_limbs( ({"right hand","left hand"}) );
    set_body_type("human");
    money=new("std/obj/coins");
    money->set_money("gold",(random(50)+50));
    money->move(this_object());
    new(OBJ+"metal.c")->
     move(this_object());
    new(OBJ+"pick-axe.c")->
     move(this_object());
     force_me("wield pick in right hand and left hand");
}
