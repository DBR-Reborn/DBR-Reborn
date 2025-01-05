inherit "std/room";
#include <std.h>








void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "Lunch room");
     set("long",
     "There are animal bones scattered all over this area.  Demons are not the cleanest eaters.  There is a pit in the center of the room that has some unlucky gnome toasting in it.  Looks like he is the main course today.\n"
        );
     set_smell("default", "The scent of roasted gnome fills your nostrils.");
     add_item("pit", "This firey pit is burning bright embers onto it's latest poor hapless soul.\n");
     add_item("gnome", "This poor soul must of wandered here right before you did.  He has a terror striken look on his face as if he was cooked alive.\n");
     add_item("bones","The bones are picked clean of all meat.\n");
     add_exit("dm4a", "southwest");
}

void reset() {
     ::reset();
     if(!present("fat Demon")) {
     new(MON_PATH+"fat1")->move(this_object());
     new(MON_PATH+"fat1")->move(this_object());
}
}
