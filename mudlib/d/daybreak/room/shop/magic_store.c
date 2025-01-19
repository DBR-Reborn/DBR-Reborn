#include "../../daybreak.h"
#include <std.h>

inherit "/std/vault";

void clone_once();

void create() {
  ::create();
  set_short("You probably shouldn't be here!");
  set_long("This is the storage room for the Magic Shop. Lots of "
           "valuable looking wares lie about.");
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("no teleport", 1);
  set_property("no summon", 1);
  set_property("no scry", 1);
  set_property("storage room", 1);
  add_exit(ROOMS+"shop/magic", "east");
  set_door("wooden door", ROOMS+"shop/magic", "east","ak shop6 store");
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
  object *inv, bob, ob;
  int i;

  ::reset();
  seteuid(getuid());
  inv = all_inventory(this_object());
  call_out("remove_all", 5, inv);
  bob = present("shopkeeper", find_object_or_load(ROOMS+"shop/magic"));
  if(bob) {
    message("info", "Karsten says in Common: Wait a second.  I've got a new
"+
            "shipment coming in...", environment(bob));
    call_out("finish_deliver",5, bob);
  }
  i = 5;
  while(i--) {
    ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a small healing potion", "healing_potion", "/std/diewarzau/obj/misc/heal_func", 100);
    ob->set_value(650);
    ob->set_weight(50);
	ob->move(this_object());
	ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a small mana potion", "mana_potion", "/std/diewarzau/obj/misc/heal_func", 100);
    ob->set_value(650);
    ob->set_weight(50);
    ob->move(this_object());
	ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a medium healing potion", "healing_potion", "/std/diewarzau/obj/misc/heal_func", 300);
    ob->set_value(10000);
    ob->set_weight(150);
	ob->move(this_object());
	ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a medium mana potion", "manar_potion", "/std/diewarzau/obj/misc/heal_func", 300);
    ob->set_value(10000);
    ob->set_weight(150);
    ob->move(this_object());
	    ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a large healing potion", "healing_potion", "/std/diewarzau/obj/misc/heal_func", 600);
    ob->set_value(24700);
    ob->set_weight(300);
	ob->move(this_object());
	ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a large mana potion", "mana_potion", "/std/diewarzau/obj/misc/heal_func", 600);
    ob->set_value(24700);
    ob->set_weight(300);
    ob->move(this_object());
	
	ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a alabaster potion", "alabaster_potion", "/std/diewarzau/obj/misc/heal_func", 100);
    ob->set_value(1200);
    ob->move(this_object());
//ADD
ob = new("/d/1tlny/loot/crystal/scroll_tp");              
    ob->set_value(100);
    ob->move(this_object());
//END
    ob->move(this_object());
    ob = new("/std/obj/bag_of_holding");
    ob->set_value(5800);
    ob->move(this_object());
    /*ob = new("/std/diewarzau/obj/misc/bag_of_holding_m");
    ob->set_value(22000);
    ob->move(this_object());
    ob = new("/std/diewarzau/obj/misc/bag_of_holding_l");
    ob->set_value(46400);
    ob->move(this_object());
    ob = new("/std/diewarzau/obj/misc/bag_of_holding_h");
    ob->move(this_object());*/
    ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a purple potion", "herb_action",
      "/std/diewarzau/obj/misc/herb_func",
      70);
    ob->set_value(50);
    ob->move(this_object());
    ob = new("/std/diewarzau/obj/misc/small_vial");
    ob->fill_vial("a purple potion", "herb_action",
      "/std/diewarzau/obj/misc/herb_func",
      70);
    ob->set_value(50);
    ob->move(this_object());
//ADD TLNY2025
    new("/std/spells/summon/obj/clay_figurine")->move(this_object());
    new("/std/spells/summon/obj/golden_figurine")->move(this_object());
    new("/std/spells/summon/obj/jeweled_figurine")->move(this_object());
    new("/std/spells/summon/obj/platinum_figurine")->move(this_object());

    new("/std/spells/summon/obj/mythical_figurine")->move(this_object());
//END
    new("/std/diewarzau/obj/misc/skill_ring")->move(this_object());
    new("/std/diewarzau/obj/misc/power_stone")->move(this_object());
    ob = new("/std/diewarzau/obj/misc/power_stone");
    ob->set_max(100);
    ob->move(this_object());
    new("/std/diewarzau/obj/misc/power_stone")->move(this_object());
    ob = new("/std/diewarzau/obj/misc/power_stone");
    ob->set_max(500);
    ob->set_value(100000);
    ob->move(this_object());
	ob = new("/std/diewarzau/obj/misc/power_stone");
    ob->set_max(1000);
    ob->set_value(200000);
    ob->move(this_object());
    new("/std/diewarzau/obj/misc/spell_scroll")->move(this_object());
    new("/std/diewarzau/obj/misc/small_vial")->move(this_object());    
  }
}

void finish_deliver(object bob) {
  if(bob)
    message("info", "Karsten says in Common: It's all here now.",
            environment(bob));
  return;
}
