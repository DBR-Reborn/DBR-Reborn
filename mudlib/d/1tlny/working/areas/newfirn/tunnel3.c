//      Wizard: Gellor
//      The New Firn'Ville Tunnels
//      tunnel3.c
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
    set("short", "Curve In Tunnel");
    set("long", "The cavern curves here going east and north. A slight "
                "cool breeze blows in from the east passage. The tunnel "
                "rock is redish brown covered with grooves from water and "
                "time. There is a slight downward direction to the tunnel "
                "to the east which allows the small stream of water "
                "to move in that direction.");
    add_exit("/wizards/gellor/newfirn/tunnel2.c","north");
    add_exit("/wizards/gellor/newfirn/tunnel4.c","east");
    set_items(([
     ({ "rock","stone","walls","tunnel","cave","wall" }) :
        "The rock in which this tunnel exists is a brown and slightly "
        "reddish, very hard rock. You can see lines in the walls from "
        "the layers of time. The walls are really quite dry, but the "
        "floor here is damp in places and wet in others.",
     ({ "water","stream" }) :
        "The water has picked up a reddish hue from the rock dust. It "
        "also has a peculiar smell which fills the caverns." ]));
    set_smell("default", "You can smell the dampness in the air coming "
                         "in a breeze from the east.");
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
