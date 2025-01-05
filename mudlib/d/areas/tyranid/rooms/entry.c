#include "../a1.h"

inherit "std/room";
#define ENTRY "d/areas/tyranid/rooms/0506"

void reset() {
    int i;
    ::reset();
    if(!present("marine"))
    {
	i = random(1)+1;
	while(i--)
	{
	    new(MON+"space_marine")->move(this_object());
	}
  }	    
    if(!present("scout"))
    {
	i = random(2)+1;
	while(i--)
	{
	    new(MON+"space_marine2")->move(this_object());
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
You stand in front of a HUGE structure that vaguely resembles a
combination between a huge termite mound and some sort of gigantic
living being!  An entrance of sorts can be seen at the base, though an
unappealing brownish fluid appears to be leaking steadily from it.
       
        up   
    @
        down
    
ext);
    set_exits( ([
	"down": "/d/damned/virtual/room_12_4.world",
	"up": ENTRY,
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
