#include <std.h>
#include "../keep.h"

/* This is the green arcane orb, present at the end of the first floor's east wing in the north room. This item plays an integral part in the areas quest for it yields the Crystal Shard of Terra required to forge the legend key. The player can 'touch' the orb if they possess the green gem, which can be found by completing the side quest involving the dwarf living in mount nelfton. If the gem is not present or the player tries to take the orb, they will lose 500-1000 hp from energy released from it. Once activated, the player must face a powerful Silver Dragon that must be defeated to exit the room. The shard is then taken to the Paladin Temple room to be blessed by Sacrel for use in forging the key. */  

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
if(present("green gem", this_player())) {
message("my_action", "You touch the orb and before you can reast it begins to glow bright green. The green gem floats out of your inventory and moves itself into the pulsing light, transforming its color to that of a blinding white. The orb then explodes outward scattering sharp debris across the room!", this_player());
message("my_action", this_player()->query_cap_name() +" touches the orb, and it violently shatters after it flashes for several seconds with an increasingly blinding light.", environment(this_player()));
tell_room(environment(this_player()), "");
tell_room(environment(this_player()), "A mysterious voics says in Common: %^CYAN%^Impressive. You ran back and forth from Mount Nelfton just to fall into my trap! You are a far bigger fool than i thought you were. I'm sure the Silver Dragon you just released will welcome your company.");
ob = new(MON+"silver_dragon.c");
ob->move(environment(this_object()));
present("green gem", this_player())->remove();
present("pedestal", environment(this_player()))->remove();
ob = new(ITEM+"pedestal.c");
ob->set_long("This is a generally cylindrical pedestal fashioned completely of solid gold. It stands approximately four feet tall and carries four prongs at its top protruding upward in a circle.");
ob->move(environment(this_object()));
ob = new(ITEM+"terra_shard1.c");
ob->move(environment(this_object()));
remove();
return 1;
}
if(!present("blue gem", this_player())) {
message("my_action", "You touch the orb and are blasted violently backwards;by a powerful blast of energy!", this_player());
message("my_action", this_player()->query_cap_name() +" touches the orb and;flies backwards upon being struck by powerful energy!", this_player());
this_player()->add_hp(-(500 + random(500)));
return 1;
}
}
}

void create() {
::create();
set_name("green orb");
set("id", ({ "orb", "blue orb", "arcane orb", "green arcane orb" }));
set_short("%^GREEN%^A green arcane orb%^RESET%^");
set_long("This orb, perfectly spherical in shape, sits comfortably atop the golden pedestal in the center of the room. It glows faintly with incredible arcane power.");
set_weight(10000000);
set_value(0);
}
