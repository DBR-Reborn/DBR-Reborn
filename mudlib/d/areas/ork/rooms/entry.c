#include "../a1.h"

inherit "std/room";


void reset() {
    int i;
    object ob;
    ::reset();
    if (!present("wildboyz")) 
    {
	i = random(2)+1;
	while(i--)
	{
    new(MON+"1wildboyz.c")->move(this_object());
    //ob->set("aggressive", 0); 
	}
  }
    if (!present("mekboyz")) 
    {
	i = random(1)+1;
	while(i--)
	{
    ob= new(MON+"2mekboyz.c");
    ob->move(this_object());  
	}
  }
    if (!present("painboyz")) 
    {
	i = random(1)+1;
	while(i--)
	{
    ob= new(MON+"3painboyz.c");
    ob->move(this_object());  
	}
  }

   if (!present("madboyz")) 
    {
	i = random(1)+1;
	while(i--)
	{
    new(MON+"4madboyz.c")->move(this_object());   
	}
  }
}


void create(){
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);

    set_property("quick study", 1);

    set("short", "Ork Entrance");
    set("long",@ext
A wide boulder in a overcast thicket marks the entrance to this dungeon. Beyond the boulder lies a modest, worn room. It's covered in broken pottery, rat droppings and roots.
Your torch allows you to see broken arrows, rusty swords and skeletal remains, deteriorated and butchered by time itself.
       
        out   
    @
        down
    
ext);
    set_exits( ([
	"out": "/d/damned/virtual/room_37_7.world",
	"down": "d/areas/ork/rooms/01",
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
