//      Wizard: Gellor
//      The New Firn'Ville Tunnels
//      tunnel1.c
#include <std.h>
inherit ROOM;
void init() {
    ::init();
    add_action("drink_water","drink");
}
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "North Of Dead End");
    set("long", "You stand in a tunnel of cool rock. This place appears "
    				 "to be ancient judging by the worn walls and floor. The "
                "rock is a dull brownish-red and has a very dull surface. "
                "Along the floor of the tunnel runs a very small stream "
                "of trickling water, probably the reason these caves "
                "exist in the first place. The water comes from a very "
                "wet spot in the south wall and trickles it's way north "
                "from here. The walls of rock are covered with a fine "
                "dust accumulated over time.");
    add_exit("/wizards/gellor/newfirn/forest1.c","up");
    add_exit("/wizards/gellor/newfirn/tunnel2.c","south");
    set_items(([
     ({ "rock","stone","walls","tunnel","cave","wall" }) :
        "The rock in which this tunnel exists is a brown and slightly "
        "reddish, very hard rock. You can see lines in the walls from "
        "the layers of time. The walls are really quite dry, but the "
        "floor here is damp in places and wet in others.",
     ({ "water","stream" }) :
        "The water has picked up a reddish hue from the rock dust. It "
        "also has a peculiar smell which fills the caverns." ]));
    set_smell("default", "An odd scent from the water is dominant in the "
    							 "air here.");
    set_listen("default", "All you can hear is the quiet, constant "
    							  "trickling of water.");
}
void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("rock")) {
      new("/wizards/gellor/newfirn/obj/rock.c")->move(this_object());}
	if (!present("rat")) {
      new("/wizards/gellor/newfirn/mobs/rat1.c")->move(this_object());}
}
int drink_water(string str){
  if(str != "water") return 0;
  write("This water tastes awful! You better hope you're not "
  		  "poisoned!\n");
  return 1;
}
