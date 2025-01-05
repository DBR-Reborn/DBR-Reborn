//pick-axe.c coder:Byon
#include <std.h>
#include "../a1.h"
inherit WEAPON;
create() {
    ::create();
    set_id(({ "pick","pick-axe","axe" }));
    set_name("pick-axe");
    set_short("dwarven pick-axe");
    set("long", "This heavy pick-axe is used to cut pieces of stone out of"
     "the pure rock wall.  It is very sharp and very dangerous.");
    set_weight(400);
    set_value(200);
    set_wc(20, "impaling");
    //set_wc(20, "crushing");
    //set_wc(20, "cutting");
    set_ac(4);
    set_quality(6);
    set_type("two handed polearm");
    set_verb("rend");
}
