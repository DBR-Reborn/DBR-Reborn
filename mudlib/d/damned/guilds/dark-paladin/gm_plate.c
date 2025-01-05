#include <move.h>
#include <std.h>

inherit "/std/armour";
inherit AUTOLOAD;
  
create() {
    ::create();
    set("id", ({ "plate", "breastplate" }));
    set("short", "The Dark Breastplate of Darkness");
    set("long",
"This is a pitch back breastplate that gives off an aura of power. "
"The dark-paladin who wears this is named Guildmaster of the Dark-Paladins.");
    set_limbs(({"torso"}));
   set_weight(400);
    set_ac(40);
    set_wear((: call_other,this_object(), "make_me_gm" :));
    set_ac(50, "disruption");
    set_enh_critical(-1);
    set_value(100000);
   return;
}

int query_always_keep() { return 1; }

int make_me_gm() {
object ob;

if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     write("%^BOLD%^Only Dark-Paladins of level 16 or higher may use this item.");
    return 0;
}

   if((string)this_player()->query_class() != "dark-paladin") {
      write("%^BOLD%^Only Dark-Paladins may use this item.");
    return 0;
  }

  seteuid(getuid());
  ob= new("d/damned/guilds/dark-paladin/dark-paladin_obj");
  ob->make_me_master(this_player());
  return 1;
}


