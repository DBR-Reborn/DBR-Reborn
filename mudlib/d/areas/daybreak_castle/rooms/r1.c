#include <std.h>
#include "../a1.h"

inherit ROOM;

void reset() {
        ::reset();
if (!present("troll")) 
new(MON+"troll.c")->move(this_object());
new(MON+"troll.c")->move(this_object());
}

int search_count;

void init(){
  ::init();
  add_action("pull_lever","lever");
}

int pull_lever(string str){
    if(str == "lever"){
      write("You pull down the lever to the bridge and it slowly lowers the draw bridge as you hear the chains bind & grind!\n"
        "You can see a faint fire inside the castle square and smell the stench of the bodly fluids over the wooden bridge!\n");
      say(this_player()->query_cap_name()+" pulls the lever to the draw bridge"
         "Watches the bridge begin to lower!");
      add_exit("enter"+"r2","bridge");
      return 1;
    }
}


void create(){
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set_property("indoors", 1);

    //set_property("no attack", 1); 
    //set_property("no cast", 1);
    //set_property("no scry", 1);
    //set_property("no teleport", 1);
    //set_property("no summon", 1);
    set( "short", "The southern entrance." );
    set( "day long", @EndText
It is cloudy outside.

    You are standing at the base of where a draw bride would lay. Bridge Trolls are present to protect the entrance into the castle. Pull the lever to lower the bridge or return where you came from.
EndText);

    set( "night long", @EndText
It is %^BOLD%^BLUE%^night%^RESET%^ outside.
    You are standing just inside the entrance.
EndText);

add_exit(PATH+"r2.c", "bridge");
add_exit(PATH+"enter.c", "south");
//add_exit(PATH+"r3.c", "east");
//add_exit(PATH+"r4.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");


}
