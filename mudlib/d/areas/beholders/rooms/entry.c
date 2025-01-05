#include "../a1.h"

inherit "std/room";
#define ENTRY "d/areas/beholders/rooms/01"
int i;

void reset() {
    ::reset();
    if(!present("shadowflame"))
    {
	i = random(3)+1;
	while(i--)
	{
	    new(MON+"shadowflamet.c")->move(this_object());
	}
  }
}


void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "The Smoldering Cells entrance");
    set("long",@ext
A tall graveyard in a shady boulder field marks the entrance to this dungeon.
       
        enter   
    @
        out
    
ext);
    set_exits( ([
	"out": "/d/damned/virtual/room_23_52.world",
	"enter": ENTRY,
      ]) );
	//add_pre_exit_function("out","check_race");
	//call_out("load_rooms", 1);
}

/*
int check_race() {
	if(this_player()->query_race() == "monster" ) {
		write("Monsters are not allowed outside");
		return 0;
	}
	write("You are allowed outside");
	return 1;
}

void load_rooms() {
	find_object_or_load(PATH+"80");
	find_object_or_load(PATH+"79");
	find_object_or_load(PATH+"78");
	find_object_or_load(PATH+"83");
	find_object_or_load(PATH+"89");
	find_object_or_load(PATH+"25");
	find_object_or_load(PATH+"18");
	find_object_or_load(PATH+"26");
	find_object_or_load(PATH+"spawn_orc1");
	find_object_or_load(PATH+"spawn_goblin1");
	find_object_or_load(PATH+"spawn_orc2");
	find_object_or_load(PATH+"spawn_goblin2");
}
*/
