inherit ROOM;

void create() {
  ::create();
    set_property("light",2);
    set_property("night light", 1);
    add_exit("/wizards/tobias/areas/underland/room29", "north");
    add_exit("/wizards/tobias/areas/underland/room10", "south");
    add_exit("/wizards/tobias/areas/underland/room6", "west");
    set("short","In a dense field");
    set("long",
"Swaying with the breeze, plants and trees seem to come alive with "
"with thier motion. A smell of death enter with each gust leaving "
"a strong odor on the foliage itself.");
}
