inherit "/std/room";
void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
  set_property("no scry", 1);
set_property("no summon", 1);
	set_property("no teleport",1);

//_-=added below to fix the exits commented out old exits=-_ (TINY)
  set_exits( ([ "north" : "/d/damned/guilds/tinker/t_hole","south" : "/d/damned/guilds/tinker/ti_treas"  ]));

   //add_exit("/d/damned/guilds/tinker/ti_treas", "north");
   //add_exit("/d/damned/guilds/tinker/train_room", "east");
   set("short","The Dragons Hord");
   set("long",
"This room is piled with gold and on top of it you see a Dragon! "+
  "A tiny hole behind the piles of gold can be seen to the north.");
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


if(!present("dragon")) {
    new("/d/damned/guilds/tinker/t_dragon")->move(this_object());
}

}

