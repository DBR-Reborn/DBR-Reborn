inherit ROOM;

void create() {
  ::create();
    set_property("light",2);
    set_property("night light", 1);
    add_exit("/wizards/tobias/areas/underland/room26", "north");
    add_exit("/wizards/tobias/areas/underland/room13", "east");
    add_exit("/wizards/tobias/areas/underland/room30", "west");
    add_exit("/wizards/tobias/areas/underland/room9", "south");
    set("short","In a dense field");
    set("long",
"The road is now lost if it was ever here. Damp foliage covers gound "
"entirely hiding even your own tracks. A slight breeze blows "
"softly from the east." );
}
