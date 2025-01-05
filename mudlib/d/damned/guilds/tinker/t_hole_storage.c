#include <std.h>

inherit "/std/vault";


void create() {
  set_short("You probably shouldn't be here");
  set_long("This is the store room for the special room Shop.");
  add_exit("/d/damned/guilds/tinker/t_hole", "south");
  set_door("iron door", "/d/damned/guilds/tinker/t_hole", "south",
    "special shop store");
  set_open("iron door", 0);
  set_locked("iron door", 1);
  set_property("light", 2);
  set_property("indoors", 1);
  set_property("storage room", 1);
  this_object()->reset();
  return;
}

void remove_all(object *inv) {
  int i;

  i = sizeof(inv);
  while(i--) if(inv[i] && !living(inv[i]) && environment(inv[i]) == this_object()) inv[i]->remove();
  return;
}

void reset() {
  object *inv, ob;
  int i;

  seteuid(getuid());
  if(query_reset_number()%4 < 1) {
  inv = all_inventory(this_object());
  call_out("remove_all", 5, inv);
  }
for(i = 1; i <=20; i++) {
if(i < 11) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/steel");
	ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/steel");
	ob->move(this_object());
}
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/iron");
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/iron");
      ob->move(this_object());

  if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/laen");
        ob->set_value(30000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/laen");
        ob->set_value(30000);
      ob->move(this_object());
      }
  if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/mithril");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/mithril");
        ob->set_value(20000);
      ob->move(this_object());
      }
 if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/elrodnite");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/elrodnite");
        ob->set_value(20000);
      ob->move(this_object());
      }

 if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/inniculmoid");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/inniculmoid");
        ob->set_value(20000);
      ob->move(this_object());
      }
 if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/platnite");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/platnite");
        ob->set_value(20000);
      ob->move(this_object());
      }
 if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/raysorite");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/raysorite");
        ob->set_value(20000);
      ob->move(this_object());
      }

 if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/catoetine");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/catoetine");
        ob->set_value(20000);
      ob->move(this_object());
      }
 if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/javednite");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/javednite");
        ob->set_value(20000);
      ob->move(this_object());
      }
 if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/davistone");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/davistone");
        ob->set_value(20000);
      ob->move(this_object());
      }
 if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/mcgrail");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/mcgrail");
        ob->set_value(20000);
      ob->move(this_object());
      }
 if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/boernerine");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/boernerine");
        ob->set_value(20000);
      ob->move(this_object());
      }
/*
 if(i <= 1) {
      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/mabril");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/mabril");
        ob->set_value(20000);
      ob->move(this_object());
      }
if(i <= 1) {

      ob = new("/std/diewarzau/obj/misc/weapon_blank");
      ob->set_material("metal/iysaughton");
        ob->set_value(20000);
      ob->move(this_object());
      ob = new("/std/diewarzau/obj/misc/armour_blank");
      ob->set_material("metal/iysaughton");
        ob->set_value(20000);
      ob->move(this_object());
      }
*/
  }
  return;
}
