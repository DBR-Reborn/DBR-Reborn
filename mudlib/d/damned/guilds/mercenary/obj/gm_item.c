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
    set("id", ({ "robe", "merchant", "robe of the merchant federation" }));
     set_name("mercenary object");
     set_id(({ "guildmaster object", "mercenary object", "tattoo" }) );
     set("short", "The Tattoo of the Mercenary Guildmaster");
     set("long", "Type 'help guildmaster' for instructions.");
    set_limbs(({"torso", "left arm", "right arm", "left leg", "right leg", "head"}));
    set_ac(50);
    set_ac(25, "impact");
    set_ac(25, "crushing");
    set_ac(25, "cutting");
    set_ac(25, "impaling");
    set_weight(25);
    set_wear((: call_other,this_object(), "make_me_gm" :));
    set_enh_critical(-2);
    set_value(0);
    set_property("no save", 1);
   return;
}

int make_me_gm() {
object ob;

  seteuid(getuid());
    ob=new("d/damned/guilds/mercenary/obj/merc_obj");
  ob->make_me_master(this_player());
  return 1;
}
