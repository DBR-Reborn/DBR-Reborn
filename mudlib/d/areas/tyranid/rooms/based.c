#include "../a1.h"

inherit "std/room";
#define BASE "/d/areas/tyranid/rooms/"
void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Tyranid Hive - Small Intestine");
    set("long",
      "The tunnel-like appearance of the hive is generally unchanged.  However\n"
      +"the specific details appear to be shifting.  The walls and floor remain\n"
      +"organic, but rather than being mostly smooth with the occational ridge\n"
      +"or striation, they are now covered with slimy, pink, worm-like\n"
      +"protrusions that wave about.  The waves seem to pass through the things\n"
      +"in waves, rather than at random.  A dim blue radiance seems to permeate\n" 
      +"the area.\n"
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
	"They are a pale, moist pink in color and covered with waving cilia.\n"
	+"The constant, but totally silent motion is extemely disorienting.",
	"cilia" : 
	"Pink and worm-like, about six inches long and in constant motion."] ) );
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
