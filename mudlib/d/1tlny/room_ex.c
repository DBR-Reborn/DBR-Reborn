#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void create()
{
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
It is%^YELLOW%^day%^RESET%^outside.
    You are standing just inside the entrance.
EndText);

    set( "night long", @EndText
It is%^BOLD%^BLUE%^night%^RESET%^outside.
    You are standing just inside the entrance.
EndText);

//add_exit(PATH+"r1.c", "north");
//add_exit(PATH+"r2.c", "south");
//add_exit(PATH+"r3.c", "east");
//add_exit(PATH+"r4.c", "west");
add_exit("/d/damned/virtual/room_8_22.world", "exit");
    //add_invis_exit("north");

	add_pre_exit_function("out","check_race"); //for function below to block races 

set_items(([
            ({ "sand" }) : "a sand pile sits on the side you should probably%^YELLOW%^search sand%^RESET%^"
     ]));

    set_search("sand",(: call_other, this_object(),"do_search" :));
    set_search("default"," You see some %^YELLOW%^sand%^RESET%^ maybe if you tried to search sand you might find something");
    search_count=0;
}

void do_search() {
  //int skill;
  object ob;
  say(this_player()->query_cap_name()+" appears to be searching "+
    "around in the sand.\n");
  //skill=((int)this_player()->query_skill("perception"))-60;
 // if((random(100)<skill) && search_count<1){
    if(search_count<1){
    search_count=1;
    write("Your search is successful.\n"+
      "You discovered a key.\n");
    ob=new("/d/khojem/nomad/obj/sand_key");
    ob->move(this_object());
  }
  else
    write("Your search yields nothing.");
  return;
}

//block any race tyranid fome going outside
int check_race() {
	if(this_player()->query_race() == "tyranid" ) {
		write("Tyranid are not allowed outside");
		return 0;
	}
	write("You are allowed outside");
	return 1;
}

