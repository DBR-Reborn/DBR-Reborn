inherit ROOM;

void create() {
  ::create();
    set_property("light",2);
    set_property("night light", 1);
    add_exit("/wizards/tobias/test/test_room", "off");
    add_exit("/wizards/tobias/areas/underland/room2", "north");
    set("short","A road to Vidyanoi");
    set("long",
"This is the road to Vidyanoi. The brush and trees have grown to "
"almost completely cover the road. Althought heavily overgrown the "
"direction in which the road leads is obvious." );
}
