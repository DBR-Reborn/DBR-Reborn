
inherit "std/room";

void create() {
     ::create();
     set_property("outdoors", 1);
     set_property("light", 2);
     set_smell("default", "There is a slight odor of sulfur in the air.");
     set("short", "A huge crack in the ground");
     set("long",
         "There is a giant opening in the ground and you see smoke rising from it.  You might be able to climb down it.\n"
     );

     set_items( ([ "crack": " The crack seems to go down forever." ]) );
add_post_exit_function("dm2","monitor");
     add_exit("dm2", "down");
    add_exit("/d/damned/virtual/room_34_27.world", "out");
}
