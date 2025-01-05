#include "../a1.h"

inherit "std/room";
#define BASE "/d/areas/beholders/rooms/"
object tyranid;
int i;


void reset() {
    ::reset();
    if(!present("beholder"))
    {
	i = 2;
	while(i--)
	{
	    new(MON+"beholder1")->move(this_object());
	}
  }
}

void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);

    set_property("no scry", 1);
    set_property("no summon", 1);
	set_property("no teleport",1);
    set_property("no boss spell", 1);
    //set_property("no spell", 1);

    set("short", "The Beholders Den");
    set("long",
      "You proceed onwards, deeper into the dungeon's darkness. You pass a few more rooms and passages, they all look so similar, this whole place is a maze. You eventually make it to what is likely the final room. Only to feel the stench that feels the air of rotted corpses and bones are scattered everywhere. \n"

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
    //set_items( ([
	//"walls" : "loaded down with shiny minerals", 
	//"floor" : "dirt dirt and more dirt",
//] ) );
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
#ifdef NORTHWEST
    "northwest": BASE + NORTHWEST,
#endif
#ifdef NORTHEAST
    "northeast": BASE + NORTHEAST,
#endif
#ifdef SOUTHWEST
    "southwest": BASE + SOUTHWEST,
#endif
#ifdef SOUTHEAST
    "southeast": BASE + SOUTHEAST,
#endif
#ifdef OTHER
    "exit": OTHER,
#endif
  ]) );
}
