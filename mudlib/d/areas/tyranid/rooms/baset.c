#include "../a1.h"

inherit "std/room";
#define BASE "/d/areas/tyranid/rooms/"
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
      +"light fills this area, illuminating glittering pools of clear water\n"
      +"filling tiny basin-like depressions.\n"
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
	+"light.\n",
	"depressions":
	"They appear to have formed naturally where the stomach acid has\n"
	+"eaten away at the mucus coating of the stomach lining.  The water\n"
	+"APPEARS safe to drink.\n",
	"water":
	"Its clear, lukewarm to the touch and it doesn't SEEM to smell\n"
	+"particularly bad...you could drink it if you were desperate.\n",
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
  ]) );
}

void init()
{
    ::init();
    add_action("drink","drink");
}

int drink(string str)
{
    if (!str) {
	message("error",
	  "Drink what?\n",
	  this_player());
	return 1;
    }
    if (str != "water" && str != "basin" && str != "depressions") return 0;
    if (!this_player()->add_quenched(20)) {
	message("info",
	  "Any more water and you would burst like a ballon.\n",
	  this_player());
	return 1;
    }
    message("info",
      "You take a deep drink of the clear liquid and discover that it\n"
      +"actually tastes worse than the surounding area smells...\n",
      this_player());
    message("info",
      capitalize(this_player()->query_name())+
      "take a large drink of stagnant water and shudders.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}
