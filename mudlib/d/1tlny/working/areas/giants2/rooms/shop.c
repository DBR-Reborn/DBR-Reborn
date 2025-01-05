#include "giants_paths.h"
inherit "/std/vault";


private int open;

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("conrad") && open) {
      new(ROOMS_PATH+"conrad.c")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS_PATH+"market5", "west");
   add_exit(ROOMS_PATH+"storage", "north");
   set_door("wooden door", ROOMS_PATH+"storage", "north",
           "storage");
   set_open("wooden door", 0);
   set_locked("wooden door", 1);
   open = 1;
   set_door("east door", ROOMS_PATH+"market5", "west",
           "shop");
    set_open("east door", 1);
   set_locked("east door", 0);
   set_lock_level("wooden door", 20);
   set("short","The Storm Giant Armoury");
   set("long",@EndText
This is the armour shop of the storm-giants.
Here you can find many high quality types of
armour, forged by the well known Conrad Storm-
beard and his qualified helpers, this place is
legendary throughout the realm for always
providing the best armour for its customers.
EndText
);
   set_items( (["sign":"The say reads: 'say conrad, help' for assistance.",
              "wooden door" : "It looks very sturdy."]) );
   set_open_function("open_door", "4:30:00");
   set_close_function("close_door", "17:30:00");
}

void open_door() {
  set_locked("north door", 0);
  set_open("north door", 1);
  call_other(ROOMS_PATH+"market5", "set_locked",
            "east door", 0);
  call_other(ROOMS_PATH+"market5", "set_open",
            "east door", 1);
  open = 1;
  this_object()->reset();
  return;
}

void close_door() {
  object ob, *inv;
  int i;
  
  ob = present("conrad", this_object());
  if(ob) {
    ob->move(find_object_or_load("/d/standard/void"));
    ob->remove();
  }
  inv = all_inventory(this_object());
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i])) {
      message("info", "The shop is closing now.  You must leave.", inv[i]);
      inv[i]->move(find_object_or_load(ROOMS_PATH+"market5"));
    }
  }
  set_open("east door", 0);
  set_locked("east door", 1);
  call_other(ROOMS_PATH+"market4", "set_open", 
               "east door", 0);
  call_other(ROOMS_PATH+"market4", "set_locked", 
               "east door", 1);
   open = 0;
}
