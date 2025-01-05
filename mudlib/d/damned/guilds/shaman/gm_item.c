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

int take_me_off() {
    worn_by = 0;
    return 1;
}
  
create() {
    ::create();
    set("id", ({ "raven", "gmitem", "lidfino", "black raven" }));
    set_name("raven");
    set("short", "A Black Raven");
    set("long","This jet black raven sits on your shoulder. He will often make witty remarks about the weather. You wish you could be rid of this annoyance, but alas, his possessor is the master of the shamen, and that is a power no one could give away. You can wear him.");
    set_limbs(({"head"}));
    set_ac(50);
    set_ac(50, "holy");
    set_ac(50, "impact");
    set_weight(25);
    set_wear((: call_other,this_object(), "make_me_gm" :));
    set_remove((: call_other, this_object(), "take_me_off" :));
    set_enh_critical(-2);
    set_value(0);
    set_property("no save", 1);
   return;
}

int make_me_gm() {
object ob;

  seteuid(getuid());
  ob= new("d/damned/guilds/shaman/shaman_obj");
  ob->make_me_master(this_player());
  worn_by = environment();
  return 1;
}
