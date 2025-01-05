inherit ROOM;

void create() {
  ::create();
    set_property("light",2);
    set_property("night light", 1);
    add_exit("/wizards/tobias/areas/underland/room3", "north");
    add_exit("/wizards/tobias/areas/underland/room1", "south");
    set("short","A road to Vidyanoi");
    set("long",
"The road continues north. Plantlife begins to grow thicker, and "
"the road's direction grows faint." );
}
