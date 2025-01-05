//pick.c coder:Byon
#include <std.h>
#include "../a1.h"
inherit WEAPON;
create() {
    ::create();
    set_id(({ "pick" }));
    set_name("pick");
    set_short("dwarven pick");
    set("long", "This heavy pick is used to cut pieces of stone out of "
     "the pure rock wall.  It is very sharp and very dangerous.");
    set_weight(300);
    set_value(150);
    set_wc(15, "impaling");
    //set_wc(15, "crushing");
    set_ac(3);
    set_quality(6);
    set_type("two handed polearm");
    set_verb("slam");
}
