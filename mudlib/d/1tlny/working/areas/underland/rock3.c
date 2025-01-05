inherit ROOM;

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    set_smell("default", "The smell of rotting flesh is everywhere.");
    set_listen("default", "Loud rumbling is heard as water hits the rocks.");
    add_exit("/wizards/tobias/areas/underland/rock2", "south");
    add_exit("/wizards/tobias/areas/underland/wfall", "waterfall");
     set("short","A Waterfall.");
    set("long",
"You are surrounded on all sides by large rocks and a cliff from "
"which a sparkling waterfall flows evenly. Corpses and maggots seem at "
"home here. Large foot prints sunk deep into the mud are everywhere. "
"Plantlife flurishes all around the base of the cliff. ");
   new("/wizards/tobias/areas/underland/obj/waterfall.c")->move(this_object());
}
void reset() {
      ::reset();
       if(!present("maggot"))

new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
new("/wizards/tobias/areas/underland/mon/maggot.c")->move(this_object());
}
