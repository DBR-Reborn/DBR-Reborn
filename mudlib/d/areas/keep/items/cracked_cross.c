#include <std.h>

/* This is the cracked cross that is present in the paladin temple room of the black keep. It is the worship object of Sacrel, the God of Light, and is cracked to demonstrate Owedquar's hatred for the diety due to its location in the conquered keep. It serves no purpose other than decoration in the room. */

inherit OBJECT;

void init() {
::init();
add_action("get", "get");
}

int get(string str) {
if(str == "cross" || str == "cracked cross") {
message("my_action", "You cannot take the cross off the wall, for it is nailed to it unimaginably tight.", this_player());
return 1;
}
}

void create() {
::create();
set_name("cracked cross");
set("id", ({ "cross", "cracked cross" }));
set_short("A cracked cross");
set_long("This is a white cross used by Paladins to worship Sacrel, the God of Light. It hangs nailed to the south wall of the room and is badly cracked, likely a sign of undying hatred to the diety.");
set_property("no get", 1);
set_weight(10000000);
set_value(0);
}
