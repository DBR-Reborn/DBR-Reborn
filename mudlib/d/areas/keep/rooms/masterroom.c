#include <std.h>
#include "../keep.h"

/* This is the master room of the black keep, the residence of the keep's leader. There are no monsters present in the room when the player enters, but approximately 5-10 seconds after the first player enters, Owedquar's Shadow, the boss mob of the area, materializes and floats down from the tall ceiling. Immediately upon appearing he casts his powerful storm of ages spell to start the fight. Only with a very diverse and extremely powerful offense/defense party of heroes and pets will this creature of darkness be overcome, and it will likely take several tries to do so because a lot of the battle is based on luck and what the boss decides to cast. The only exit from this room is east back through the crystal door. */

inherit "/std/vault";

void create() {
object ob;
::create();
set_property("light", 1);
set_property("indoors", 1);
set_short("The master room");
set_long(@ext Entering from the east through the crystal door, you look upon an almost unbelievable sight as you look about this extremely large room, which is approximately the size of four normal sized rooms placed together in a square. It is extraordinarily elegant, with a long red carpet extending from the entrance to a small stairway. Atop the stairway is a perfectly circular platform with two cresent shaped crystalline obelisks pointing toward the unobstructed sky, one at each end of the circle's diameter. From this location one can see outside the keep, beyond the mist surrounding it as there are only walls in the north and south ends of the room.
 
    @--0
ext);
set_smell("default", "The air smells both rich and of death.");
set_listen("default", "Lightning crackles throughout the skies above you.");
add_exit(ROOMS+"inside25", "east");
set_door("crystal door", ROOMS+"inside25", "east", "legend key");
set_open("crystal door", 1);
set_locked("crystal door", 0);
set_lock_level("crystal door", 1000);
ob = new(ITEM+"obelisk.c");
ob->move(this_object());
ob = new(ITEM+"obelisk.c");
ob->move(this_object());
ob = new(MON+"heartbeat_tester.c");
ob->move(this_object());
set_items(([
({ "obelisks" }) : "Two large crescent shaped obelisks sit atop the stairway on the platform, pointing at both each other and the sky.",
({ "sky" }) : "The sky appears very dark and ominous.",
({ "mist" }) : "The mist seen below covering the keep appears to be extremely thick.",
({ "platform" }) : "This circular platform sits atop a small stairway. Two large crescent shaped obelisks sit at the opposite ends of the diameter, perpendicular to the north and south walls.", 
({ "diameter" }) : "The diameter of the circular platform contains two crystalline obelisks, one at each end perpendicular to the north and south walls.",
({ "room" }) : "This is a very large room, with no ceiling present, no wall present to the west, and a stairway leading to a circular platform containing two obelisks.",
({ "carpet" }) : "This long red carpet extends from the crystal door west up a stairway and ends near a circular platform atop it.",
({ "stairway" }) : "The stairway leads up and ends as it reaches a circular platform containing two shining crystal crescent shaped obelisks.",
({ "wall" }) : "The wall is fashioned of bright red stone and is completely plain.",
({ "walls" }) : "The walls present in the north and south of the room and bordering the crystal door in the east are fashioned of bright red stone and are completely plain.",
({ "crystal door" }) : "The crystal door shines brilliantly as does the crest of Owedquar protruding from its center. It has a keyhole requiring a key of an unimaginable shape.",
({ "door" }) : "The crystal door shines brilliantly as does the crest of Owedquar protruding from its center. It has a keyhole requiring a key of an unimaginable shape.",
({ "crest" }) : "The crest present on the front of the crystal door protrudes outward and is the insignia of the dark god Owedquar.",
({ "keyhole" }) : "The keyhole on the crystal door is excessively complicated, with more shapes and sizes than one can fathom. The key that fits this must truly be one of a kind",
({ "circle" }) : "Two crystal obelisks stand here on this platform facing each other and the sky, one on each side of the diameter.",
({ "entrance" }) : "The entrance into this room, through a crystal door, also serves as the only noticeable exit.",
({ "exit" }) : "The exit from this room is through the crystal door to the east.",
({ "north end" }) : "A plain bright red stone wall sits here.",
({ "south end" }) : "A plain bright red stone wall sits here.",
({ "keep" }) : "From where you stand, the keep appears far less gloomy from this room due to the red stone walls.",
({ "sight" }) : "You can see an amazing carpeted path to and up a stairway leading to a perfectly circular platorm, with two beautiful crescent shaped crystalline obelisks sitting atop it, facing each other and the sky above.",
]));
}
