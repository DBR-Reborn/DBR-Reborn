/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
#define PATH "/d/camps/catacombs/rooms/"
#define MON_PATH "/d/camps/catacombs/mon/"
#define MISC_PATH "/d/camps/catacombs/misc/"
#define ARMOR_PATH "/d/camps/catacombs/armor/"
#define WEAP_PATH "/d/camps/catacombs/weapon/"
inherit MONSTER;
 
void create() {
   object ob;
 
   ::create();
   set_name("Eog skeleton");
   set("id", ({"skeleton", "Eog skeleton"}) );
   set_level(50);
   set_overall_ac(5000);
   set_max_hp(20000);
   set_hp(20000);
   set("short", "Eog skeleton");
   set("long",
   "Before you stands a human skeleton whose bones appear to be coated "
   "with Eog.  Its metal frame shines in the faint torchlight.  As "
   "it moves, you hear its metal limbs scrape against each other.  This "
   "creature is obviously the product of very evil magic."
   );
   set("race", "undead");
   set_gender("neuter");
   set_money("mithril", random(100)+200);
   set_body_type("human");
   set_emotes(5, ({
                   "The skeleton's Eog bones shine in the torchlight.",
                   "The Eog skeleton turns toward you and watches you carefully.",
                   "The Eog's bones clang loudly against the stone as it walks about.",
                   }), 0);
   set_achats(30, ({
                    "The skeleton swings violently at empty space.",
                    "The skeleton's bones flash brilliantly as the monster fights.",
                  }) );
   ob = new(WEAP_PATH+"cutlass");
   ob->move(this_object());
   ob->set_wc(10, "hlight");
   ob->add_poisoning(random(100));
   force_me("wield cutlass in right hand");
}
 
