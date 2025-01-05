#include <std.h>
#include "../keep.h"

/* This is a copy of a Death Dagger used by the Invisible-Dagger Guild. It has identical descriptions to that of the real dagger, but it just serves the purpose of having the add_action function as part of pulling it out of the oak table to allow the contract on it to be taken. When the dagger is removed, this item will be destroyed and a real Death Dagger will be replaced that players can take. */

inherit WEAPON;

object ob;

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
set_property("no get", 1);
   set_quality(6);
   set_material("metal/mithril");
}

void init(){
   ::init();
   set_wield((: call_other, this_object(), "weapon_wield" :));
   set_unwield((: call_other, this_object(), "weapon_unwield" :));
add_action("pull", "pull");
add_action("get", "get");
}

int pull(string str) {
if(id(str)) {
if(this_player()->query_stats("strength") > 400) {
message("my_action", "With superhuman might, you manage to pull the dagger out of the oak table! Upon doing so, the weapon quickly leaves your hands due to the instantly removed resistance previously provided by the table and flies across the room, eventually landing on the floor.", this_player()); 
message("my_action", this_player()->query_cap_name() +" pulls up on the dagger with incredible force and removes it from the table! The dagger flies across the room upon doing so and lands on the floor.", environment(this_player()));
present("contract")->remove();
ob = new(ITEM+"contract2.c");
ob->move(environment(this_object()));
ob = new("/d/areas/idarea/obj/death_dagger.c");
ob->move(environment(this_object()));
remove();
return 1;
}
message("my_action", "You pull up on the dagger with all the strength you can muster. Unfortunately, it does not budge.", this_player());
message("my_action", this_player()->query_cap_name() +" pulls up on the dagger but fails to remove it from the table.", environment(this_player()));
return 1;
}
}

int get(string str) {
if(id(str)) {
message("my_action", "You cannot get this dagger without first pulling it out of the table.", this_player());
return 1;
}
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

