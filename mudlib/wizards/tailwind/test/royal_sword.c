/* Weapon coded by Duridian for DarkeMud. */
/* Stolen by TW for DBR! */

#include <std.h>
inherit WEAPON;

void create() {
    mixed str;
    ::create();
    set_name("royal sword");
    set("id", ({"royal sword", "sword", "royal"}) );
    set("short", "A Royal Sword");
    set("long",
   "The Royal Sword is the standard issue weapon for Royal-Infantry troops. "+
   "It's not particularly impressive, but does have a stout blade and a "+
   "nice-looking gold(-plated) hilt."
   );
   set_weight(30);
   set_value(0);

set_type("knife");
   set_wc(20, "impaling");
   set_wc(25, "cutting");
   set_wc(10, "royal");
   set_ac(2);
   set_property("no add quality", 1);
   set_property("no decay", 1);
   set_quality(6);
   set_material("metal/iron");
}

void init(){
   ::init();
   set_wield((: call_other, this_object(), "weapon_wield" :));
   set_unwield((: call_other, this_object(), "weapon_unwield" :));
}

int weapon_wield() {
    if((string)this_player()->query_class() != "royal-infantry"){
      write("You attempt to wield the Royal Sword, but you find you cannot. The sword sends a strong shock to you to reinforce this rejection.");
      return 0;
    } 
write("You wield the Royal Sword, and the power of the Kingdom flows through your very soul.");
    return 1;
}

int weapon_unwield() {
    write("You feel a bit less royal as you unwield the sword.");
    return 1;
}
