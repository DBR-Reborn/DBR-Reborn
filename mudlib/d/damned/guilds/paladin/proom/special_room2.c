inherit "/std/room";
void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",-1);
  set_property("no scry", 1);
set_property("no summon", 1);
	set_property("no teleport",1);


  set_exits( ([ "west" : "/d/damned/guilds/paladin/proom/p_loot","east" : "/d/damned/guilds/paladin/proom/special_room"  ]));


   set("short","The Liches prison");
   set("long",
"This room is filled with dead bodies piled like a mountain! You should not be here! in the corner you see a hold lich that looks at you with blood red eyes grinning as you have freed him from his prison! ");
}



void reset() {

::reset();



if(!present("lich")) {
    new("/d/damned/guilds/paladin/proom/p_lich")->move(this_object());
 
}

}

