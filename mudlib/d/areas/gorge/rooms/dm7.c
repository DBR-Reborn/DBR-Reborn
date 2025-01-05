inherit "std/room";

void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "Start of Maze");
     set("long", "This room is vacant of most anything, only scattered bones are lying about.  You must be directly over a pool of magma because the heat is utterly painful.\n"
         );
     set_items( (["bones": "These are the bones from a small group of adventurers who must have come upon this area before you.  They are molted from the massive heat you are feeling from the north."]) );
     set_smell("default", "The smell of sulfur is definately coming from the north.");
     add_exit("dm5", "up");
     add_exit("mz1", "north");
}
