#include <std.h>

inherit ROOM;

void create() {
    object ob;
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("quick study", 1);
    set_short("The Nexus Chamber of the Nethermancer Guild");
    set_long("This is a perfectly circular chamber, notably large in size and completely barren of any design on the walls or any items on the floor save for one extremely large artifact. That artifact is a large glowing nexus that serves as a permanent gateway to the netherworld beyond, where Nethermancers can draw souls into various soul orbs for the creation of different types of pets. It is also at this nexus that nethermancers draw forth the sheer power to transform those orbs into temporary magical power or into living undead beings.");
    add_exit("/wizards/cythug/nethermancer/rooms/skill_room", "north");
}

void reset() {
    if(!present("nexus")) new("/wizards/cythug/nethermancer/misc/guild_lesser_nexus.c")->move(this_object());
}
