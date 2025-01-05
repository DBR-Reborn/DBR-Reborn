#include <std.h>
#include "../keep.h"

/* This is an enormous statue of a open palm which is located in the east wing of the black keep. It serves only as decoration initially, but during the areas quest it is where the red gem required to activate the red arcane orb appears once the holy soul is immersed in the pool of life at the opposite side of the keep. To know it will appear here, the player must read the description which tells it is the location of Lidfino's offering. When the gem appears, it will appear in the description, not the room itself. The player then takes it */

inherit OBJECT;

object ob;
int a;

void init() {
::init();
add_action("get", "get");
}

int get(string str) {
if(str == "gem from palm" || str == "red gem from palm") {
if(a==0) {
message("my_action", "You take the gem from the open palm.", this_player());
set_long("This is a four foot tall statue of a horizontally open palm, fashioned completely of white stone. An inscription on it says 'Lidfino's offerings are recieved here by the worthy'.");
ob = new(ITEM+"red_gem.c");
ob->move(this_player());
a++;
return 1;
}
if(a==1) {
message("my_action", "What?", this_player());
return 1;
}
}
}

void create() {
::create();
set_name("palm statue 2");
set("id", ({ "statue", "palm statue", "palm", "open palm", "open palm statue", "statue of an open palm" }));
set_short("A statue of an open palm");
set_long("This is a four foot tall statue of a horizontally open palm, fashioned completely of white stone. An inscription on it says 'Lidfino's offerings are recieved here by the worthy'. A %^RED%^red%^RESET%^ gem is currently sitting at the center of the palm.");
set_weight(10000000);
set_value(0);
}
