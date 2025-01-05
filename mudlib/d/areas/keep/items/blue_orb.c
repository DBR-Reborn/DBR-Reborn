#include <std.h>
#include "../keep.h"

/* This is the blue arcane orb which plays a vital part of the black keep quest. It is located at the end of the west wing of the keep in the north room. When the player reaches the orb he/she can 'touch' it if the blue gem from the jail in the basement is present and activate it. It then shatters revealing a powerful Silver Dragon that must be defeated for it blocks the exit out. If the player touches the orb without the gem or tries to take it they will lose 500-1000 hp. The shard which is obtained from this orb must be blessed in the pool of life by Lidfino before a merchant can use it to forge the legend key. */

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
if(present("blue gem", this_player())) {
message("my_action", "You touch the orb and it immediately begins to glow an extremely bright blue. The blue gem floats out of your inventory and enters the light, transforming the blue color of the light into blinding white. A massive explosion then occurs shattering the orb!", this_player());
message("my_action", this_player()->query_cap_name() +" touches the orb, and it violently shatters after it flashes for several seconds with an increasingly blinding light.", environment(this_player()));
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "A mysterious voice says in Common: %^CYAN%^Isn't this a pleasant surprise. My favorite mortals to torture are actually falling into my traps! The Golden Dragon released from the orb will teach you to find yourself a brain. HA HA HA!");
ob = new(MON+"gold_dragon.c");
ob->move(environment(this_object()));
present("blue gem", this_player())->remove();
present("pedestal", environment(this_player()))->remove();
ob = new(ITEM+"pedestal.c");
ob->set_long("This is a generally cylindrical pedestal fashioned completely of solid gold. It stands approximately four feet tall and carries four prongs at its top protruding upward in a circle.");
ob->move(environment(this_object()));
ob = new(ITEM+"life_shard1.c");
ob->move(environment(this_object()));
remove();
return 1;
}
if(!present("blue gem", this_player())) {
message("my_action", "You touch the orb and are blasted violently backwards by a powerful blast of energy!", this_player());
message("my_action", this_player()->query_cap_name() +" touches the orb and flies backwards upon being struck by powerful energy!", environment(this_player()));
this_player()->add_hp(-(500 + random(500)));
return 1;
}
}
}

void create() {
::create();
set_name("blue orb");
set("id", ({ "orb", "blue orb", "arcane orb", "blue arcane orb" }));
set_short("%^BLUE%^A blue arcane orb%^RESET%^");
set_long("This perfectly spherical blue orb sits atop a pedestal fashioned of solid gold. It glows faintly with immense arcane power.");
set_weight(10000000);
set_value(0);
}
