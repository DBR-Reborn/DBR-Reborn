#include "../a1.h"

inherit "std/room";
#define BASE "/d/areas/tyranid/rooms/"
object tyranid;
int i;

void reset() {
    ::reset();
    if(!present("tyranid"))
    {
	i = random(3)+1;
	while(i--)
	{
	    new(MON+"termagant1")->move(this_object());
	}
  }
}

void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Tyranid Hive - Large Intestine");
    set("long",
      "The interior of the hive bears a vague resemblance to a series of\n"
      +"tunnels bored through soft earth...at least until one looks more\n"
      +"closely.  The 'walls' of the tunnel are soft and spongy, made not of\n"
      +"earth, but of some slimy organic substance with odd patterns and\n"
      +"convolutions that pulse with the beating of a distant heart...  The\n"
      +"'floor' is out of sight, under several inches of a noxious brownish\n"
      +"green fluid that bears a disturbing resemblance to raw sewage.  A\n"
      +"misty white light seems to permeate the area.\n"
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
	"walls" : "Sticky and disgusting, yet not as wet as you would expect.", 
	"floor" : "You hold your nose and peer closely, buy you still can't"
	+"see anything through the noxious liquid.",
	"fluid" : "Thick and soupy, almost clotted, and the stench is..."
	+"indescribable."] ) );
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
