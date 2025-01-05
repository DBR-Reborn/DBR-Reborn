//      Wizard: Gellor
//      The New Firn'Ville Tunnels
//      tunnel2.c
#include <std.h>
inherit ROOM;
void init() {
    ::init();
    add_action("step_in_hole","step");
}
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "North-South Tunnel");
    set("long", "Ancient and filled with stuffy air, this tunnel "
    				 "is not the most comfortable place to be. The rock "
                "here is cool and has a red and brown color. Thin "
                "horizontal grooves cover the walls, probably "
                "from the water which has run through here for "
                "centuries and still does in the form of a tiny "
                "trickling stream. At one spot the water is "
                "accumulating in a small pool where a hole has formed.");
    add_exit("/wizards/gellor/newfirn/tunnel1.c","north");
    add_exit("/wizards/gellor/newfirn/tunnel3.c","south");
    add_exit("/wizards/gellor/newfirn/tunnel23.c","west");
    add_invis_exit("west");
    set_items(([
     ({ "rock","stone","walls","tunnel","cave","wall" }) :
        "The rock in which this tunnel exists is a brown and slightly "
        "reddish, very hard rock. You can see lines in the walls from "
        "the layers of time. The walls are really quite dry, but the "
        "floor here is damp in places and wet in others.",
     ({ "water","stream" }) :
        "The water has picked up a reddish hue from the rock dust. It "
        "also has a peculiar smell which fills the caverns.",
     ({ "hole" }) :
        "The hole is filled with water. It is about sixteen inches around. "
        "From what you can see, the lip around the edge of the hole is "
        "unusually sharp for a naturally formed hole. Everything else "
        "about it looks normal." ]));
    set_smell("default", "All you smell is damp rock and a hint of "
    							 "something from the north.");
    set_listen("default", "You hear nothing other than the noise you "
    							  "are making.");
}
int step_in_hole(string str){
  if(str != "in hole") return 0;
  write("You carefully set your foot into the water "
        "filled hole and find that it's not really "
        "deep with water. As you do so the west wall "
        "begins to shimmer! You must have found "
	"a fake wall!\n");
  return 1;
}
