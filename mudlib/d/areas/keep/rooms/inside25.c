#include <std.h>
#include "../keep.h"

/* This is the elegant hallway leading to the master room of the black keep. There are four shadow knights present in this room, intended to give players a good run for their money and a taste of the danger to come if they are prepared to face the keep's master in the next room. At the west end of it rests a crystal door, which requires the legend key to open. To get the legend key, the player and his party must have completed everything else in the entire areas quest. The key is forged at the Shadowforge in the great hall on the first floor by a merchant using all three crystal shards obtained from the three arcane orbs, and all three must have recieved the divine blessings for it to work. The east exit leads back into the second floor's main intersection. */ 

inherit "/std/vault";

int a;

void init() {
::init();
if(present("legend key", this_player()) && !present("ultima umbra", this_player())) {
a = 1;
if(a>0) {
write("A mysterious voice says in Common: %^CYAN%^Do you really think you can beat me?%^RESET%^");
return;
}
if(present("ultima umbra", this_player())) {
a = 0;
return;
}
}
}

void create() {
object ob;
::create();
a = 0;
set_property("light", 1);
set_property("indoors", 1);
set_short("An elegant hallway");
set_long(@ext Rarely in your life have you seen a hallway look so decorated. The walls are bright red in color, and four white pillars stand seperating each of the north and south walls, two for each, into three equal sections. The walls themselves are decorated with very expensive art, and the floor is completely covered by a gold colored rug. The room itself is illuminated rather well from lit lanterns, one on the center section of each of the two walls. A beautiful crystal door bars access to the west, and you can see an intersection to the east.
 
 0--@--0
ext);   
set_smell("default", "The air smells somewhat fresh.");
set_listen("default", "You hear an evil voice echoing in your head.");
add_exit(ROOMS+"masterroom", "west");
add_exit(ROOMS+"inside17", "east");
set_door("crystal door", ROOMS+"masterroom", "west", "legend key");
set_open("crystal door", 0);
set_locked("crystal door", 1);
set_lock_level("crystal door", 100000);
ob = new(MON+"shadow_knight.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"shadow_knight.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"shadow_knight.c");
ob->set("aggressive", 1);
ob->move(this_object());
ob = new(MON+"shadow_knight.c");
ob->set("aggressive", 1);
ob->move(this_object());
set_items(([
({ "crystal door" }) : "The crystal door shines brilliantly as does the crest of Owedquar protruding from its center. It has a keyhole requiring a key of an unimaginable shape.",
({ "door" }) : "The crystal door shines brilliantly as does the crest of Owedquar protruding from its center. It has a keyhole requiring a key of an unimaginable shape.",
({ "crest" }) : "The crest present on the front of the crystal door protrudes outward and is the insignia of the dark god Owedquar.",
({ "keyhole" }) : "The keyhole on the crystal door is excessively complicated, with more shapes and sizes than one can fathom. The key that fits this must truly be one of a kind",
({ "pillar" }) : "This pillar which seperates two sections of a wall is fashioned completely of bright white stone",
({ "pillars" }) : "The four pillars, two on each of the north and south walls, which seperate two sections of a wall each, are fashioned completely of bright white stone.",
({ "walls" }) : "The walls, fashioned of bright red stone, carry beautiful works of art and are divided into three sections by white stone pillars. A well lit lantern is bolted above the art on the center section on each.",
({ "wall" }) : "This wall, fashioned of bright red stone, carries beautiful works of art and is divided into three sections by white stone pillars. A well lit lantern is bolted above the art on the center section.",
({ "hallway" }) : "This hallway is very elegant. A beautiful golden rug covers the entire floor, and it contains four white pillars dividing the north and south walls into three sections with each containing an exquisite work of art. A shiny crystal door is situated at the west end barring passage beyond here in that direction.",
({ "north wall" }) : "This wall, fashioned of bright red stone, carries beautiful works of art and is divided into three sections by white stone pillars. A well lit lantern is bolted above the art on the center section.",
({ "south wall" }) : "This wall, fashioned of bright red stone, carries beautiful works of art and is divided into three sections by white stone pillars. A well lit lantern is bolted above the art on the center section.",
({ "section" }) : "This section of the wall, divided from other sections by white pillars, carries a work of art painted by a truly talented artist.",
({ "sections" }) : "The three sections of the wall, divided by white pillars, carry works of art painted by truly talented artists.",
({ "art" }) : "The art present on the walls is very awe-inspiring. One work is of three colored balls, another directly across from it of three small pieces of crystal. There is also art of a hand extending a crystal, and facing it a work of a beautiful diety. Finally, there is art of a large object containing fire, and on the other wall a shiny design of a key.",
({ "lantern" }) : "This is a well lit lantern bolted into the center section of the wall above the art hanging on it.",
({ "lanterns" }) : "These well lit lanterns are bolted into the center sections of each wall above the art hanging on them.",
({ "floor" }) : "The floor of the room is completely covered by a magnificent golden rug.",
({ "rug" }) : "This is a truly eye catching rug covering the entire floor. It is colored bright gold and is completely full of intricate designs, most of which resemble war.",
({ "center section" }) : "A stunning piece of art hangs on this section of the wall. A well lit lantern is bolted a bit above it.",
({ "intersection" }) : "A well lit three way intersection is seen directly to the east.",
({ "exits" }) : "The exits in the intersection seen to the east go towards the north and further east.",
({ "room" }) : "This room is an extraordinarily elegant hallway. Four white stone pillars divide the red walls into three sections, each containing incredible art with the center one also containing a bright lantern. The floor is also completely covered by a gold colored rug, and an striking crystal door is located at the west end. The unhindered exit from here is east.",
({ "exit" }) : "The only unblocked exit from this room is east to a visible lit intersection.",
({ "west end" }) : "At this end of the luxurious hallway rests a beautiful crystal door, blocking access any further in that direction.",
({ "designs" }) : "The designs on the gold colored rug mostly resemble those of vicious war.",
]));
}
