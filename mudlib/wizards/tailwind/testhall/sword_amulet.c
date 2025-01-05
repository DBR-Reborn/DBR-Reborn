#include <move.h>
#include <std.h>

inherit "/std/armour";
inherit AUTOLOAD;

static private object worn_by;

int query_always_keep() { return 1; }
int query_worn();

int query_worn() {
  if(worn_by && worn_by == environment()) return 1;
  return 0;
}
  
create() {
    ::create();
    set("id", ({ "amulet", "sword amulet", "shield amulet", "sword and shield amulet" }));
    set_name("amulet");
    set("short", "Amulet of the Sword and Shield");
    set("long","Two small crossed swords hanging from a chain, the symbol of the royal-infantry guild");
    set_limbs(({"torso"}));
    set_weight(25);
    set_ac(10);
    set_wear((: call_other,this_object(), "make_me_gm" :));
    set_enh_critical(-1);
    set_value(0);
   return;
}

int make_me_gm() {
object ob;

  seteuid(getuid());
  ob= new("d/damned/guilds/royal-infantry/ri_obj");
  ob->make_me_master(this_player());
  return 1;
}
