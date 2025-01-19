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
	    new(MON+"stealer1")->move(this_object());
	}
  }
}

void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Tyranid Hive - Stomach");
    set("long",
      "You have definitely climbed a long way into the hive.  After passing\n"
      +"through the intestines, you appear to have arrived in the stomach.  The\n"
      +"general tunnel-like appearance of the place is the same, but the walls\n"
      +"and floor are much softer...rather like walking on huge soggy sponges,\n"
      +"dripping with corrosive acid.  A gentle wind blows through the whole\n"
      +"area, carrying with it clouds of stinging acid mist.  A pulsing orange\n"
      +"light fills this area.\n"
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
	"The stomach lining is oddly smooth and glistens slightly in the\n"
	+"light.  It appears to be covered with a slimy mucus, though you\n"
	+"find the idea of investigating more closely daunting.\n"] ) );
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
