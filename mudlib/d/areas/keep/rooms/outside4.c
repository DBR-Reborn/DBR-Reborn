#include <std.h>
#include "../keep.h"

/* This is the room in the misty field directly to the west of the keep. The exits lead north and south, south going to the fields southwest corner and north going to the northwest corner. Of the 9 rooms of mist fields, this is the only room that contains a secret passage, which can be uncovered by reading the room description carefully and looking at things. There are no monsters in this room. */

inherit ROOM;

void create() {
::create();
set_property("light", 1);
set_property("indoors", 0);
set_short("A misty field");
set_long(@ext Walking through the thick mist and across the dead grass, you look to the east to see a polluted moat and an enormous entire side of what appears to be a keep. Other than a few rocks scattered across the ground, there is nothing else here.
    0   
    |   
    @
    |
    0
ext); 
set_smell("default", "The air smells of death");
set_listen("default", "You dont hear a sound");
add_exit(ROOMS+"outside6", "north");
add_exit(ROOMS+"outside2", "south");
set_items(([
({ "rock" }) : "This is a relatively large rock. There are several of similar size scattered across the ground.",
({ "water" }) : "The water in the moat is horribly polluted. It appears light grey through the mist.",
({ "side" }) : "The side of the keep you can see appears to be pitch black, with no illumination.",
({ "ground" }) : "Endless shreds of dead grass covers the entirety of the ground. There are also a few rocks laying here placed in a formation shaped somewhat like an arrow.",
({ "mist" }) : "The mist is incredibly thick, so much so that you can barely make out your own hands.",
({ "moat" }) : "The moat, filled with old and heavily polluted water, gives off a grey hue.",
({ "grass" }) : "The grass is dead without the slightest trace of green.",
({ "keep" }) : "From what you can make out, the keep appears to be black without a single light shining.",
({ "rocks" }) : "A few rocks are scattered here in a suspicious arrangement. Perhaps you can 'search' for something within the design.",
]));
}

void init() {
::init();
add_action("read_func", "search");
}

int read_func(string str) {
if(!str || str!="rocks") {
notify_fail("You find nothing odd.");
return 0;
}
write("As you search the design of the rocks, you lift the rock the other rocks seem to point to as an arrow and uncover a secret hole!");
message("my_action", this_player()->query_cap_name() +" searches the rocks and lifts one uncovering a secret hole!", environment(this_player()), ({ "this_player()" }));
add_exit(ROOMS+"outsidesecret", "hole");
return 1;
}
