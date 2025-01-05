#include <std.h>
#include "../keep.h"

/* This is the armory room of the black keep, where a former royal infantry member lived before the keeps conquering. There are no hidden secrets in this room, but there is a vital item required to proceed in the mandatory keep quests present on the ground. It is the grand axe, the only one of the numerous virtual weapons that is not in the virtual code. This requires the player to observe all the types and know what the virtual weapons are to point out which doesnt belong. During the quest, the grand axe is put to use in the clone statues room where it is placed in the hands of the statue not already wielding a weapon. Present also in this room is one death soldier, an introduction in some way to the mob as there are rooms with more further in the keep. The only exit from this room is to the south, back into the keep's eastern hall. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A cluttered armory");
set_long(@ext Numerous different types of weapons are both scattered across the floor and leaning against the black stone walls of this medium sized room. There are many steel racks throughout, some of which are knocked over, full with weaponry, or partially stocked. Hearing what you think are faint footsteps suggesting someone or something may be very close by, you can see the only obvious exit directly to the south.

    @
    |
    0
ext);
set_smell("default", "The air smells like rust.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside7", "south");
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new("/d/damned/virtual/broad-sword_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/broad-sword_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/broad-sword_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/broad-sword_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/broad-sword_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/broad-sword_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/footman's-mace_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/footman's-mace_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/footman's-mace_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/footman's-mace_6.weapon");
ob->move(this_object());
/*
ob = new("/d/damned/virtual/giant-maul_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/giant-maul_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/giant-maul_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/giant-maul_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/giant-maul_6.weapon");
ob->move(this_object());
*/
ob = new("/d/damned/virtual/shod-staff_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/shod-staff_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/shod-staff_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/shod-staff_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/knife_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/knife_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/knife_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/knife_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/knife_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/knife_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/knife_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/knife_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/knife_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/knife_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/spear_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/spear_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/spear_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/spear_6.weapon");
ob->move(this_object());
ob = new("/d/damned/virtual/spear_6.weapon");
ob->move(this_object());
ob = new(WEAP+"grand_axe.c");
ob->move(this_object());
ob = new(WEAP+"grand_axe.c");
ob->move(this_object());
ob = new(WEAP+"grand_axe.c");
ob->move(this_object());
ob = new(WEAP+"grand_axe.c");
ob->move(this_object());
set_items(([
({ "weaponry" }) : "The weaponry present in this room is very diverse, and it seems as if something is present for most all weapon types.",
({ "rack" }) : "This rack is well crafted of good steel are is used for the purpose of holding weapons.",
({ "exit" }) : "The exit from this room is located directly to the south.",
({ "maces" }) : "Several well crafted footman's maces are present in the room, either lying against the walls or scattered on the floor.",
({ "swords" }) : "Many broad swords are here, half of which are on a steel rack and the other half scattered on the floor.",
({ "broad swords" }) : "Many broad swords are here, half of which are on a steel rack and the other half scattered on the floor.",
({ "knives" }) : "A great deal of professionally forged and sharpened knives are here, all of which fill one of the steel racks.",
({ "mauls" }) : "A few very large mauls are all leaning against the walls of the room.",
({ "spears" }) : "A couple spears are standing tall on a steel rack, while a few others are leaning against the walls.",
({ "axes" }) : "A couple very large polearm axes are laying on the cluttered floor.",
({ "grand axes" }) : "A couple very large polearm axes are laying on the cluttered floor.",
({ "staves" }) : "A few well designed intricate shod staves are either laying sideways on a steel rack or laying in the clutter on the floor.",
({ "giant mauls" }) : "A few very large mauls are all leaning against the walls of the room.",
({ "shod staves" }) : "A few well designed intricate shod staves are either laying sideways on a steel rack or laying in the clutter on the floor.",
({ "footman's maces" }) : "Several well crafted footman's maces are present in the room, either lying against the walls or scattered on the floor.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the floor is very smooth.",
({ "wall" }) : "The wall is fashioned of rough black stone and is completely plain, save for several different types of weapons leaning against it.",
({ "racks" }) : "The steel racks in this room either contain a full stock of weapons, a partial stock, are empty, or are knocked over.",
({ "weapons" }) : "A seemingly countless amount of weapons reside within this room, either on a rack, laying against a wall, or scattered across the floor.",
({ "room" }) : "This is a medium sized room, with a huge amount of various types of weapons present all over.",
({ "floor" }) : "The floor, while black in appearance and cluttered thoroughly with different types of weapons, is extremely smooth and appears to have been heavily traveled upon.",
({ "keep" }) : "The keep from within appears to be extremely dark and haunted.",
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain, save for several different types of weapons leaning against them.",
]));
}
