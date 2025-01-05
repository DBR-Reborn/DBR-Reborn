inherit "std/room";



void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "Small decline");
     set("long",
         "The corridor starts to decline a bit and you have to try to get traction to avoid sliding downward.  The heat is getting unbareable.\n"
        );
     set_listen("default", "The bubbling sound is coming from the north.  Sounds like someone has a pot of coffee going.");
     add_exit("dm4a", "south");
     add_exit("dm4ba", "north");
}










