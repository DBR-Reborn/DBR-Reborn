#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit VAULT;

private int open;

void reset() {
  ::reset();
   seteuid(getuid());
   if(!present("rob")) {
     new(TARAMON+"rob")->move(this_object());
   }
}

void create() {
  ::create();
   set_property("light",3);
   set_property("night light",1);
   add_exit(TARAROOMS+"rm18", "east");
   set_door("round door", TARAROOMS+"rm18", "east", 0);
    set_open("round door", 1);
    set_locked("round door", 0);
    open = 1;
   set("short","Rob's General Store");
   set("day long", @DAY
This shop is built into the hillside of Tara.  Here is
where Rob sells general goods to the public, and buys just
about anything from them.  Here you can buy almost anything
you need to survive in this little town, and while the goods
are not the best, they are well priced.
DAY
);
   set("night long", @NIGHT
This empty shop is built into the hillside of Tara.  Rob may
hang out here while the shop is closed at night because he is
having some problems with the wife at home.  During the day,
this is the place to buy goods needed to live in this town.
NIGHT
);
   add_item("goods", "Assorted goods such as food, torchs, "+
   "and other supplies.");
   set_listen("default","You can hear Rob bartering with "+
   "his customers.");
}

void open_door() {
   set_locked("round door", 0);
   set_open("round door", 1);
   call_other(TARAROOMS+"rm18", "set_locked",
   "round door", 0);
   call_other(TARAROOMS+"rm18", "set_open",
   "round door", 1);
   open = 1;
   this_object()->reset();
  return;
}

void close_door() {
   object ob, *inv;
   int i;
  
   ob = present("rob", this_object());
   if(ob) {
    ob->move(find_object_or_load("/d/standard/void"));
    ob->remove();
   }
   inv = all_inventory(this_object());
   i = sizeof(inv);
   while(i--) {
    if(living(inv[i])) {
      message("info", "Rob closes the shop.  You leave.", inv[i]);
      inv[i]->move(find_object_or_load(TARAROOMS+"rm18"));
     }
   }
   set_open("round door", 0);
   set_locked("round door", 1);
   call_other(TARAROOMS+"rm18", "set_open", 
   "round door", 0);
   call_other(TARAROOMS+"rm18", "set_locked", 
   "round door", 1);
   open = 0;
}
