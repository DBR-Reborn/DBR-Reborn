#include <std.h>
#include "../keep.h"

/* This is the main intersection of the black keep's dangerous second floor. Two shadow knights and two warlocks are present here, all of which are powerful and aggro to all players. This is considered one of the challenge rooms players should be able to overcome if they wish to proceed towards the keep's boss. West of here is the hallway that leads to the master room, and north is what appears to be an abandoned room, but contains a secret passage to the red arcane orb. East leads back to the second floor entrance room. */

inherit "/std/vault";

void create() {
object ob;
::create();
set_property("light", 1);
set_property("indoors", 1);
set_short("A bright intersection");
set_long(@ext A great deal of light from two lit magical lanterns bolted to the southern wall illuminates this distinct intersection. Sitting between those two objects of illumination on the stone wall is an absolutely glorious painting of a divine god. Looking about as you stand on the plain floor, you can see a somewhat luxurious hallway to the west and a crystal door at its end. To the north you see what appears to be a hastily abandoned room, and to the direct east a sturdy blue door blocking access to that direction.
    0   
    |   
 0--@--0
ext);
set_smell("default", "The air smells somewhat fresh.");
set_listen("default", "You hear an evil voice echoing in your head.");
add_exit(ROOMS+"inside24", "north");
add_exit(ROOMS+"inside25", "west");
add_exit(ROOMS+"inside9", "east");
set_door("blue door", ROOMS+"inside9", "east", "blue key");
set_open("blue door", 1);
set_locked("blue door", 0);
set_lock_level("blue door", 1000);
ob = new(MON+"shadow_knight.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"shadow_knight.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"warlock.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"warlock.c");
ob->set("aggressive", 1);
ob->move(this_object());
set_items(([
({ "light" }) : "The light providing this room with its illumination is coming from the two lanterns bolted on the southern wall.",
({ "lantern" }) : "This lantern, bolted to the southern wall, provides the room with a good deal of light.",
({ "lanterns" }) : "These two lanterns, both bolted to the southern wall, provide the room with a good deal of light.",
({ "southern wall" }) : "An astounding painting of a divine god, as well as two bright lanterns are present on this thick stone wall, the only one in the room.",
({ "wall" }) : "An astounding painting of a divine god, as well as two bright lanterns are present on this thick stone wall, the only one in the room.",
({ "stone" }) : "The stone comprising the wall in this room is black and extremely rough.",
({ "intersection" }) : "This intersection contains exits in three different directions. A highly decorated hallway is to the west, a blue door to the east, and a hastily abandoned room to the north.",
({ "frame" }) : "This pure golden frame encases a truly beautiful painting of a divine god. A very faint inscription is written on its bottom that says '%^BOLD%^%^WHITE%^Only the true followers of Lidfino, his disciples, contain the ability to unleash the power of his holy essence%^RESET%^'.",
({ "painting" }) : "This stellar painting sitting between the lit lanterns takes up a great deal of the southern wall along with its pure golden frame. It is a painting of a powerful divine god completely dressed in white robes hovering over what seems to be a large range of mountains. An inscription at the bottom reads '%^BLUE%^Lidfino, the God of Life%^RESET%^'.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "hallway" }) : "The hallway directly to the west of this intersection appears very highly decorated, as if a truly important individual resides beyond it.",
({ "crystal door" }) : "The crystal door, visible at the end of the rich west hallway, shines brilliantly as does the crest of Owedquar protruding from its center.",
({ "crest" }) : "The crest present on the front of the crystal door protrudes outward and is the insignia of the dark god Owedquar.",
({ "abandoned room" }) : "The room to the north appears to have been hastily abandoned.",
({ "blue door" }) : "The blue door is extremely well contructed, with a pentagram symbol above its center and an oddly shaped keyhole on the middle right.",
({ "pentagram" }) : "The pentagram on the blue door protrudes and looks well designed.",
({ "keyhole" }) : "The keyhole on the blue door looks as if it requires a key with three prongs in a triangular formation.",
]));
}
