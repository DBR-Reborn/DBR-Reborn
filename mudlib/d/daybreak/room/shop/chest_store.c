#include <std.h>
#include "../../daybreak.h"

inherit "/std/vault";

void clone_once();

void create() {
  ::create();
  set_short("You probably shouldn't be here!");
  set_long(
           "This is the storage room for the Chest Shop. Lots of "
           "valuable looking wares lie about.");
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no scry", 1);
  set_property("no summon", 1);
  set_property("no teleport", 1);
  set_property("storage room", 1);
  add_exit(ROOMS+"shop/chest", "south");
  set_door("wooden door", ROOMS+"shop/chest", "south","ak shop6 store");
  set_open("wooden door", 0);
  set_locked("wooden door", 1);
  set_lock_level("wooden door", 22);
  return;
}

void remove_all(object *inv) {
  int i;

  i = sizeof(inv);
  while(i--) if(inv[i] && !living(inv[i]) && environment(inv[i]) ==
this_object()) inv[i]->remove();
  return;
}

void reset() {
  object *inv, bob;
  int i;

  ::reset();
  seteuid(getuid());
  inv = all_inventory(this_object());
  call_out("remove_all", 5, inv);
  bob = present("shopkeeper", 
                find_object_or_load("/d/damned/akkad/ak_shop6"));
  if(bob) {
    message("info", "Gil says in Common: Wait a second.  I've got a new "+
            "shipment coming in...", environment(bob));
    call_out("finish_deliver",5, bob);
  }
  i = 5;
  while(i--) {
    new("/std/obj/safe")->move(this_object());
   // new("/std/diewarzau/obj/misc/small_chest")->move(this_object());
    new("/std/obj/large_chest")->move(this_object());
    new("/std/diewarzau/obj/misc/storage_locker")->move(this_object());
  }
}

void finish_deliver(object bob) {
  if(bob)
    message("info", "Gil says in Common: It's all here now.",
            environment(bob));
  return;
}
