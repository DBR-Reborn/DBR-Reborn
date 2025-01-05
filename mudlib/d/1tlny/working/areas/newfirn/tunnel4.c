//      Wizard: Gellor
//      The New Firn'Ville Tunnels
//      tunnel4.c
#include <std.h>
inherit ROOM;
void init(){
::init();
call_out("water_drop",40);
}
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "An Intersection Of Tunnels");
    set("long", "Two tunnels intersect here, one running from west "
    				 "to east, the other going south. The rock here is "
                "cool and feels moist. There is a small stream of water "
                "which flows down the center of the tunnel and runs "
                "from the west to the east from here due to how the "
                "tunnel goes down a bit to the east.");
    add_exit("/wizards/gellor/newfirn/tunnel8.c","south");
    add_exit("/wizards/gellor/newfirn/tunnel3.c","west");
    add_exit("/wizards/gellor/newfirn/tunnel5,c","east");
    set_items(([
     ({ "rock","stone","walls","tunnel","cave","wall" }) :
        "The rock in which this tunnel exists is a brown and slightly "
        "reddish, very hard rock. You can see lines in the walls from "
        "the layers of time. The walls are really quite dry, but the "
        "floor here is damp in places and wet in others.",
     ({ "water","stream" }) :
        "The water has picked up a reddish hue from the rock dust. It "
        "also has a peculiar smell which fills the caverns." ]));
    set_smell("default", "The air smells of moist rock.");
    set_listen("default", "There is a constant rumbling sound to the "
    							  "east.");
}
void water_drop() {
        remove_call_out("water_drop");
               call_out("water_drop", 40);
    switch(random(3)){
      case 0:tell_room("/wizards/gellor/newfirn/tunnel3.c",
      					  "A slight humid breeze blows by covering your "
                       "face with condensation.");
      break;
      case 1:tell_room("/wizards/gellor/newfirn/tunnel3.c",
      					  "You wipe some of the moisture off your face.");
      break;
      case 2:tell_room("/wizards/gellor/newfirn/tunnel3.c",
      					  "A drop of water splashes into the stream on "
                       "on the tunnel floor.");
      break;
}
}
