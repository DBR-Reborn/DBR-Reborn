#include <move.h>
#include <std.h>

inherit "/std/armour";
inherit AUTOLOAD;

int query_always_keep() { return 1; }
  
create() {
    ::create();
    set("id", ({ "amulet" }));
    set_name("amulet");
    set("short", "The Amulet of Nethermancers");
    set("long",
"This amulet is fashioned in the shape of an ornate silver skull with "
"red rubies set in it's eyes.");
    set_limbs(({"head"}));
    set_weight(25);
    set_ac(40, "cold");
    set_wear((: call_other,this_object(), "make_me_gm" :));
    set_ac(30, "disruption");
    set_enh_critical(-2);
    set_value(100000);
   return;
}

int make_me_gm() {
object ob;

   if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     write("%^BOLD%^Only nethermancers of level 16 or higher may use this item.");
    return 0;
}

   if((string)this_player()->query_class() != "nethermancer") {
      write("%^BOLD%^Only nethermancers may use this item.");
    return 0;
  }

  seteuid(getuid());
  ob= new("d/damned/guilds/nethermancer/nethermancer_obj");
  ob->make_me_master(this_player());
  return 1;
}
