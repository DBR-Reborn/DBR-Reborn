
#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "A Hermit's Hut");
   set_long(
    "This hut is sparsely furnished, and has a dirt floor. The table is "
    "rickety, and has blood, dripping from it. On the wall, written in blood "
    "is the word REDRUM."
   " The ceiling is made of thatch, and is leaking like a sieve. "
    );
     add_exit("plat19", "out");
    set_smell("default", "The smell of blood is unmistakable.");
   set_listen("default", "The wind makes a whistling noise as it blows through the hut.");
  }

   void reset()   {
       ::reset();
      new(PLATMON + "hermit") -> move(this_object());
}


