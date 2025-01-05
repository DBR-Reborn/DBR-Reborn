#include <std.h>
#include "../keep.h"

/* This is the paladin temple room of the black keep. There are no monsters present here initially, but this is the room where the player and his comrades will eventually face a powerful boss, the Icefire Hydra. In the room a paladin must offer the Crystal Shard of Terra to Sacrel, which is obtained from the green arcane orb. Immediately upon offering the shard the Hydra will appear and initiate combat. When the boss is defeated, the shard must be offered again. After doing so Sacrel will bless it and it can be taken to the Shadowforge where a merchant can use it in forging the Legend Key. The only exit from this room is north. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A temple room");
set_long(@ext A cracked cross nailed to the south wall grabs your immediate attention as you enter this room from the north. The black stone walled room itself is slightly large, with four stark white pillars extending from the ceiling to the floor placed perfectly equidistant from the four corners and a circle containing an insignia in the center. Aside from the previous, there is nothing else in this room, which you deduce to be a temple of some sort, most likely to a divine god.
    0   
    |   
    @
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You dont hear a sound.");
add_exit(ROOMS+"inside22", "north");
ob = new(ITEM+"stone_pillar.c");
ob->move(this_object());
ob = new(ITEM+"stone_pillar.c");
ob->move(this_object());
ob = new(ITEM+"stone_pillar.c");
ob->move(this_object());
ob = new(ITEM+"stone_pillar.c");
ob->move(this_object());
ob = new(ITEM+"cracked_cross.c");
ob->move(this_object());
set_items(([
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain.",
({ "wall" }) : "The wall is fashioned of rough black stone and is completely plain.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon. Four bright white pillar extend upwards from it all the way to the ceiling.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the floor and ceiling is very smooth. The pillars in the room are comprised of stone that is bright stark white.",
({ "ceiling" }) : "The ceiling is well crafted of black stone and is very smooth. Four white pillars extend from it down to the floor.",
({ "pillars" }) : "The four pillars in the room are stark white in appearance and extend completely from the ceiling to the floor. They are placed in absolute perfection equally distant from the corners of the room and the insignia in the center.",
({ "circle" }) : "The circle in the center of the room contains a well engraved insignia, resembling that of the Paladins of Sacrel.",
({ "insignia" }) : "The insignia inscribed the center of the room, surrounded by an engraved circle, is that of the Paladins of Sacrel. It is an elegant sword crossed over a shining silver shield.",
({ "room" }) : "This room appears to be a temple of some sorts. It contains four white pillars equidistant from the corners and a circle containing an insignia in the center. The only exit from here is to the north.",
({ "exit" }) : "The exit from this temple-esque room is north.",
({ "temple" }) : "This temple like room contains four white pillars equidistant from the corners and a circle containing an insignia in the center. The only exit from here is to the north.",
({ "south wall" }) : "This wall, fashioned of rough black stone, contains a nastily cracked cross nailed directly in the middle.",
({ "center" }) : "The center of this room contains a circle surrounding a well inscribed insignia bearing resemblance that of the Paladins of Sacrel.",
({ "middle" }) : "The middle of the south wall contains a badly cracked cross, extremely well nailed.",
({ "corner" }) : "The corner of the room is perfectly square. A white pillar is positioned perfectly between it and the insignia in the center of the room.",
({ "corners" }) : "The corners of the room are perfectly square. Four white pillars are positioned perfectly between them and the insignia in the center of the room.",
]));
}
