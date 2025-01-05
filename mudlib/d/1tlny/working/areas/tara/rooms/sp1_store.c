#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
#define MY_INV ({ "torch", "sextant", "lantern", "oil" })
#define MAX_INV 25
inherit VAULT;

void clone_once();

void create() {
  ::create();
   set_short("Robs storage room.");
   set_long("This is the storage room of Rob, if anyone "
   "catches you in here, it might be the last place you see.");
   set_property("light", 2);
   set_property("indoors", 1);
   set_property("no scry", 1);
   set_property("no summon", 1);
   set_property("no teleport", 1);
   set_property("storage room", 1);
   return;
}

int my_inv_filter(object item) {
  int i;

  i = sizeof(MY_INV);
  while(i--) if(item->id(MY_INV[i])) return 1;
  return 0;
}

void remove_all(object *inv) {
  int i;


  i = sizeof(inv);
  while(i--) if(inv[i] && !living(inv[i]) && environment(inv[i]) ==
this_object()) inv[i]->remove();
  return;
}

void reset() {
   object rob, *inv;
   int i;

   ::reset();
   seteuid(getuid());
   inv = filter_array(all_inventory(this_object()), "my_inv_filter",
       this_object());
   call_out("remove_all", 5, inv);
   inv = all_inventory(this_object());
   if(sizeof(inv) > MAX_INV) {
     for(i=MAX_INV-1;i<sizeof(inv);i++) inv[i]->remove();
   }
   rob = present("shopkeeper", 
                 find_object_or_load(TARAROOMS+"sp1"));
  if(rob) {
    message("info", "Rob looks exited as a group of halflings bring in "+
					 "some more goods.", environment(rob));
    call_out("finish_deliver", 4, rob);
  }
  clone_once();
  return;
}
void finish_deliver(object rob) {
  if(rob)
    message("info", "The halflings put the goods in the storage room.",
					    environment(rob));
  return;
}

void clone_once() {
   object ob;
   int i;

   seteuid(getuid());
   for(i=1; i <= 10; i++) {

     ob = new(TARAOBJ+"torch");
     ob->move(this_object());
     ob = new(TARAOBJ+"oil");
     ob->move(this_object());
   if(i <= 7) {
     ob = new(TARAOBJ+"lantern");
     ob->move(this_object());
   }
   if(i <= 5) {
     ob = new(TARAOBJ+"sextant");
     ob->move(this_object());
     ob = new(TARAOBJ+"waterskin");
     ob->move(this_object());
   }
   }
  return;
}
