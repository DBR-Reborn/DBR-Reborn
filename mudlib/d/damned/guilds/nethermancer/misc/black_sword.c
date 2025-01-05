#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_ac(0);
    set_name("black sword");
    set("id", ({ "sword", "black sword", "long sword", "long black sword" }));
    set_short("A long black sword");
    set_long("This is a rather large sword, extending over five feet long and completely fashioned of a rare darkened steel. It appears extremely sharp at both the point and two sides of the blade, which also carries several subtle inscriptions engraved in a seemingly undecipherable language.");
    set_type("blade");
    set_quality(6);
    set_property("no add quality", 1);
    set_weight(75);
    set_material("darkened steel");
    set_value(3000);
    set_wc(50, "cutting");
    set_wc(50, "impaling");
    set_verb("slash");
    return;
}
