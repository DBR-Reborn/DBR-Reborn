inherit "std/room";

void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "fountain room");
     set("long", "The walls here are not hot like the rest of the maze.  There does not seem to be any heat flowing from the walls.  There is a fountain in the center of this room.");
     set_smell("default", "The room is cool and relaxing.");
     set_listen("default", "You can hear the sound of people burning in the maze.");
     add_item("walls", "The walls are actually cool to the touch...weird.");
     add_exit("mz27", "south");
     new("/d/areas/gorge/obj/paper")->move(this_object());
}
void init() {
     ::init();

     if(this_player()->chk_my_mob())
       add_action("no_exit", "up");
     add_action("do_drink", "drink");
}

int do_drink(string str) {
     if(!str) {
       notify_fail("What do you want to drink?\n");
     return 0;
}
     if(str !="water" && str!= "fountain") {
     return 0;
}
     this_player()->add_quenched(5);
     write("You bend down and drink the clear water from the fountain.\n");
     say(this_player()->query_cap_name()+" gulps water from the fountain.\n",
           this_player());
     return 1;
}
