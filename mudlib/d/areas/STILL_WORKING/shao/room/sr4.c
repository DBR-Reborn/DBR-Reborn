#include <shao.h>
inherit "std/vault";


void create() {
  ::create();
    set_property("light",2);
    set_property("night light", -1);
add_exit(PATH+"sr3","west");
add_exit(PATH+"sr5","east");
add_exit(PATH+"al5","north");
add_invis_exit("north");
set_door("south door", PATH+"leather_shop","south",
"leather shop");
	  set_open("south door", 1);
	  set_locked("south door", 0);
          set_open_function("open_door", "5:00:00");
    set_close_function("close_door", "16:30:00");
add_exit(PATH+"leather_shop","south");
set_items(([
"door": "It looks quite sturdy", "south door":
"it looks quite sturdy.",
"building": "There are three of them that you can see...\n"+
"One on the northwest corner, one on the northeast corner, "
"and one directly south of you...\n"]));
set("short","Southern Row");
set("night long","%^RESET%^A smashed lantern lay "
"at your feet.\n"
"This section of the road is very dark, if not for the dim light "
"given off from the moon and stars that hang in the sky it "
"would be totaly dark.\n");
set("day long","%^RESET%^%^ORANGE%^A broken street "
"lantern lay at your feet, "
"the sharp glass not yet cleaned up by the Shao-tan care takers. "
"A building lay to the south, a sign is located over the door. "
"To the east appeer to be more buildings as well as the "
"notorious, and feared Excecution Square.\n");
    return;
}

void close_door() {
call_other(PATH+"leather_shop","close_door");
  return;
}

void open_door() {
call_other(PATH+"leather_shop","open_door");
  return;
}

