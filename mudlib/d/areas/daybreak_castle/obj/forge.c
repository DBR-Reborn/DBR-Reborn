inherit "/std/room";
void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
  set_property("no scry", 1);
set_property("no summon", 1);
	set_property("no teleport",1);

//_-=added below to fix the exits commented out old exits=-_ (TINY)
  set_exits( ([ "north" : "/d/areas/daybreak_castle/rooms/r8",
	     "east" : "/d/areas/daybreak_castle/rooms/r10" ]));

add_exit("/d/areas/daybreak_castle/rooms/r9", "northeast");
add_exit("/d/areas/daybreak_castle/rooms/r11", "southeast");
add_exit("/d/areas/daybreak_castle/rooms/r7", "northwest");
add_exit("/d/areas/daybreak_castle/rooms/r5", "southwest"); 
add_exit("/d/areas/daybreak_castle/rooms/r3", "south");  
   set("short","The Forge Room");
   set("long",
"This room is very hot with the fires of a small forges. "+
  "You see some mice and rats bedding nearby for warmth, you can use this forge to tinker.");
}
void reset() {
object forge;
::reset();
//_-=Fixed forge it was Broken room works NOW! TINY=-_
if(!present("forge")) {
forge = new("/d/areas/daybreak_castle/forge");
        forge->set_weight(100000000);
        forge->move(this_object());
}

}
