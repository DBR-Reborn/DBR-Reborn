#include "giants_paths.h"
inherit "/std/vault";


private int open;

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("stormos") && open) {
      new(ROOMS_PATH+"stormos.c")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS_PATH+"market1", "east");
   add_exit(ROOMS_PATH+"gen_storage", "north");
   set_door("wooden door", ROOMS_PATH+"gen_storage", "north",
           "gen_storage");
   set_open("wooden door", 0);
   set_locked("wooden door", 1);
   open = 1;
   set_door("east door", ROOMS_PATH+"market1", "east",
           "shop");
    set_open("west door", 1);
   set_locked("west door", 0);
   set_lock_level("wooden door", 20);
   set("short","The Storm Giant General Store");
   set("long",@EndText
EndText
);
   set_items( (["sign":"The say reads: 'say stormos, help' for assistance.",
              "wooden door" : "It looks very sturdy."]) );
   set_open_function("open_door", "5:00:00");
   set_close_function("close_door", "18:00:00");
}

void open_door() {
  set_locked("north door", 0);
  set_open("north door", 1);
  call_other(ROOMS_PATH+"market4", "set_locked",
            "west door", 0);
  call_other(ROOMS_PATH+"market4", "set_open",
            "west door", 1);
  open = 1;
  this_object()->reset();
  return;
}

void close_door() {
  object ob, *inv;
  int i;
  
  ob = present("stormos", this_object());
  if(ob) {
    ob->move(find_object_or_load("/d/standard/void"));
    ob->remove();
  }
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i])) {
      message("info", "The shop is closing now.  You must leave.", inv[i]);
      inv[i]->move(find_object_or_load(ROOMS_PATH+"market1"));
    }
  }
  set_open("west door", 0);
  set_locked("west door", 1);
  call_other(ROOMS_PATH+"market1", "set_open", 
               "west door", 0);
  call_other(ROOMS_PATH+"market4", "set_locked", 
               "west door", 1);
   open = 0;
}

