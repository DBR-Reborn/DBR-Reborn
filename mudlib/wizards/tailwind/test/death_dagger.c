/* Weapon coded by Duridian for DarkeMud. */
/* Stolen by TW for DBR! */

#include <std.h>
inherit WEAPON;

void create() {
    mixed str;
    ::create();
    set_name("death dagger");
    set("id", ({"death dagger", "dagger", "death"}) );
    set("short", "Death Dagger");
    set("long",
   "The ultimate Invisible Dagger weapon, the Death Dagger is death
incarnate. Poison drips from its blade, and the edge is sharper than any
normal weapon's could be."
   );
   set_weight(30);
   set_value(0);

set_type("knife");
   set_wc(20, "impaling");
   set_wc(35, "cutting");
   set_ac(7);
   set_property("no add quality", 1);
   set_property("no decay", 1);
   set_quality(6);
   set_material("metal/mithril");
}

void init(){
   ::init();
   set_wield((: call_other, this_object(), "weapon_wield" :));
   set_unwield((: call_other, this_object(), "weapon_unwield" :));
}

int weapon_wield() {
    if((string)this_player()->query_class() != "invisible-dagger"){
write("You attempt to grip the Death Dagger, but it springs from your
hands.");
 return 0;
} 
write("You grab the dagger, and feel like the greatest killer who has ever
lived... yourself.");
    return 1;
}

int weapon_unwield() {
    write("Reluctantly, you let go of your dagger. The maniacal, 'kill them
all' feeling you had fades.");
    return 1;
}

