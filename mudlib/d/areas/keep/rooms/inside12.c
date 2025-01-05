#include <std.h>
#include "../keep.h"

/* This is the lab room of the black keep, used by the keeps former alchemist before the overtaking of the structure by Owedquar. There are four undead warrior mobs in this room, that when fighting simultaneously can provide challenge to players of various level ranges, even low level heroes. There is a complete alchemy lab in this room that cannot be carried out, eight empty vials for decoration, and ten test tubes for the same purpose. However, if the player searches the vials, a couple useful potions can be found hidden behind them. The rooms only exit is north back into the west hall. */

inherit ROOM;

int found;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A dusty laboratory");
set_long(@ext Peering about, you find yourself in a medium sized laboratory. The west and east ends of the room contain nothing but rough and plain walls, the northern end the only visible exit, but the southern end contains a complete alchemy lab as well as a large rack of vials. The former is covered in thick dust, hinting that the equipment in this room has not been put to use for a significant amount of time.
    0   
    |   
    @
ext);
set_smell("default", "The air smells of chemicals.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside6", "north");
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
ob = new(MON+"undead_warrior.c");
ob->move(this_object());
/*
ob = new("/std/tailwind/obj/lab.c");
ob->set_weight(100000000);
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/small_vial.c");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/small_vial.c");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/small_vial.c");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/small_vial.c");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/small_vial.c");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/small_vial.c");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/small_vial.c");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/small_vial.c");
ob->move(this_object());
ob = new(ITEM+"test_tube.c");
ob->move(this_object());
ob = new(ITEM+"test_tube.c");
ob->move(this_object());
ob = new(ITEM+"test_tube.c");
ob->move(this_object());
ob = new(ITEM+"test_tube.c");
ob->move(this_object());
ob = new(ITEM+"test_tube.c");
ob->move(this_object());
ob = new(ITEM+"test_tube.c");
ob->move(this_object());
ob = new(ITEM+"test_tube.c");
ob->move(this_object());
ob = new(ITEM+"test_tube.c");
ob->move(this_object());
ob = new(ITEM+"test_tube.c");
ob->move(this_object());
ob = new(ITEM+"test_tube.c");
ob->move(this_object());
*/
set_items(([
({ "laboratory" }) : "The laboratory situated in the southern end of the room looks very dusty, as if it hasn't been used in a very long time.",
({ "northern end" }) : "The exit north is located in this section of the room.",
({ "southern end" }) : "In the southern end of the room sits a complete laboratory, covered in dust and appearing to have not been used in a good while.",
({ "dust" }) : "You cough as you get close to the thick dust, which covers all the lab equipment.",
({ "equipment" }) : "The lab equipment consists of all the tools an alchemist could need to perform all his/her duties.",
({ "exit" }) : "The exit from this laboratory is located in the rooms northern end.",
({ "rack" }) : "This is a relatively large rack, containing several vials and test tubes on its shelves.",
({ "shelves" }) : "Several vials and test tubes sit on these, many of which are present on the rack.",
({ "shelf" }) : "Several vials and test tubes sit on this, many of which are present on the rack.",
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough.",
({ "west wall" }) : "The west wall of this room is fashioned of rough black stone and is completely plain.",
({ "east wall" }) : "The east wall of this room is fashioned of rough black stone and is completely plain.",
({ "west end" }) : "The west end of the room contains nothing but a rough black stone wall.",
({ "wall" }) : "The wall is fashioned of rough black stone and is completely plain.",
({ "east end" }) : "The east end of the room contains nothing but a rough black stone wall.",
({ "vials" }) : "The vials sitting on the shelves of the rack are empty. However, they are all blocked forward, suggesting more may be present behind them.",
({ "test tubes" }) : "The test tubes appear very delicate, and are well stocked.",
({ "tubes" }) : "The test tubes appear very delicate, and are well stocked.",
]));
set_search("vials",(: call_other, this_object(), "do_search" :));
found=0;
}

void do_search() {
object ob;
if(found<1) {
found=1;
write("As you search the empty vials on the rack you uncover a few potions hidden behind them!");
ob = new("/std/diewarzau/obj/misc/small_vial.c");
ob->fill_vial("an alabaster potion", "alabaster potion", "/wizards/diewarzau/obj/misc/heal_func");
ob->move(this_object());
ob = new("/std/diewarzau/obj/misc/small_vial.c");
ob->fill_vial("an alabaster potion", "alabaster potion", "/wizards/diewarzau/obj/misc/heal_func");
ob->move(this_object());
ob = new("/std/tailwind/obj/speed_potion.c");
ob->move(this_object());
ob = new("/std/tailwind/obj/aura_flare_potion.c");
ob->move(this_object());
}

else
write("You find nothing odd.");
return;
}
