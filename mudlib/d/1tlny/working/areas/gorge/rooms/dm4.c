inherit "std/room";

void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "A narrow corridor");
     set("long",
     "This is more of a hole in the earth then a tunnel.  The only light is a subtle glowing coming from the walls.  There is no real definition to the walls.  They seem to be just burrowed out of the earth.  You notice some comotion coming from the north.\n"
        );
     set_listen("default", "You hear a slight bubbling sound coming from the north.");
     set_smell("default", "The heat is becoming uncomfortable.");
     add_item("walls", "The walls are smooth and warm to the touch");
     add_exit("dm3", "south");
     add_exit("dm4a", "north");
}
