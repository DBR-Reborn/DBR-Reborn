//berserker_blade.c coder: Byon
#include <std.h>
inherit WEAPON;

void create() {
   mixed str;
   ::create();
   set_name("berserker blade");
   set("id", ({"berserker blade", "blade", "sword"}) );
   set("short", "Berserker Blade");
   set("long",
   "This huge sword's length looks like it was made for a dwarf but the "
   "width and proportions would challenge any but the most skilled and "
   "strong men."
   );
   set_weight(25);
   set_value(0);
   set_type("blade");
   set_verb("blast");
   set_wc(30, "cold");
   set_wc(65, "cutting");
   set_wc(30, "electricity");
   set_wc(30, "plasma");
   set_wc(60, "impaling");
   set_wc(30, "fire");
   set_wc(30, "aether");
   set_wc(30, "vacuum");
   set_wc(30, "disruption");
   set_wc(30, "speed");
   set_wc(30, "psychic");
   set_wc(60, "crushing");
   set_wc(30, "infernal");
   set_ac(5);
   set_property("no add quality", 1);
   set_property("no decay", 1);
   set_quality(9);
   set_wield("The huge sword quivers as you wield it.");
   set_unwield("You feel drained as you unwield the mighty weapon.");
   set_material("metal/neorolite");
}
