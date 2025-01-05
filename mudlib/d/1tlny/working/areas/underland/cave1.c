inherit ROOM;

void reset()
{
  ::reset();
  remove_exit("west");
}

void create() {
  ::create();
    set_property("light",2);
    set_property("night light", 1);
    set_smell("default", "The smell of rotting flesh lingers in the air.");
    add_exit("/wizards/tobias/areas/underland/cave2", "south");
    add_exit("/wizards/tobias/areas/underland/cave3", "north");
    add_exit("/wizards/tobias/areas/underland/room8", "east");
    set("short","The mouth of a cave");
    set("long",
"This is a large opening to a cave. The ceiling is open allowing "
"light to pass through. A stiff breeze flows in from the opening "
"keeping the cave somewhat dry, but at the same time stirring up "
"unpleasant sents.");
     new("/wizards/tobias/areas/underland/obj/stream.c")->move(this_object());
  set_search("rock",(:call_other, this_object(), "search_rock":));
  set_search("west",(:call_other, this_object(), "search_rock":));
  set_search("rocks",(:call_other, this_object(), "search_rock":));
}

void search_rock()
{
  write("You push the rocks aside and find a tunnel formed by the stream.\n");
  say(this_player()->query_cap_name()+
      " searches for a bit, then pushes aside some rocks and reveals a tunnel formed by the stream.\n");
  add_exit("/wizards/tobias/areas/underland/rock1","west");
  return;
}
