inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/tinker/forge_room", "south");
   add_exit("/d/damned/guilds/tinker/special_room", "north");
   set("short","The Tinker Treasury");
   set("long",
  "This room is somewhat of a closet. To the south is a much "+
"nicer room. "
"This is the Tinker Treasury.  Any tinker may store items here, "
"but they are open to use by any other tinker.  Several lockers and "
"chests lie about.  \nMAKE SURE you close a chest after using it, "
"or the items may be lost!");

if (!present("rune")) {
	new ("/std/diewarzau/obj/misc/h_rune") ->move(this_object());
	 }
//if (!present("locker")) {
//	new("/std/diewarzau/obj/misc/storage_locker")->move(this_object());
//	}
}



