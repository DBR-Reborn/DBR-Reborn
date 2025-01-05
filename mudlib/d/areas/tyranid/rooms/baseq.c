#include "../a1.h"

inherit "std/room";
#define BASE "/d/areas/tyranid/rooms/"

void reset() {
    ::reset();
    if(!present("tyranid"))
    {
	new(MON+"zoanthrope2")->move(this_object());
    }
}

void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Tyranid Hive - Neck");
    set("long",
      "The tunnels here are clearer and smoother than they've been in some\n"
      +"time.  They are walled with a smooth, solid substance that is probably\n"
      +"muscle.  Huge rings of bone-like material and thinner tubes that must be\n"
      +"blood vessels can be seen now and then, giving the muscle a sort of\n"
      +"marbleized look.  Oddly, a painful violet light seems to fill this area,\n"
      +"its source undetectable.\n"
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
