inherit "/std/vault";

#include <std.h>
void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "Guard room");
     set("long", "The room seems to vibrate a bit.  The vibrations are coming from below you.  The walls seem to be more defined, instead of being just cut out of the earth.There are two very large drawings on both sides of this wall.\n" );  
     set_items( (["drawing" : "The first drawing shows a Grand Demon lord casting a spell on a silver knight.  The other drawing shows the knight being imprisioned." ]) );
     add_exit("dm3", "west");
     add_exit("gr1","door");
     add_pre_exit_function("north","go_north");
     set_post_exit_functions( ({"north","west"}),
        ({"lock_door","lock_door"}) );
     set_door("door","north","door","door key");
     set_string("door","open","The stone door slides open easily.\n");
     set_lock_level("door",99);
     reset();
}
int go_north(){
     if(present("demon guard")){
     write("The demon pushes you back with a strong force");
     return 0;
}
     else return 1;
}
void reset() {
     ::reset();
     if(!present("demon guard")) {
     new(MON_PATH+"guard1")->move(this_object());
     new(MON_PATH+"guard1")->move(this_object());



}
     set_open("door",0);
     set_locked("door",1);
}
int lock_door() {
     set_open("door",0);
     set_locked("door",1);
     return 1;
}
