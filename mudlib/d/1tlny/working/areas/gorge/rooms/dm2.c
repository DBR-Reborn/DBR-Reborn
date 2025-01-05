inherit "std/room";

void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set_smell("default", "There is a strong smell of sulfur in the air.");
     set("short", "Middle of the entrance");
    set("long",
     "You work you way down the crevice.  There are jagged rocks all around you.  You can see a light source coming from farther down the hole.\n"
     );
     set_items( (["rocks" : "The rocks are razor sharp." ]) );
     set_exits( ({"dm3", "dm1"}), ({"down", "up"}) );
}
