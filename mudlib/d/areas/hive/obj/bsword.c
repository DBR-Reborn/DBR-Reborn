//  Wizard:   Myrddin
//  Weapon:  Steel Broadsword
//  File:        bsword.c
//  June 97

#include <std.h>
inherit WEAPON;

void create() {
   ::create();
   set_name("broadsword");
   set("id", ({ "broadsword", "broad sword", "sword"}) );
   set("short", "broadsword");
   set("long",
   "The broadsword is durable and very well made."
);
   set_weight(200);
   set_value(750);
   set_type("blade");
   set_wc(15, "cutting");
   set_ac(5);
   set_quality(5);
   set_hit_bonus(10);
   set_parry_bonus(-10);
   set_material("metal/steel");
}
