#include <shao.h>
inherit "/std/vault";

private int open;

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("joseph") && open) {
      new("/d/damned/akkad/obj/mon/joseph")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
add_exit("1st8", "west");
add_exit("arm2","east");
set_door("wooden door", "arm2", "east", "Shao-tan key");
   set_open("wooden door", 0);
   set_locked("wooden door", 1);
   open = 1;
set_door("east door", "1st8", "west", "Shao-tan key");
    set_open("north door", 1);
   set_locked("north door", 0);
   set_lock_level("wooden door", 20);
   set("short","The Armoursmith Shop");
   set("long",
"This is the Armoursmith Shop.  Various objects of armour adorn the "
"walls and counters.  A sturdily built, sweaty shopkeeper peers at "
"you from behind a small table.  There is a large wooden door to the "
"east.  There is a sign on the wall.");
   set_items( (["sign":"The say reads: 'say joseph, help' for assistance.",
              "wooden door" : "It looks very sturdy."]) );
   set_open_function("open_door", "5:00:00");
   set_close_function("close_door", "16:30:00");
}

void open_door() {
set_locked("east door", 0);
set_open("east door", 1);
call_other("1st8", "set_locked",
"east door", 0);
  call_other("/d/damned/akkad/ak_markne", "set_open",
	     "north door", 1);
  open = 1;
  this_object()->reset();
  return;
}

void close_door() {
  object ob, *inv;
  int i;
  
  ob = present("joseph", this_object());
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
