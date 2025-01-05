#include <shao.h>
inherit "/std/vault";

void clone_once();

void create() {
  ::create();
  set_short("You probably shouldn't be here!");
  set_long(
"This is Sabrina's storage room, where she keeps all "
"the leather items she has crafted.\n");
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no summon", 1);
  set_property("no scry", 1);
  set_property("no teleport", 1);
  set_property("storage room", 1);
add_exit(PATH+"leather_shop","west");
set_door("wooden door", PATH+"leather_shop","west",
"master key");
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
find_object_or_load(PATH +"leather_shop"));
  if(bob) {
message("info","Sabrina says in Common : Wait a second. I've just "
"finished some more leathers...", environment(bob));
    call_out("finish_deliver", 12, bob);
  }
  for(i = 1;i <= 6;i++)
    call_out("clone_once", i*2);
  return;
}

void finish_deliver(object bob) {
  if(bob)
message("info","Sabrina says in Common : Ok it's all ready now.",
	    environment(bob));
  return;
}

void clone_once() {
  object ob;
  int i;

  seteuid(getuid());
  for(i = 1; i <= 2; i++) {
ob = new(ARMOR_PATH+"l_thong");
    ob->move(this_object());
ob = new(ARMOR_PATH+"l_boot");
ob->move(this_object());
ob = new(ARMOR_PATH+"l_bra");
ob->move(this_object());
ob = new(ARMOR_PATH+"l_cpanty");
ob->move(this_object());
ob = new(ARMOR_PATH+"l_mask");
ob->move(this_object());
ob = new("/d/damned/virtual/leather-vest.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/leather-jacket.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/studded-leather-jacket.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/leather-pants.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/studded-leather-pants.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/leather-glove.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/studded-leather-glove.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/leather-boots.armour");
ob->move(this_object());
ob = new("/d/damned/virtual/leather-belt.armour");
ob->move(this_object());
  }
  return;
}
