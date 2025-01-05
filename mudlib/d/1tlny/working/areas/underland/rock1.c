inherit ROOM;

void create() {
  ::create();
    set_property("light",1);
    set_property("night light", 1);
    set_smell("default", "The smell of rotting flesh fills the air.");
     set_listen("default", "A faint rumbling echos constantly.");
    add_exit("/wizards/tobias/areas/underland/cave1", "east");
    add_exit("/wizards/tobias/areas/underland/rock2", "west");
     set("short","Entry of a tunnel.");
    set("long",
"This is the entrance of an eroded tunnel. Chunks of flesh "
"litter the ground. Fungus grows thick along the edges of the tunnel "
"and provide what little color this place has.");
     new("/wizards/tobias/areas/underland/obj/stream2.c")->move(this_object());
}
