#include <std.h>
#include "../keep.h"

/* This is the warlock room of the black keep. Present here are a powerful combo of three warlocks, making this one of the most dangerous rooms on the entire first floor. There is nothing special in this room, but an extremely vital quest clue is here. The banner on the back wall is that of a large gem, and in the center of the room are three crystal balls. From this, players can infer that they must have corresponding colored gems in order to activate the arcane orbs on both the first and second floors. If the player knows this clue however already, this room can be bypassed in the quest. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A room of magic");
set_long(@ext Three large crystal balls lay positioned in a perfect triangular shape on a low platform in the center of this somewhat large room. Very faint streams of energy are seen moving throughout the air, suggesting this is a room where a great deal of magical practice takes place. The stone walls are plain except for the large banner on the back wall, as is the floor save for the platform.
    0   
    |   
    @
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside27", "north");
ob = new(ITEM+"crystal_ball.c");
ob->move(this_object());
ob = new(ITEM+"crystal_ball.c");
ob->move(this_object());
ob = new(ITEM+"crystal_ball.c");
ob->move(this_object());
ob = new(MON+"warlock.c");
ob->move(this_object());
ob = new(MON+"warlock.c");
ob->move(this_object());
ob = new(MON+"warlock.c");
ob->move(this_object());
set_items(([
({ "balls" }) : "These very large spherical balls are fashioned entirely of crystal. They sit in a perfectly triangular formation on a platform in the center of the room.",
({ "formation" }) : "The formation created by the three crystal balls on the platform is perfectly triangular.",
({ "shape" }) : "The shape created by the three crystal balls on the platform is perfectly triangular.",
({ "platform" }) : "This is a low rising platform, positioned in the center of the room. Three perfectly spherical crystal balls are embedded into it in a triangular formation.",
({ "center" }) : "The center of this room contains a low platform, containing three crystal balls in a triangular formation.",
({ "room" }) : "This is a somewhat large room, with a banner on the back wall and a low rising platform containing three crystal balls in a triangular formation in the center. The only exit from the room that is visible is north.",
({ "exit" }) : "The exit from this somewhat large room is north",
({ "energy" }) : "The faint and barely visible streams of energy pass throughout the air endlessly.",
({ "streams" }) : "The faint and barely visible streams of energy pass throughout the air endlessly.",
({ "stream" }) : "This faint and barely visible stream of energy passes through the air endlessly.",
({ "walls" }) : "The walls are fashioned of rough black stone and are completely plain, except for the back wall which contains a large banner.",
({ "back wall" }) : "This wall is fashioned of rough black stone and contains a relatively large banner.",
({ "wall" }) : "The wall is fashioned of rough black stone and is completely plain.",
({ "stone" }) : "The stone comprising the walls is black and extremely rough, while the stone fashioning the floor is very smooth.",
({ "banner" }) : "This is a very large banner hanging on the back wall. It is an enormous depiction of a gem, a hand, and a ball, likely some sort of mysterious insignia.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon. A low platform is positioned on it in the center of the room.",
]));
}
