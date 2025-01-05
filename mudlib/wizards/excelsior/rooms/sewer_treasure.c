// /wizards/excelsior/rooms/sewer_treasure

#include <std.h>

inherit ROOM;

//void reset() {
	//object money;
	//::reset();
	//if (!present("coins")) {
		
	//}
//}

void create() {
	object money;
	::create();
	set_property("light",0);
	set_property("indoors",1);
	set("short","A dead end in the sewers");
	set("long",@ext The tunnel you were following has met an abrupt end here. 
		However, on the bright side of things, this sewer chamber seems 
		to be some sort of storage room used by the legendary sewer gremlins. 
		There is stuff piled all over covered in sewer goo. You wouldn't 
		want to touch any of it.      
       
    @
     \
      0
ext);
	set_items( (["stuff":"It is all very wet from sewer water."]) );
	set_exits( (["southeast":"/wizards/excelsior/rooms/sewer2.6"]) );
        money = new("/std/obj/coins");
		money->set_money("gold",random(900)+1);
		money->set_money("silver",random(1500)+1);
		money->move( this_object() ); 
	reset();
}


