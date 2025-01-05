// Wizard: Gellor
// Faelana's Storage
// faelana_storage.c
#include <std.h>
inherit "/std/vault";
void clone_once();
void create() {
  ::create();
  set_short("Faelana's Greenhouse Storage");
  set_long("This is the greenhouse portion of Faelana's Greenhouse. "
	   "It is a large building made of long thin metal posts "
           "covered with thick glass with green coloring in it. "
           "The floor is plain soil with many different plants growing "
           "in it.");
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no scry", 1);
  set_property("no summon", 1);
  set_property("no teleport", 1);
  set_property("storage room", 1);
      add_exit("/wizards/gellor/newfirn/faelana_shop.c", "east");
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
  bob = present("shopkeeper", this_object());
                 
  if(bob) {
      message("info", "Faelana says in Common: Here's what I just "
      					 "finished picking in the greenhouse!",
                      environment(bob));
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
      message("info", "Faelana says in Common: Ah...it's all ready to go.",
            environment(bob));
  return;
}
