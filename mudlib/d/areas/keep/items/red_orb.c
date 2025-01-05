#include <std.h>
#include "../keep.h"

/* This is the red arcane orb present on the second floor of the black keep past the room with the false wall. It is an integral part of the areas quest, as when it is activated and shattered, the crystal shard of power is revealed. To activate it, the player must 'touch' the orb while the red gem from the palm statue on the first floor is in his inventory. The gem will then float inside the activated orb to shatter it, revealing the crystal. However, at the same time a powerful silver dragon will descend and attack, blocking the exit to defend the shard. The shard obtained from the orb must be blessed on the first floor by Taul before it can be used in forging the legend key. */

inherit OBJECT;

object ob;

void init() {
::init();
add_action("get", "get");
add_action("touch", "touch");
}

int get(string str) {
if(id(str)) {
message("my_action", "You attempt to take the orb from the pedestal but instead are blasted backwards by a powerful blast of energy!", this_player());
message("my_action", this_player()->query_cap_name() +" attempts to take the orb from the pedestal but is blasted across the room by energy released from it!", environment(this_player()));
this_player()->add_hp(-(500 + random(500)));
return 1;
}
}

int touch(string str) {
if(id(str)) {
if(present("red gem", this_player())) {
message("my_action", "You touch the orb and it immediately begins to glow and extremely bright red. The red gem floats out of your inventory and enters the light, transforming the red color of the light into blinding white. A massive explosion then occurs shattering the orb!", this_player());
message("my_action", this_player()->query_cap_name() +" touches the orb, and it violently shatters after it flashes for several seconds with an increasingly blinding light.", environment(this_player()));
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "A mysterious voice says in Common: %^CYAN%^How amusing. Too bad you activated the orb for nothing, except to release the dragon I kept inside it! And I sense it is very hungry for your flesh and bones. You mortals never learn to not fall into my many traps!");
ob = new(MON+"silver_dragon.c");
ob->move(environment(this_object()));
present("red gem", this_player())->remove();
present("pedestal", environment(this_player()))->remove();
ob = new(ITEM+"pedestal.c");
ob->set_long("This is a generally cylindrical pedestal fashioned completely of solid gold. It stands approximately four feet tall and carries four prongs at its top protruding upward in a circle.");
ob->move(environment(this_object()));
ob = new(ITEM+"power_shard1.c");
ob->move(environment(this_object()));
remove();
return 1;
}
if(!present("red gem", this_player())) {
message("my_action", "You touch the orb and are blasted violently backwards by a powerful blast of energy!", this_player());
message("my_action", this_player()->query_cap_name() +" touches the orb and flies backwards upon being struck by powerful energy!", environment(this_player()));
this_player()->add_hp(-(500 + random(500)));
return 1;
}
}
}

void create() {
::create();
set_name("red orb");
set("id", ({ "orb", "red orb", "arcane orb", "red arcane orb" }));
set_short("%^RED%^A red arcane orb%^RESET%^");
set_long("This brilliant red orb is a perfect sphere, sitting atop a pure gold pedestal. It glows faintly with immense arcane power.");
set_weight(10000000);
set_value(0);
}
