//icingdeath.c coder:Byon
#include <std.h>
inherit WEAPON;
void create() {
    ::create();
    set_name("icingdeath");
    set_id( ({"scimitar","icingdeath"}) );
    set_short("A scimitar named Icingdeath");
    set_long("The scimitar belonging to Drizzt Do'Urden, named Icingdeath. 
The hilt feels cold to the touch.");
    set_parry_bonus(10);
    set_weight(120);
    set_value(500);
    set_material("metal/elrodnite");
    set_verb("slice");
    set_type("blade");
    set_wc(40, "cutting");
    set_wc(45, "impaling");
    set_wc(20, "speed");
    set_ac(5);
    set_property("no decay", 1);
    set_property("no add quality", 1);
    set_quality(6);
}
