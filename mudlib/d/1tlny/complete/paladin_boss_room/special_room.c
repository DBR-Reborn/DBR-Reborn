inherit "/std/room";
void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",-1);
  set_property("no scry", 1);
set_property("no summon", 1);
	set_property("no teleport",1);

//_-=added below to fix the exits commented out old exits=-_ (TINY)
  set_exits( ([ "west" : "/d/damned/guilds/paladin/proom/special_room2","east" : "/d/damned/guilds/paladin/p_treas"  ]));

   //add_exit("/d/damned/guilds/tinker/ti_treas", "north");
   //add_exit("/d/damned/guilds/tinker/train_room", "east");
   set("short","The Liches path");
   set("long",
"This room is filled with dead bodies everywere! You think to yourself why would the holy Paladins keep such a place? Standing before you you see a holy knight protecting a hole to the West. "+
  "A tiny hole behind the pile of corpses can be seen to the west.");
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


if(!present("knight")) {
    new("/d/damned/guilds/paladin/proom/p_knight")->move(this_object());
 
}

}

