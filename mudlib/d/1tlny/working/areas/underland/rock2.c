inherit ROOM;

void create() {
  ::create();
    set_property("light",1);
    set_property("night light", 1);
    set_smell("default", "The smell of rotting flesh fills the air.");
    set_listen("default", "A constant rumbling echos from close by.");
    add_exit("/wizards/tobias/areas/underland/rock3", "north");
    add_exit("/wizards/tobias/areas/underland/rock1", "east");
     set("short","An eroded tunnel.");
    set("long",
"This is a damp, eroded tunnel with rocks scattered about. Large lumps "
"of rotted flesh are make the ground hardly visable. Fungus "
"seems to flurish here." );
     new("/wizards/tobias/areas/underland/obj/stream2.c")->move(this_object());
}
