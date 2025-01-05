#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "1st Street");
set("night long","%^RESET%^The oil lanterns lining "
"the street "
      "burn bright and keep the streets of the busness district well lit.  "
      "The insides of the shops on the west and east sides of the street "
      "are dark, but the signs hanging over the doors are still readable.  "
      "1st street continues north towards the bank and militia, and "
      "south towards Execution Square and Southern Row.\n");

set("day long","%^RESET%^%^ORANGE%^This is "
"the southern part of the busness district.\n"
"The cobble stone streets are well maintained and as litter free as "
"possible with the heavy traffic of patrons that travel it each day.  "
"A building with a large Shao-tan coat of arms painted "
"on the sign over the door is to the east.  Another building "
"with a sword and dagger painted on the sign over the door "
"is to the west. To the south lay "
  "%^RED%^Executioners Square %^RESET%^and the Southern Row crossroads.  ");
add_exit("wep_shop", "west");
add_exit("arm_shop", "east");
add_exit("1st9", "north");
add_exit("Ex_square", "south");

}
