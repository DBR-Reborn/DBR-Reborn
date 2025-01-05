// Agulz - Arch-mage Spell trainer
// Wiztower
// Coded by Glitch for DBR 06-25-00

#include <std.h>

inherit MONSTER;

void create(){
   ::create();
   
   set_name("Agulz");
   set("id", ({ "agulz", "trainer", "mage", "arch-mage" }) );
   set_level(75);
   set("short", "Agulz");
   set("long", "Agulz the Arch-mage is a ancient human with eyes that seem to see all and know much.");
   set("race", "human");
   set_gender("male");
   set_alignment(100);
   set_money("mithril", (random(100)+275));
   set_body_type("human");
   set_wielding_limbs(({"right hand", "left hand"}));
   set_skill("melee", 300);
   set_skill("blade", 300);
   set_skill("attack", 300);
   set_emotes(20, ({ "Agulz says, 'All these spells, one must do what I want.'",
      "Agulz shuffles some scrolls around searching for something.",
      "Agulz mutters something under his breath.",
      "Agulz moves about the room searching for something.",
      }), 0);
}
