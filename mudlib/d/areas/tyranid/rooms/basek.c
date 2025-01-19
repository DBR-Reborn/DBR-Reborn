#include "../a1.h"

inherit "std/room";
#define BASE "/d/areas/tyranid/rooms/"


void reset() {
    int i;
    ::reset();
    if(!present("tyranid"))
    {
	i = random(3)+2;
	while(i--)
	{
        new(MON+"tyranid1")->move(this_object());
	    new(MON+"stealer1")->move(this_object());
	}
  }
}

void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Tyranid Hive - Veins and Arteries");
    set("long",
      "The tunnels in this section of the hive are completely round, with walls\n"
      +"that resemble the stretched skins of drum heads.  The tunnels widden and\n"
      +"constrict at regular intervals, sending a surge of putrid blue fluid\n"
      +"rushing along them and nearly washing you off your feet.  Worse, every\n"
      +"hundred feet or so there are iris-like membranes, apparently to prevent\n"
      +"the fluid from backing up or traveling the wrong way.  A sickly greenish\n"
      +"glow seems to permeate this entire area.\n"
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

    set_items( ([
	"walls" : 
	"They are made of an extremely smooth, elastic substance.  They are,\n"
	+"nonetheless, very sturdy.\n",
	"fluid" :
	"Thick, viscous, oily and incredibly vile, this deep blue fluid is\n"
	+"your constant companion here.\n",
	"membranes" :
	"These irising membranes open and then snap shut again with alarming\n"
	+"speed.  Only by carefully timing their cycle can you get by them safely.\n",
      ] ) );
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
