inherit "/std/room";
void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",-1);
  set_property("no scry", 1);
set_property("no summon", 1);
	set_property("no teleport",1);

//_-=added below to fix the exits commented out old exits=-_ (TINY)
  set_exits( ([ "east" : "/d/damned/guilds/paladin/proom/special_room2"  ]));

   //add_exit("/d/damned/guilds/tinker/ti_treas", "north");
   //add_exit("/d/damned/guilds/tinker/train_room", "east");
   set("short","The Loot Room");
   set("long",
"This room is filled with dead bodies piled like a mountain! In the corner you see something maybe you need to search the room in order to find it! ");
}


// Remove and add pile of gold yet to be created (TINY)
void reset() {
//object forge;
::reset();
//_-=Fixed forge it was Broken room works NOW! TINY=-_

/*
if(!present("forge")) {
forge = new("/d/excelsior/tinker/greater_forge");
        forge->set_weight(100000000);
        forge->move(this_object());
}
*/


if(!present("skeleton")) {
    new("/d/damned/guilds/paladin/proom/p_mithskel")->move(this_object());
 
}

}

