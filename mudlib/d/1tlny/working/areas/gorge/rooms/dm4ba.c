inherit "std/room";
#include <std.h>
void init() {
     ::init();
     add_action("magma", "enter");
}

void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "Demon spawning area");
     set("long",
         "There are several demons all spawled out next two a very large pool of magma.  They seem to be relaxing somewhat.  They do not notice your puny being.\n"
         );
     set_listen("default", "You can hear the bubbling of the magma.");
     set_items( (["magma": "If you are such a fool that you would enter a pool of magma...go ahead and try."]) );

     add_exit("dm4c", "south");

}
int magma(string str) {
     object who, ob;
     who=this_player();
     if(str=="magma") {
     tell_room(this_object(),""+who->query_cap_name()+" dissapears into the magma pool",who);
     write("%^RED%^You get horribly burned!%^RESET%^");
     who->die();
     write("You watch as your ghost leaves your lifeless body....%^RED%^FOOL!%^RESET%^");
//   this_player()->add_hp("-3000");


     return 1;
}
notify_fail("Enter what? \n");
return 0;
}
void reset() {
     ::reset();
     if(!present("lfegrd1")) {
     new(MON_PATH+"lfegrd1")->move(this_object());
     new(MON_PATH+"tandemon1")->move(this_object());
     new(MON_PATH+"tandemon1")->move(this_object());
     new(MON_PATH+"tandemon1")->move(this_object());



}
}
