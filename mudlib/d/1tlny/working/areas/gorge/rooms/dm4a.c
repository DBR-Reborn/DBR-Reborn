inherit "std/room";

void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
 
     set("short", "Northern Corridor");
set("long",
         "The tunnel seems to widen out a bit here to allow you more walking space.  There is two exits to the north and one going back to where you came from.\n"
        );
     set_listen("default", "The bubbling sound is getting stronger.");
     add_exit("dm4", "south");
     add_exit("dm4b", "northeast");
     add_exit("dm4c", "north");
}
