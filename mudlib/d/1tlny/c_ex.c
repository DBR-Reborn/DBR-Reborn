//TLNY2020 Example of basic creatures
 
#include <std.h>

inherit MONSTER;
 
void create() {
   object ob;
int zlevel;
   ::create();

    zlevel = (5+random(5));

   set_level(zlevel);
   set_overall_ac(zlevel+5);
   set_property("magic resistance", zlevel/2);
   set_skill("resist stun", zlevel);
   set_melee_damage(([ "crushing" : zlevel,"cutting" : zlevel ]));

   set_money("silver", random(100)+5*zlevel); 
   set_name("Infernal skeleton");
   set("id", ({"skeleton", "example skeleton"}) );
   set("long","Before you stands a human skeleton whose bones appear to be coated "
   "with Devil Fire.");
   set_short("["+zlevel+"]skeleton");    

   set("race", "undead");
   set_body_type("human");
   set_gender("neuter");
   set_alignment(-100);
   set("aggressive", (: call_other, this_object(), "no_other_monsters" :));
    //set("aggressive", 1);

    set_stats("strength", 50 + 1*zlevel);
    set_stats("dexterity", 50 + 1*zlevel);
    set_stats("constitution", 50 + 1*zlevel);
    set_stats("wisdom", 50 + 1*zlevel);
    set_stats("intelligence", 50 + 1*zlevel);
    set_stats("charisma", 50 + 1*zlevel);
/*
    set_skill("melee", 50 + 1*zlevel);
    set_skill("attack", 50 + 1*zlevel);
    set_skill("defense", 50 + 1*zlevel);
    set_skill("dodge", 50 + 1*zlevel);
*/   
/*  
    ob = new("/d/damned/virtual/broad-sword_6.weapon");
    ob->move(this_object());   
    ob->set_wc(10 ,"fire");
    ob->set_wc(5 ,"cold");
    ob->set_wc(5 ,"electricity");
    ob = new("/d/damned/virtual/large-shield.armour");
    ob->move(this_object());    
    ob->set_ac(25);
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob->move(this_object());    
    ob->set_ac(25);
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob->move(this_object());    
    ob->set_ac(25);
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());    
    ob->set_ac(25);
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());    
    ob->set_ac(25);
    ob = new("/d/damned/virtual/great-helm.armour");
    ob->move(this_object());    
    ob->set_ac(25);
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob->move(this_object());    
    ob->set_ac(25);
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob->move(this_object());    
    ob->set_ac(25);
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob->move(this_object());    
    ob->set_ac(25);
    force_me("equip");
*/
}

int loot;

void die(object ob) {
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
loot=(1+random(10));

if (loot == 1){ 
    ob = new("/d/damned/virtual/great-helm.armour");
   ob->move(this_object());
    //ob->set_ac(35);
    ob->set_material("metal/iron");
}
else 
if (loot == 2) { 
    ob = new("/d/damned/virtual/gauntlet.armour");
   ob->move(this_object());
    //ob->set_ac(35);
    ob->set_material("metal/iron");
}
else
if (loot == 3) {   
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob->move(this_object());    
    //ob->set_ac(35);
    ob->set_material("metal/iron");
}
else
if (loot == 4) {  
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob->move(this_object());    
    //ob->set_ac(35);
    ob->set_material("metal/iron");
}
else
if (loot == 5) {  
    ob = new("/d/damned/virtual/large-shield.armour");
    ob->move(this_object());    
    //ob->set_ac(35);
    ob->set_material("metal/iron");
}
else
if (loot == 6) {    
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob->move(this_object());    
    //ob->set_ac(35);
    ob->set_material("metal/iron");
}
else
if (loot == 7) {   
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());    
    //ob->set_ac(35);
    ob->set_material("metal/iron");
}
else {
 ob = new("/std/diewarzau/obj/misc/ingot");
   ob->set_material("metal/boernerine");
   ob->move(this_object());
}
 
   ::die();
}

//Aggressive code to only kill payers see below line above
//set("aggressive", (: call_other, this_object(), "no_other_monsters" :));

int no_other_monsters(object who) {
  if(who->is_player()) {
    if(who->query_invis()) { return 0; }
    if(who->query_hiding() >= 70)  { return 0; }
    if(who->query_stealth() >= 80) { return 0; }
   this_object()->kill_ob(who,0);
    return 1;
  }
  else return 0;
}
