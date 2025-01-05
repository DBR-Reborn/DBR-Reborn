#include "../a1.h"

inherit "std/room";
#define ENTRY "d/areas/dragon/rooms/01"


void reset() {
    int i;
    object ob;
    ::reset();
    if (!present("elder")) 
    {
	i = random(1)+1;
	while(i--)
	{
    new(MON+"elder_dragon.c")->move(this_object());   
	}
  }
    if (!present("cursed")) 
    {
	i = random(1)+1;
	while(i--)
	{
    ob= new(MON+"cursed_dragon.c");
    ob->set("aggressive", 0);
    ob->move(this_object());  
	}
  }
    if (!present("mighty")) 
    {
	i = random(1)+1;
	while(i--)
	{
    ob= new(MON+"mighty_dragon.c");
    ob->set("aggressive", 0);
    ob->move(this_object());  
	}
  }
   if (!present("buff")) 
    {
	i = random(1)+1;
	while(i--)
	{
    new(MON+"buff_dragon.c")->move(this_object());   
	}
  }
}


void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);

    set_property("quick study", 1);

    set("short", "Dragon Cave");
    set("long",@ext
A narrow overgrown boulder in a dire mountain range marks the entrance to this dungeon. It's covered in bat droppings, large bones and crawling insects.
       
        out   
    @
        down
    
ext);
    set_exits( ([
	"out": "/d/damned/virtual/room_73_13.world",
	"down": ENTRY,
      ]) );
	//add_pre_exit_function("out","check_race");
	//call_out("load_rooms", 1);
}

/*
int check_race() {
	if(this_player()->query_race() == "dragon" ) {
		write("Monsters are not allowed outside");
		return 0;
	}
	write("You are allowed outside");
	return 1;
}
*/
/*
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
