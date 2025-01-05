#include "../a1.h"

inherit "std/room";
#define BASE "/d/areas/beholders/rooms/"
object tyranid;
int i;


void reset() {
    ::reset();
    if(!present("elder brain"))
    {
	i = 1;
	while(i--)
	{
	    new(MON+"elderbrain")->move(this_object());
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


    set("short", "The Elder Brain Throne Room");
    set("long",@ext
      Slender braziers encompassing each of the twelve marmoreal columns light up the lower levels of the throne hall and their light wraps the hall in a warm radiance. The angelic paintings on the terraced ceiling dance in the flickering light while statues look down upon the slate floor of this royal hall.

A golden rug runs from the throne down through the center and splits into two paths leading out while ribbon banners with embellished ridges the walls. Between each banner hangs a lantern, some of them have been lit and in turn illuminate the tapestries of gods and goddesses below them.
Extensive, tinted glass windows are framed by drapes colored the same golden as the banners. The curtains have been adorned with fancy tassels and gold leaves.

A noble throne of silver sits beneath a fairly plain looking baldachin (canopy) and is adjoined by six almost identical seats for those aiding the royal highness in all affairs.
The throne is covered in holy designs and fixed on each of the broad feet is a jade petal. The thick pillows are a dark golden and these too have been adorned with embellished tassels. \n
ext

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
