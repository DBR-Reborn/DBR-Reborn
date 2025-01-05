//      Wizard: Gellor
//      The New Firn'Ville Tunnels
//      tunnel11.c
#include <std.h>
inherit ROOM;
int search_count;
void init(){
	 ::init();
	 call_out("water_drop",40);
    add_action("catch_fish","catch");
}
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "Tunnel Intersection");
    set("long", "This intersection is located at a place which is loud "
    				 "with a constant thunderous sound. A humid air blows "
                "through here keeping it cool for the most part. The "
                "rock here is almost dripping with water while the "
                "floor is home of a fairly large stream. Good thing the "
                "tunnel is quite wide here or you might be forced to wade "
                "in the swift currents.");
    add_exit("/wizards/gellor/newfirn/tunnel7.c","north");
    add_exit("/wizards/gellor/newfirn/tunnel12.c","south");
    add_exit("/wizards/gellor/newfirn/tunnel10.c","west");
    set_items(([
     ({ "rock","stone","walls","tunnel","cave","wall" }) :
        "The rock in which this tunnel exists is a brown and slightly "
        "reddish, very hard rock. You can see lines in the walls from "
        "the layers of time. The walls are really quite dry, but the "
        "floor here is damp in places and wet in others.",
     ({ "water","stream" }) :
        "Strong eddies and whirlpools fills the stream. The water is "
        "extremely clear here, allowing you see not only the bottom "
        "but hundreds of fish too! They are swimming against the current "
        "trying to go north. Some of them seem to notice you standing "
        "at the edge of the stream and swim closer to you." ]));
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
void catch_fish() {
  int skill;
  say(this_player()->query_cap_name()+" appears to be poking his "+
    "hands into the water.\n");
  skill=(int)this_player()->query_skill("perception");
  if((random(70)<skill) && search_count<3){
    search_count++;
    write("You caught a fish!");
    switch(random(3)){
      case 0:new("/wizards/gellor/newfirn/obj/torch.c")->
                 move(this_object());
             write("You caught a small vell.");
      break;
      case 1:new("/wizards/gellor/newfirn/obj/torch.c")->
                 move(this_object());
             write("You have landed a beautiful cave julkass!");
      break;
      case 2:new("/wizards/gellor/newfirn/obj/torch.c")->
                 move(this_object());
             write("You pulled small harger from the stream.");
      break;
    }
  }
    else
    write("Your search yields nothing.");
  return;
}
