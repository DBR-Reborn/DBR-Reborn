#include <move.h>
#include <std.h>

inherit "/std/armour";
inherit AUTOLOAD;
  
void create() {
    ::create();
    set("id", ({ "ankh", "necklace" }));
    set("short", "The Ankh of the War Priest");
    set("long",
"This ornate amulet can provide protection from fire and cold.");
    set_limbs(({"head"}));
    set_weight(25);
    set_ac(30);
    set_ac(60, "disruption");
    set_wear((: call_other,this_object(), "make_me_gm" :));
    set_enh_critical(-1);
    set_value(50000);
   return;
}

int query_always_keep() { return 1; }
int make_me_gm() {
object ob;

   if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     write("%^BOLD%^Only war-priests of level 16 or higher may use this item.");
    return 0;
}

   if((string)this_player()->query_class() != "war-priest") {
      write("%^BOLD%^Only war-priests may use this item.");
    return 0;
  }

  seteuid(getuid());
  ob= new("d/damned/guilds/war-priest/war-priest_obj");
  ob->make_me_master(this_player());
  return 1;
}


