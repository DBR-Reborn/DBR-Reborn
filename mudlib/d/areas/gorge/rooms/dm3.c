inherit "std/room";

void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "Deep inside chasm.");
     set("long",
         "You finally find somewhat stable flooring here.  It seems that there is a passage here leading into three directions.  The heat here is becoming uncomfortable.\n"
        );
     set_exits( ({"dm2", "dm4", "dm5", "dm6"}), ({"up", "north", "south", "east"}) );
}

