inherit "std/room";
#include <std.h>

void init() {
     ::init();
     call_out("damage_living",12);
}
void damage_living() {
     object *living;
int i;
     living = all_inventory(this_object());
     living = filter_array(living, "test_living", this_object());
     if(!living || !sizeof(living)) return;
     for(i=0; i < sizeof(living); i++) {
     living[i]->add_hp(-5);
     message("info","%^RED%^You are taking fire damage!%^RESET%^",living[i]);
}
     remove_call_out("damage_living");
     call_out("damage_living",12);
}
int test_living(object ob) {
     if(ob->is_player()) return 1;
     return 0;
}
void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "Maze");
     set("long", "The light source is a gentle glowing coming from the ceiling.  There must be a pool of magma directly overhead. The walls are slightly warped from the immense heat in this area.  All the exits are just chiseled holes out of the stone walls."


         );
     set_listen("default", "You feel like you are walking in circles.");
     add_item("walls", "The walls are very smooth and are hot to the touch.");
     add_item("ceiling", "The ceiling is glowing from the magma pool directly overhead.");
     add_exit("mz2", "west");
     add_exit("mz4", "east");
     add_exit("mz6", "north");
     add_exit("mz20", "south");
}
void reset() {
     ::reset();
     if(!present("demon1")) {
     new(MON_PATH+"demon1")->move(this_object());
}
}
