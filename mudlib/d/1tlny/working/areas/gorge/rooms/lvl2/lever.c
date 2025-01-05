//     lever passage room by Sinclair with help from Nual//
inherit ROOM;
#include <std.h>
#include <def.h>

void create() {
     ::create();
     set_property("light",-4);
     set_property("indoors",1);
     set("short","A dark passageway");
     set("long","You are standing in a small passageway. There does not seem to"
" be any light source at all. There is a small opening in the ceiling but you"
" cannot reach it.  You can see a lever mounted in the center of the northern"
" wall.  There is a sign right below the lever.");
     add_item("lever", "The lever is a dull silver color and is slightly worn"
" from use.\n");
     add_item("sign", "As with all things, choices have to be made.  Either set lever left or set lever right and they set your path.\n");
     add_item("hole","The hole is about 3 foot in diameter and directly over"
" top of the lever.\n");
     add_item("ceiling", "There is a large hole in the ceiling\n");
     set_smell("default","The scent of charred flesh fills your nostrils.\n");
     set_listen("default", "You hear sounds coming from behind the walls.\n");
     add_exit("/wizards/sinclair/gorge/rooms/gr1", "south");
}

void init(){
   ::init();
   add_action("push", "set");
}

int push(string str){
     object who, ob;
     who=this_player();
   if(!str) return notify_fail( "Set what?\n" );
   if(str != "lever left" && str != "lever right" )
      return notify_fail("You cannot set that.\n");
   if(str == "lever left") {
      write(" You push the lever up and an exit opens up out of the western"
       " wall.");
      say(this_player()->query_cap_name() + " pushes the lever.\n" );
      say( "%^YELLOW%^An exit opens in the west wall!\n%^RESET%^");
      add_exit("dp1", "west");
      call_out("close_lever",120);
      return 1;
   }
   if(str == "lever right") {
     write("%^RED%^MAGMA falls from the hole in the ceiling and burns you alive!\n%^RESET%^");
      say(this_player()->query_cap_name() +"pushes the lever down.\n");
     say(this_player()->query_cap_name() +" gets covered in %^RED%^MAGMA%^RESET%^ dropping from the hole in the ceiling.\n");
     who->die();
     write("I guess you have made the wrong choice this time.\n");
      say(this_player()->query_cap_name() +"is covered with magma falling from"
        " the hole in the ceiling.\n");
      return 1;
   }
}

void close_lever() {
    message("info","The lever suddenly resets itself and the exit closes.",TO);
    remove_exit("west");
    return;
}
