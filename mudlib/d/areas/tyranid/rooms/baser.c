#include "../a1.h"

inherit "std/room";
#define BASE "/d/areas/tyranid/rooms/"

void reset() {
    ::reset();
    if(!present("tyranid"))
    {
	new(MON+"tyrant1")->move(this_object());
    }
}

void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Tyranid Hive - Brain");
    set("long",
      "You have reached the apex of the Tyranid hive.  This huge chamber\n"
      +"has walls of glittering blood-red crystal trough which the central\n"
      +"node of the Tryanid hive intelligence can observe its new world.\n"
      +"The view through the 'windows' is tinted a deep crimson, almost as\n"
      +"if the world was awash in blood...\n"
"\n"
#ifdef NORTHWEST
    "NW"
#endif
#ifdef NORTHEAST
    "     NE"
#endif
#ifdef NORTH
    "\n    N\n    |"
#endif
"\n "
#ifdef WEST
    "W-"
#endif
"   "
#ifdef EAST
    "-E"
#endif
#ifdef SOUTH
    "\n    | \n    S"
#endif
"\n"
#ifdef SOUTHWEST
    "SW"
#endif
#ifdef SOUTHEAST
    "     SE"
#endif
#ifdef UP
    "       up"
#endif
#ifdef DOWN
    "       down"
#endif
);
    set_exits( ([
#ifdef NORTH
	"north": BASE + NORTH,
#endif
#ifdef SOUTH
	"south": BASE + SOUTH,
#endif
#ifdef EAST
	"east": BASE + EAST,
#endif
#ifdef WEST
	"west": BASE + WEST,
#endif
#ifdef UP
	"up": BASE + UP,
#endif
#ifdef DOWN
	"down": BASE + DOWN,
#endif
      ]) );
}
