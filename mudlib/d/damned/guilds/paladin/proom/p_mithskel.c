/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
#define PATH "/d/camps/catacombs/rooms/"
#define MON_PATH "/d/camps/catacombs/mon/"
#define MISC_PATH "/d/camps/catacombs/misc/"
#define ARMOR_PATH "/d/camps/catacombs/armor/"
#define WEAP_PATH "/d/camps/catacombs/weapon/"
inherit MONSTER;

void init() {
    :: init();
    add_action("no","east");
    return;
}
 
void create() {
   object ob;
 
   ::create();
   set_name("Infernal skeleton");
   set("id", ({"skeleton", "infernal skeleton"}) );
   set_level(99);
   set_max_hp(50000*4);
   set_hp(50000*4);
   set_overall_ac(55555);
    set("aggressive", 1);
   set("short", "Infernal skeleton");
   set("long",
   "Before you stands a human skeleton whose bones appear to be coated "
   "with Devil Fire.  Its metal frame shines in the faint torchlight.  As "
   "it moves, you hear its metal limbs scrape against each other.  This "
   "creature is obviously the product of very evil magic."
   );
   set("race", "undead");
   set_gender("neuter");
   set_money("mithril", random(60)+60);
   set_body_type("human");
   
    //set_skill("perception",random(80)+100);
     set_skill("martial arts",99*10);
     set_skill("attack",99*10);
    set_skill("dodge",99*9);
    set_skill("parry",99*9);
   //set_skill("sweep",99*11);
    //set_skill("parry",random(80)+200);
    set_skill("melee",99*11);
    set_skill("resist stun", 99*10);  
   set_property("enhance criticals",-100);
   set_property("magic resistance", 1000);

   set_melee_damage(([ "infernal" : 5555555 ]));
   //set_melee_damage(([ "z1" : 5555555 ]));

//set_auto_crits(([ "z1" : 100000 ] )); 

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
    ob = new("/std/spells/shadows/ele_pres_shad");
    ob->set_power(3);
    ob->set_damage(({ "unholy", "fire" }));
    ob->set_shadow_name("Skeleton Presence");
    ob->start_shadow(this_object(), 2000000000, "");

    ob = new("/std/spells/shadows/ele_pres_shad");
    ob->set_power(5);
    ob->set_damage(({ "infernal" }));
    ob->set_shadow_name("Skeleton Presence2");
    ob->start_shadow(this_object(), 2000000000, "");

    ob = new("/d/areas/beholders/spells/skeleton_shield.c");
    ob->set_damage_allowed(25000);
    ob->set_shadow_name("skeleton shield");
    ob->start_shadow(this_object(), 2000000000, "");

}

int no()
{
   if(archp(this_player())) return 0;
   if(this_player()->query_ghost()) return 0;
    message("blocking",
      "The Skeleton jumps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Skeleton blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}

int loot;
 
void die(object ob) {
   object ob1;

loot=(1+random(15));

if (loot == 1){ 
   ob = new("/std/diewarzau/obj/misc/ingot");
   ob->set_material("metal/eog");
   ob->set_weight(random(99)+20);
   ob->move(this_object());
}
if (loot == 2){ 
   ob = new("/std/diewarzau/obj/misc/ingot");
   ob->set_material("metal/eonmite");
   ob->set_weight(random(99)+20);
   ob->move(this_object());
}
else { 
   ob = new("/std/diewarzau/obj/misc/ingot");
   ob->set_material("metal/iysaughton");
   ob->set_weight(random(99)+20);
   ob->move(this_object());
}



/*
   ob1 = new("/std/diewarzau/obj/misc/weapon_blank");
   ob1->set_material("metal/iysaughton");
   ob1->move(find_object_or_load("/d/damned/guilds/paldain/proom/p_loot"));
*/
   ::die();
}

