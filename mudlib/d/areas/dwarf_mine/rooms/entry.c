#include "../a1.h"

inherit "std/room";
#define ENTRY "d/areas/dwarf_mine/rooms/01"

void reset() {
    int i;
    ::reset();
if (!present("sentry")) 
    {
	i = random(1)+1;
	while(i--)
	{
new(MON+"sentry.c")->move(this_object());
//new(MON+"shieldbreaker.c")->move(this_object());
	    new(MON+"youngslayer")->move(this_object());
	    new(MON+"worker")->move(this_object());
        new(MON+"dwarfslayer")->move(this_object());
	}
  }
}


void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
	set_property("clean", 1);
    set("short", "Dwarven Mine");
    set("long",@ext
You stand in front of the entrance of a mine. do you dare enter?
       
        out   
    @
        down
    
ext);
    set_exits( ([
	"out": "/d/damned/virtual/room_8_22.world",
	"down": ENTRY,
      ]) );
	add_pre_exit_function("out","check_race");
	call_out("load_rooms", 1);
}

int check_race() {
	if(this_player()->query_race() == "monster" ) {
		write("Monsters are not allowed outside");
		return 0;
	}
	write("You are allowed outside");
	return 1;
}

void load_rooms() {
	//find_object_or_load(PATH+"80");
	//find_object_or_load(PATH+"79");
	//find_object_or_load(PATH+"78");
	//find_object_or_load(PATH+"83");
	//find_object_or_load(PATH+"89");
	//find_object_or_load(PATH+"25");
	//find_object_or_load(PATH+"18");
	//find_object_or_load(PATH+"26");
	//find_object_or_load(PATH+"spawn_orc1");
	//find_object_or_load(PATH+"spawn_goblin1");
	//find_object_or_load(PATH+"spawn_orc2");
	//find_object_or_load(PATH+"spawn_goblin2");
}
