#include "../newshards.h"
inherit "/std/vault";

private int open;

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("zinst")) {
      new(MON+"zinst")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"street3", "east");
   set_open("wooden door", 0);
   set_locked("wooden door", 1);
   open = 1;
    set_open("east door", 1);
   set_locked("east door", 0);
   set_lock_level("wooden door", 20);
   set("short","The Weapon Shop");
   set("long",
"Inside this medium sized building is a weapon shop. It seems to be well-stocked, but something nags you about its wares. They're different from what you've seen in Daybreak Ridge... somehow. ");
   set_items( (["sign":"The say reads: 'say zinst, help' for assistance.",
              "wooden door" : "It looks very sturdy."]) );
}

void open_door() {
  set_locked("east door", 0);
  set_open("east door", 1);
  call_other("/d/damned/akkad/ak_markne", "set_locked",
	     "east door", 0);
  call_other("/d/damned/akkad/ak_markne", "set_open",
	     "east door", 1);
  open = 1;
  this_object()->reset();
  return;
}

void close_door() {
  object ob, *inv;
  int i;
  
  ob = present("zinst", this_object());
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
  set_open("east door", 0);
  set_locked("east door", 1);
  call_other("/d/damned/akkad/ak_markne", "set_open", 
		"east door", 0);
  call_other("/d/damned/akkad/ak_markne", "set_locked", 
		"east door", 1);
   open = 0;
}
