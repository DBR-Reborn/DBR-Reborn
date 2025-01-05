#include <std.h>
#include "../keep.h"

/* This is the forge room of the black keep. Present in this room are six undead warriors, not entirely difficult considering the other monsters in the halls on the way to this room, but still a challenge to mid-high level players. There is a greater forge present here, as well as a bunch of steel weapon and armour blanks, and some boards for wood related forging as well. Unlike the lab room however, there are no secrets present here. The only exit is north into the main east wing hall. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", 1);
set_property("indoors", 1);
set_short("A hot forge room");
set_long(@ext High levels of heat strike your body, and a good deal of light is emitted from the magma like fire inside the large forge illuminating this charred room from its center. The room is extremely dirty and smeared in black in several noticeable places, allowing you to infer that this room is one which at one time or possibly still does employed slave labor. Numerous boards and blanks rest against the walls and lay on the floor, the tools a blacksmith requires to do his duties.
    0   
    |   
    @
ext);
set_smell("default", "The air smells as if something is burning.");
set_listen("default", "You hear bubbling sounds coming from the forge.");
add_exit(ROOMS+"inside30", "north");
ob = new("/std/diewarzau/obj/misc/greater_forge.c");
ob->set_weight(10000000);
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/armour_blank.c");
ob->set_material("steel");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/armour_blank.c");
ob->set_material("steel");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/armour_blank.c");
ob->set_material("steel");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/armour_blank.c");
ob->set_material("steel");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/armour_blank.c");
ob->set_material("steel");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/weapon_blank.c");
ob->set_material("steel");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/weapon_blank.c");
ob->set_material("steel");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/weapon_blank.c");
ob->set_material("steel");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/weapon_blank.c");
ob->set_material("steel");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/weapon_blank.c");
ob->set_material("steel");
ob->move(this_object());
ob = new("/wizards/excelsior/tinker/board.c");
ob->move(this_object());
ob = new("/wizards/excelsior/tinker/board.c");
ob->move(this_object());
ob = new("/wizards/excelsior/tinker/board.c");
ob->move(this_object());
ob = new("/wizards/excelsior/tinker/board.c");
ob->move(this_object());
ob = new("/wizards/excelsior/tinker/board.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
set_items(([
({ "light" }) : "The light substantially illuminating this room is being generated from the magma like fire from the forge.",
({ "magma" }) : "The magma like fire inside the forge is bubbling constantly and is extraordinarily hot.",
({ "fire" }) : "The magma like fire inside the forge is bubbling constantly and is extraordinarily hot.",
({ "room" }) : "This room is extremely dirty and horribly hot. A large active forge sits directly in the center, and many blanks and boards lay across the floor and against the walls. The only noticeable exit is directly north.", 
({ "exit" }) : "The exit from this room, a truly hot one indeed, is directly to the north.",
({ "blanks" }) : "The many blanks in this room lay either scattered across the floor or are leaning against the walls.",
({ "boards" }) : "The several boards present in this room either lay across the floor or lean against the walls.",
({ "tools" }) : "The blacksmith tools present here are a good amount of metal blanks and wooden boards.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon. A few blanks and A couple boards lay scattered across it.",
({ "walls" }) : "The significantly dirty walls are fashioned of rough black stone and are completely plain of design.",
({ "wall" }) : "The significantly dirty wall is fashioned of rough black stone and is completely plain of design.",
({ "center" }) : "The center of this blistering hot room is home to a blazing forge.",
]));
}
