#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "1st Street");
set("night long","%^RESET%^The oil lanterns "
"lining the street "
      "burn bright and keep the streets of the busness district well lit.  "
      "The insides of the shops on the west and east sides of the street "
      "are dark, but the signs hanging over the doors are still readable.  "
      "Towards the north you can see the midnight oil burning in "
      "the Shao-tan Jail, and even farther up 1st street "
"the bright flaiming %^BOLD%^%^YELLOW%^cross "
"%^RESET%^of "
      "Shao-tan church can be seen.  "
      "To the south lay some other shops that are closed for "
      "the night, as well as the Southern Row intersection and "
      "Exuction Square.\n");
set("day long","%^RESET%^%^ORANGE%^You stand in "
"the middle of the busness district "
      "and are at the heart of Shao-tan.  "
      "The cobble stone streets are well maintained and as litter free as "
      "possible with the heavy traffic of patrons that travel it each day.  "
      "A fortress like building is to the east, judging from the "
      "numerious bars on the windows, and the odd door, "
      "it appears to be the Shao-tan bank.  "
      "On the other side of the street a lodge type building "
      " with faded sign on the front door.\n");
add_exit("mil_shop", "west");
add_exit("bank", "east");
add_exit("1st10", "north");
add_exit("1st8", "south");

}
