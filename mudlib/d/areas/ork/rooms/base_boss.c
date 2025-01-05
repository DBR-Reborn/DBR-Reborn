#include "../a1.h"

inherit "std/room";
#define BASE "/d/areas/ork/rooms/"
int i;


void reset() {
    ::reset();

    if(!present("painboyz"))
    {
	i = random(2)+1;
	while(i--)
	{
	    new(MON+"3painboyz")->move(this_object());
	}
  }
    if(!present("slugga boyz"))
    {
	i = random(1)+1;
	while(i--)
	{
	    new(MON+"6sluggaboyz")->move(this_object());
	}
  }

    if(!present("madboyz"))
    {
	i = random(2)+1;
	while(i--)
	{
	    new(MON+"4madboyz")->move(this_object());
	}
  }
    if(!present("mekboyz"))
    {
	i = random(2)+1;
	while(i--)
	{
	    new(MON+"2mekboyz")->move(this_object());
	}
  }
    if(!present("wildboyz"))
    {
	i = random(4)+1;
	while(i--)
	{
	    new(MON+"1wildboyz")->move(this_object());
	}
  }

    if(!present("ardboyz"))
    {
	i = random(2)+1;
	while(i--)
	{
	    new(MON+"5ardboyz")->move(this_object());
	}
  }

}

void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Dragon Cave");
    set("long",
      "You cautiously proceed onwards, deeper into the dungeon's depths. You pass countless passages, most lead to nowhere or back to this same path. You eventually make it to what is likely the final room."

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
	"walls" : "loaded down with shiny minerals", 
	"floor" : "dirt dirt and more dirt",
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
  ]) );
}
