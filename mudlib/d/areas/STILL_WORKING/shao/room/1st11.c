#include <std.h>
#include <shao.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "1st Street");
set("night long","%^RESET%^You stand in the north"
"ern most tip of the "
      "burn bright and keep the streets of the busness district well lit.  "
      "The dim glow of candle light flows from the barred windows "
      "on the Shao-tan Jail to the west.  The Post office to the east "
      "appears to be closed for the night as it is bitch black inside.  "
      "Further up 1st street "
"the bright flaming %^RESET%^%^BOLD%^%^YELLOW%^cross "
"%^RESET%^of "
      "Shao-tan church can be seen.  "
      "Towards the south the street is very dark, imparing your vision "
      "in that direction.\n");
set("day long","%^RESET%^%^ORANGE%^You stand "
"on the northern most tip of the "
      "busness district.\n"
      "The cobble stone streets are well maintained and as litter free as "
      "possible with the heavy traffic of patrons that travel it each day.  "
      "A large stone building to the west has barred windows, "
      "the freshly painted letters : %^BOLD%^%^BLUE%^J-A-I-L "
"%^RESET%^%^ORANGE%^lead you to believe "
"it is the infamous Shao-tan jail. "
      "To the east appears to be the post office, while north lay the "
"Northern Row intersection and Shao-tan church.\n");
add_exit("jail", "west");
set_door("iron door",PATH+"jail","west",0);
add_exit("post", "east");
add_exit("1st12", "north");
add_exit("1st10", "south");

}
