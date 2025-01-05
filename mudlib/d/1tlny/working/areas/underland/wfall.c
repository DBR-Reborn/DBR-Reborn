inherit ROOM;

void create() {
  ::create();
    set_property("light",2);
    set_property("night light", 1);
   set_smell("default", "The smell of rotting flesh is everywhere.");
    set_listen("default", "A loud rumbling is heard outside.");
    add_exit("/wizards/tobias/areas/underland/rock3", "out");
    set("short","Behind the falls");
    set("long",
"This is the damp lair behind the waterfall. Scattered bones rest near "
"a large nest made of grass and straw. Besides the massive nest "
"the lair is empty and rather dreary.");

}

void reset() {
       ::reset();
       if(!present("goblin"))
new("wizards/tobias/areas/underland/mon/g_troll.c")->move(this_object());
}
