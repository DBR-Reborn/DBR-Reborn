#include "../newshards.h"
inherit "/std/vault";

private int open;

void reset() {
   ::reset();
   seteuid(getuid());
     if (!present("tinkerfiddle")) {
        new(MON+"tinkerfiddle")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"street3", "west");
   set_open("wooden door", 0);
   set_locked("wooden door", 1);
   open = 1;
    set_open("north door", 1);
   set_locked("north door", 0);
   set_lock_level("wooden door", 20);
   set("short","The Armour Shop");
   set("long",
"This armour shop appears to be more of a clothing store than anything else. Try as you might, you cannot find a single piece of metal armour anywhere on the shelves. What kind of armour shop doesn't even sell gauntlets?");
   set_items( (["sign":"The say reads: 'say tinkerfiddle, help' for assistance.",
              "wooden door" : "It looks very sturdy."]) );
}

void open_door() {
  set_locked("north door", 0);
  set_open("north door", 1);
  call_other("/d/damned/akkad/ak_markne", "set_locked",
	     "north door", 0);
  call_other("/d/damned/akkad/ak_markne", "set_open",
	     "north door", 1);
  open = 1;
  this_object()->reset();
  return;
}

void close_door() {
  object ob, *inv;
  int i;
  
  ob = present("tinkerfiddle", this_object());
  if(ob) {
    ob->move(find_object_or_load("/d/standard/void"));
    ob->remove();
  }
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i])) {
      message("info", "The shop is closing now.  You must leave.", inv[i]);
      inv[i]->move(find_object_or_load("/d/damned/akkad/ak_markne"));
    }
  }
  set_open("north door", 0);
  set_locked("north door", 1);
  call_other("/d/damned/akkad/ak_markne", "set_open", 
		"north door", 0);
  call_other("/d/damned/akkad/ak_markne", "set_locked", 
		"north door", 1);
   open = 0;
}
