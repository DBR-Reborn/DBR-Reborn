//jewelled_dagger.c coder:Byon
#include <std.h>
inherit WEAPON;
void create() {
    ::create();
    set_name("dagger");
    set_id( ({"dagger","jewelled dagger","jewel-encrusted dagger"}) );
    set_short("A jewel-encrusted dagger");
    set_long("This is the dagger that belongs to the assassin, Artemis
Entreri.  I don't think he'd be too happy to know you have it.  You can
feel the energy pulsing in the hilt.");
    set_parry_bonus(50);
    set_weight(120);
    set_value(500);
    set_material("metal/catoetine");
    set_verb("poke");
    set_type("knife");
    set_wc(40, "cutting");
    set_wc(45, "impaling");
    set_ac(10);
    set_hit((: call_other, "/wizards/diewarzau/obj/misc/vampiric_func",
"vampiric_func", 6:));
    set_property("no decay", 1);
    set_property("no add quality", 1);
    set_quality(6);
}
