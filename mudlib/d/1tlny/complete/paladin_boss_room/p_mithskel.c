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
   set_name("Infernal skeleton");
   set("id", ({"skeleton", "Infernal skeleton"}) );
   set_level(60);
  // set_property("enhance criticals",-5);
 //  set_max_hp(50000);
 //  set_hp(50000);
   set_overall_ac(600);
    set("aggressive", (: call_other, this_object(), "no_other_monsters" :));
   set("short", "Infernal skeleton");
   set("long",
   "Before you stands a human skeleton whose bones appear to be coated "
   "with Devil Fire.  Its metal frame shines in the faint torchlight.  As "
   "it moves, you hear its metal limbs scrape against each other.  This "
   "creature is obviously the product of very evil magic."
   );
   set("race", "undead");
   set_gender("neuter");
   set_money("mithril", random(100)+200);
   set_body_type("human");
   
    //set_skill("perception",random(80)+100);
    //set_skill("attack",random(80)+100);
    //set_skill("dodge",random(80)+200);
    //set_skill("parry",random(80)+200);
    //set_skill("melee",random(80)+250);
    set_skill("resist stun", 300);  
   set_property("enhance criticals",-5);
   set_property("magic resistance", 300);

   set_melee_damage(([ "infernal" : 200  ]));
   set_emotes(5, ({
                   "The skeleton's Infernal bones shine in the torchlight.",
                   "The Infernal skeleton turns toward you and watches you carefully.",
                   "The Infernal's bones clang loudly against the stone as it walks about.",
                   }), 0);
   set_achats(30, ({
                    "The skeleton swings violently at empty space.",
                    "The skeleton's bones flash brilliantly as the monster fights.",
                  }) );
   //ob = new(WEAP_PATH+"cutlass");
   //ob->move(this_object());
   //ob->set_wc(10, "infernal");
   //ob->add_poisoning(random(10));
   //force_me("wield cutlass in right hand");
/*   
 ob = new("/d/damned/virtual/large-shield.armour");
    ob->move(this_object());    
    ob->set_ac(200);
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob->move(this_object());    
    ob->set_ac(500);
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob->move(this_object());    
    ob->set_ac(200);
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());    
    ob->set_ac(200);
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());    
    ob->set_ac(200);
    ob = new("/d/damned/virtual/great-helm.armour");
    ob->move(this_object());    
    ob->set_ac(200);
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob->move(this_object());    
    ob->set_ac(200);
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob->move(this_object());    
    ob->set_ac(200);
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob->move(this_object());    
    ob->set_ac(200);
*/
   // force_me("equip");
}

int loot;
 
void die(object ob) {
   object ob1;

loot=(1+random(3));

if (loot == 1){ 
   ob = new("/std/diewarzau/obj/misc/ingot");
   ob->set_material("metal/eog");
   ob->move(this_object());
}
else { 
   ob = new("/std/diewarzau/obj/misc/ingot");
   ob->set_material("metal/eonmite");
   ob->move(this_object());
}



/*
   ob1 = new("/std/diewarzau/obj/misc/weapon_blank");
   ob1->set_material("metal/iysaughton");
   ob1->move(find_object_or_load("/d/damned/guilds/paldain/proom/p_loot"));
*/
   ::die();
}

