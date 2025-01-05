#include <std.h>
#include "../newshards.h"
#define TORSO_ARMOUR ({ "cloak", "leather-jacket", "studded-leather-vest", "studded-leather-jacket", "quilted-vest", "leather-vest" })
#define LEG_ARMOUR ({ "wing-guards", "spats", "leather-pants", "studded-leather-pants" })
#define HEAD_ARMOUR ({ "leather-hood", "robe", "leather-belt", "leather-boots" })

inherit "/std/vault";

void clone_once();

void create() {
  ::create();
  set_short("You probably shouldn't be here!");
  set_long(
	   "This is the storage room for the Armoursmith Shop. Lots of "
	   "valuable looking wares lie about.");
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no summon", 1);
  set_property("no scry", 1);
  set_property("no teleport", 1);
  set_property("storage room", 1);
  set_open("wooden door", 0);
  set_locked("wooden door", 1);
  set_lock_level("wooden door", 22);
  return;
}

void remove_all(object *inv) {
  int i;

  i = sizeof(inv);
  while(i--) if(inv[i] && !living(inv[i]) && environment(inv[i]) == this_object()) inv[i]->remove();
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
                find_object_or_load(ROOMS+"armourshop"));
  if(bob) {
    message("info", "Joseph says in Common: Wait a second.  I've got a new "+
	    "shipment coming in...", environment(bob));
    call_out("finish_deliver", 12, bob);
  }
  for(i = 1;i <= 6;i++)
    call_out("clone_once", i*2);
  return;
}

void finish_deliver(object bob) {
  if(bob)
    message("info", "Joseph says in Common: It's all here now.",
	    environment(bob));
  return;
}

void clone_once() {
  object ob;
  int i;

  seteuid(getuid());
  for(i = 1; i <= 2; i++) {
    ob = new("/d/damned/virtual/studded-leather-glove.armour");
  ob->set_material("misc/leather");
    ob->move(this_object());
    ob = new("/d/damned/virtual/gauntlet.armour");
  ob->set_material("misc/leather");
    ob->move(this_object());
    ob = new("/d/damned/virtual/padded-glove.armour");
  ob->set_material("misc/leather");
    ob->move(this_object());
  }
  ob = new("/d/damned/virtual/"+
      TORSO_ARMOUR[random(sizeof(TORSO_ARMOUR))]
      + ".armour");
  ob->set_material("misc/leather");
  ob->move(this_object());
  ob = new("/d/damned/virtual/"+
      LEG_ARMOUR[random(sizeof(LEG_ARMOUR))]
      + ".armour");
  ob->set_material("misc/leather");
  ob->move(this_object());
  ob = new("/d/damned/virtual/"+
      HEAD_ARMOUR[random(sizeof(HEAD_ARMOUR))]
      + ".armour");
  ob->set_material("misc/leather");
  ob->move(this_object());
  return;
}
