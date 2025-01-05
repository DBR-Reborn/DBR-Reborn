#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_ac(0);
    set_name("blood stained sword");
    set("id", ({ "sword", "stained sword", "blood sword", "blood stained sword" }));
    set_short("A blood stained sword");
    set_long("This rather peculiar sword extends approximately four feet in length and has a very odd shaped blade. The blade has as many edges as a well crafted key and is horribly stained in long dried up blood, suggesting that this weapon has been used to bring death to far more than a single individual.");
    set_type("blade");
    set_quality(6);
    set_property("no add quality", 1);
    set_weight(75);
    set_material("metal/mcgrail");
    set_value(5000);
    set_wc(70, "cutting");
    set_wc(60, "unholy");
    set_verb("gash");
    return;
}
