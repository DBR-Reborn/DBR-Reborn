// Wizard: Gellor
// Jesip's Storage
// jesip_storage.c
#include <std.h>
inherit "/std/vault";
void clone_once();
void create() {
  ::create();
  set_short("You should not be here!");
  set_long("This is the storage room for Jesip's shop. It is ");
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no scry", 1);
  set_property("no summon", 1);
  set_property("no teleport", 1);
  set_property("storage room", 1);
    add_exit("/wizards/gellor/newfirn/shops/schtel_shop.c", "south");
  set_locked("wooden door", 1);
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
  bob = present("shopkeeper",this_object()); 
                 
  if(bob) {
      message("info", "Jesip says in Common: Finally! A new "
              "shipment has finally arrived!", environment(bob));
    call_out("finish_deliver",5, bob);
  }
  i = 5;
  while(i--) {
    new("/wizards/gellor/newfirn/obj/jerky.c")->move(this_object());
    new("/wizards/gellor/newfirn/obj/waterskin.c")->move(this_object());
    new("/wizards/gellor/newfirn/obj/silk_bag.c")->move(this_object());
    new("/wizards/gellor/newfirn/obj/torch.c")->move(this_object());
    new("/wizards/gellor/newfirn/obj/rations_pack.c")->move(this_object());
  }
}
void finish_deliver(object bob) {
  if(bob)
      message("info", "Jesip says in Common: Now it's all here.",
            environment(bob));
  return;
} 
