// Wizard: Avatar
// Room: Hive Room - type A
// /wizards/avatar/tyranid/rooms/basea.c
// October 23rd, 1996

//#define SOUTH "0507"
//#define DOWN "entry"
//#include "basea.c"

#include "../a1.h"

inherit "std/room";

object tyranid;
int i;

void reset() {
    ::reset();
    if(!present("tyranid"))
    {
	i = random(2)+1;
	while(i--)
	{
	    new(MON+"ripper")->move(this_object());
	}
  }
}

void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Tyranid Hive");
    set("long",@ext
The interior of the hive bears a vague resemblance to a series of
tunnels bored through soft earth...at least until one looks more
closely.  The 'walls' of the tunnel are soft and spongy, made not of
earth, but of some slimy organic substance with odd patterns and
convolutions that pulse with the beating of a distant heart...  The
'floor' is out of sight, under several inches of a noxious brownish
green fluid that bears a disturbing resemblance to raw sewage.  A
misty white light seems to permeate the area.
       
           
    @
    |    down
    S
ext);


    set_exits( ([
	"down": "/d/areas/tyranid/rooms/entry",
	"south": "/d/areas/tyranid/rooms/0507",
      ]) );
	add_pre_exit_function("down","check_race");
}

int check_race() {
	if(this_player()->query_race() == "tyranid" ) {
		write("Tyranid are not allowed outside");
		return 0;
	}
	write("You are allowed outside");
	return 1;
}

