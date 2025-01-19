#include "../a1.h"

inherit "std/room";
#define BASE "/d/areas/tyranid/rooms/"

void reset() {
    int i;
    ::reset();
    if(!present("tyranid"))
    {
	i = random(4)+2;
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
      +"light fills this area, illuminating strange white and yellow masses\n"
      +"clinging wetly to the walls.\n"
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
	+"light.  Strange yellow and white masses seem to be stuck to the\n"
	+"walls, resembling soggy tissue paper.\n",
	"masses":
	"They bear a striking resemblance to tissue paper...or partially\n"
	+"digested food...perhaps you could 'eat' one if you were quite\n"
	+"brave?\n",] ) );
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
  ]) );
}

void init()
{
    ::init();
    add_action("eat","eat");
}

int eat(string str)
{
    if (!str) {
	message("error",
	  "Eat what?\n",
	  this_player());
	return 1;
    }
    if (str != "mass" && str != "masses") return 0;
    if (!this_player()->add_stuffed(20)) {
	message("info",
	  "You are too full...the mere thought of eating the fatty globule\n"
	  +"makes your stomach turn.\n",
	  this_player());
	return 1;
    }
    message("info",
      "You suck down one of the fatty masses and nearly choke on the\n"
      +"horrible flavor.\n",
      this_player());
    message("info",
      capitalize(this_player()->query_name())+
      "sucks down a greasy globule of fat!  How sickening!\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}
