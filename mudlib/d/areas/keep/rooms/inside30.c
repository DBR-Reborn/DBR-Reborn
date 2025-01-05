#include <std.h>
#include "../keep.h"

/* This is the final room of the eastern hall of the black keep. There are three death soldiers and one vampiric demon present in this room, a small step up from the two soldiers and two demons in the hallway room in the center of the hall. North of this room is the blue arcane orb, a vital part of the quest, and south is a merchants personal forgeroom. West leads back into the central rooms of the east wing. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("The end of a dark hallway");
set_long(@ext You have reached the end of a dark hallway, judging by the dark passage leading west and the shattered lantern on the east wall that appears to have previously provided it with light. The wall with the broken lantern is noticeably rough in apperance, but the floor is extremely smooth and looks as if it has been traveled upon at very high frequency. Aside from the passage to the west you can see two other ways out of here to the north and south, both through two open archways.
    0   
    |   
 0--@
    |
    0
ext);
set_smell("default", "The air smells very old and stale.");
set_listen("default", "You hear faint footsteps.");
add_exit(ROOMS+"inside36", "north");
add_exit(ROOMS+"inside37", "south");
add_exit(ROOMS+"inside22", "west");
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new(MON+"death_soldier.c");
ob->move(this_object());
ob = new(MON+"vampiric_demon.c");
ob->move(this_object());
set_items(([
({ "lantern" }) : "The lantern on the east wall is badly shattered. It is impossible to light.",
({ "east wall" }) : "The wall is fashioned of rough black stone and has a large badly smashed lantern bolted onto its center.",
({ "wall" }) : "The wall is fashioned of rough black stone and has a large badly smashed lantern bolted onto its center.",
({ "floor" }) : "The floor, while black in appearance, is extremely smooth and appears to have been heavily traveled upon.",
({ "stone" }) : "The stone comprising the walls of the room is black and extremely rough, while the stone fashioning the floor is very smooth.",
({ "keep" }) : "The keep from within appears very dark and haunted.",
({ "passage" }) : "The passage appears very dark and can lead to anywhere.",
({ "archway" }) : "This is an archway that serves as an entrance to the adjoining room.",
({ "archways" }) : "These archways serve as entrances to the north and south rooms respectively.",
({ "rooms" }) : "The rooms beyond the archways are difficult to completely make out but appear medium sized.",
({ "hallway" }) : "This appears to be the end of a hallway. It looks as if it leads backwards down the dark passage to the west.",
({ "center" }) : "The center of the east wall contains a relatively large well destroyed lantern.",
]));
}
