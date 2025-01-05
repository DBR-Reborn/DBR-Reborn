#include <std.h>
#include "../keep.h"

/* This is the room of life, the disciple prayer room of the black keep. There are no monsters in here, to signify that it is a holy place. Present however is a large pool filled with sacred holy water that serves a purpose. The head bust at its back is that of Lidfino, which lets the player know this room is related to him for parts of the quest. In this room a non-disciple can use an item called the white globe to completely regenerate their hit points and magic points to their max. A disciple however can release the holy soul held inside of the glove and recieve Lidfino's offering, which is the red gem needed to activate the red arcane orb on the second floor. It does not appear in this room however, instead it appears in the east wing at the open palm statue. A disciple can also offer the crystal shard of life to Lidfino here, and he will bless it allowing it to be used in the forging of the Legend Key. The only exit from this holy room is south.", */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", -1);
set_property("indoors", 1);
set_short("A white walled room");
set_long(@ext This room and everything in it is almost completely white, save for the water in the pool situated in the center which is clear. The walls appear rough despite the color, however the floor remains extremely smooth as does the relatively low ceiling. As you look at the pool you are greeted by a large head bust of Lidfino, the God of Life, which is molded on its back end. This alone educates you that this room is very sacred indeed.");
set_smell("default", "The air smells noticeably pure.
  
    @
    |
    0
ext);
set_listen("default", "You dont hear a sound.");
add_exit(ROOMS+"inside19", "south");
ob = new(ITEM+"pool_of_life.c");
ob->move(this_object());
set_items(([
({ "room" }) : "This room is almost completely white except for the scared water in the large pool, molded into the floor at the center and boasting a head bust of the god Lidfino. The only exit is to the south.",
({ "exit" }) : "The exit from this divine themed room is to the south.",
({ "head" }) : "This is a large head bust of Lidfino, the legendary God of Life, fashioned completely of white stone. It stares at you endlessly.",
({ "bust" }) : "This is a large head bust of Lidfino, the legendary God of Life, fashioned completely of white stone. It stares at you endlessly.",
({ "water" }) : "The water in the pool is extremely clear and still without the slightest movement.",
({ "walls" }) : "The walls are fashioned of rough bright white stone and are completely plain.",
({ "floor" }) : "The floor is extremely bright in appearance from its white color, and appears very smooth.",
({ "wall" }) : "Th wall is fashioned of rough bright white stone and is completely plain.",
({ "ceiling" }) : "The relatively low ceiling is very smooth and completely white in color.",
({ "back" }) : "On this part of the pool a large head bust of the omnipotent Lidfino is perfectly molded, the former staring endlessly at the things before it.",
({ "stone" }) : "The bright white stone fashioning the walls and pool is noticeably rough, but the stone of the same color comprising the ceiling, floor, and bust of Lidfino on the pool is significantly smooth.",
({ "back end" }) : "On this part of the pool a large head bust of the omnipotent Lidfino is perfectly molded, the former staring endlessly at the things before it.",
]));
}
