#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("black shield");
    set("id", ({ "black shield", "shield" }));
    set_short("A black shield");
    set_long("This is a relatively large sized shield, entirely fashioned of a rare darkened steel and possessive of a single inscription directly on its center. This inscription appears to have been done in a completely foreign language, but is even more black than the main shield itself and is almost perfectly engraved.");
    set_type("shield");
    set_limbs(({ "left hand" }));
    set_ac(100);
    set_value(100);
    set_weight(250);
    set_material("darkened steel");
    return;
}
