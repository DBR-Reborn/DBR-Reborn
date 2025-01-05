inherit ROOM;

void create() {
  ::create();
    set_property("light",2);
    set_property("night light", 1);
    add_exit("/wizards/tobias/areas/underland/room2", "south");
    add_exit("/wizards/tobias/areas/underland/room4", "west");
    add_exit("/wizards/tobias/areas/underland/room5", "north");
    add_exit("/wizards/tobias/areas/underland/room11", "east");
    set("short","A cross in the road to Vidyanoi");
    set("long",
"The road breaks into three roads. The plantlife is now dense, and "
"the road's direction is gone." );
}
