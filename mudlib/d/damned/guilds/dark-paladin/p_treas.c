inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/dark-paladin/skill_room", "south");
   set("short","The Dark-Paladin Treasury");
   set("long",
"This is the Dark-Paladin Treasury.  Any dark-paladin may store items here, "
"but they are open to use by any other dark-paladin.  Several lockers and "
"chests lie about.  \nMAKE SURE you close a chest after using it, "
"or the items may be lost!");

if (!present("rune")) {
	new ("/std/diewarzau/obj/misc/h_rune") ->move(this_object());
	 }

}
