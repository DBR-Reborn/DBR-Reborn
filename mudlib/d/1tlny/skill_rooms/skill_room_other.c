#include "a1.h"
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room_any";

void create() {

  ::create();

  set("short", "Global %^YELLOW%^OTHER%^RESET%^ skills");
  set("long", "This is the room that you can train Global %^YELLOW%^OTHER%^RESET%^ skills.\n");

    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
  
  //  The following line is VERY, VERY important.
    set_join_room("/d/damned/guilds/join_rooms/child_join");

    add_exit(PATH+"skill_room_lore", "up");


//NEW
add_skill("demonic preparation", 1);
add_skill("woodwork armour", 1);
add_skill("woodwork weapon", 1);


add_skill("appraisal", 1);
add_skill("assassination", 1);
add_skill("assassinations", 1);
add_skill("assassin's desire", 1);
add_skill("assassin's magic", 1);
//add_skill("backhand smash", 1);
add_skill("blade magic", 1);
add_skill("body alteration", 1);
add_skill("chaos magic", 1);
add_skill("communion", 1);
add_skill("compare", 1);
add_skill("concentrate", 1);
add_skill("conjuration", 1);
add_skill("consider", 1);
//add_skill("control change", 1);
add_skill("control demon", 1);
add_skill("control undead", 1);
add_skill("create greater nexus", 1);
add_skill("create lesser nexus", 1);
add_skill("create master nexus", 1);
add_skill("dance of daggers", 1);
add_skill("dark will", 1);
add_skill("desert stealth", 1);
add_skill("desert survival", 1);
add_skill("detect magic", 1);
add_skill("detect trap", 1);
add_skill("disarm trap", 1);
add_skill("disguise", 1);
add_skill("duel mastery", 1);

add_skill("trade lore", 1);

add_skill("elite nether arts", 1);
add_skill("elite nether erudition", 1);
add_skill("empowerment", 1);
add_skill("enchantment", 1);
add_skill("energy manipulation", 1);
add_skill("engrave", 1);
//add_skill("eternal rage", 1);
add_skill("fast casting", 1);
add_skill("focus casting", 1);
add_skill("focused attack", 1);

add_skill("forbidden fury", 1);
add_skill("forbidden nether arts", 1);

add_skill("hide in shadows", 1);
add_skill("illusionism", 1);
add_skill("instant casting", 1);
add_skill("invisibility art", 1);
add_skill("invisible walk", 1);
add_skill("invulnerability mastery", 1);
add_skill("lay on hands", 1);
//add_skill("lore skill", 1);
add_skill("magery", 1);
add_skill("magic mastery", 1);
add_skill("major nether arts", 1);
add_skill("major nether erudition", 1);
add_skill("mass properties", 1);
add_skill("master walk", 1);
add_skill("minor nether arts", 1);
add_skill("minor nether erudition", 1);
add_skill("mold circular ring", 1);
add_skill("necromancy", 1);
add_skill("nether arts", 1);
add_skill("nether erudition", 1);
add_skill("nether magic", 1);
add_skill("orb manipulation", 1);
add_skill("owedquar's weapon", 1);
add_skill("owedquar's will", 1);
add_skill("pain strike", 1);
add_skill("paralysis magic", 1);
add_skill("parasitic fixation", 1);
add_skill("peek", 1);
add_skill("perception", 1);
add_skill("phase", 1);
add_skill("pick pocket", 1);
//add_skill("power slam", 1);
add_skill("prayer", 1);
add_skill("prayer to akhamshish", 1);
add_skill("prepare corpse", 1);
add_skill("prepare item", 1);
add_skill("shadow", 1);
add_skill("shadow target", 1);
add_skill("shadow walk", 1);
//add_skill("sneak attack", 1);
add_skill("sorcery", 1);
add_skill("soul channel", 1);
add_skill("spell sense", 1);
add_skill("stalk", 1);
add_skill("steal", 1);
add_skill("stealth", 1);
add_skill("stealth mastery", 1);
add_skill("strike mastery", 1);
//add_skill("sweep", 1);
add_skill("swimming", 1);
add_skill("telepathy", 1);
//add_skill("traerforge armour", 1);
//add_skill("undead suggestion", 1);
add_skill("unseen mime", 1);
add_skill("vibrating palm", 1);
add_skill("vision magic", 1);
/*
add_skill("wizforge armour", 1);
add_skill("wizforge weapon", 1);
add_skill("wizinscribe aldara zet", 1);
add_skill("wizinscribe harah lit", 1);
add_skill("wizinscribe malsa bonnes", 1);
add_skill("wizinscribe malsa koren", 1);
add_skill("wizinscribe malsa sen zora", 1);
add_skill("wizinscribe malsa xen", 1);
add_skill("wizinscribe xen mora", 1);
add_skill("wizinscribe zalm lit", 1);
add_skill("wizleather craft", 1);
add_skill("wiztestforge armour", 1);
add_skill("wiztestforge weapon", 1);
add_skill("wizzalm lit", 1);
*/
//add_skill("woodland lore", 1);
//add_skill("woodland stealth", 1);
//add_skill("worship of k'thach", 1);
add_skill("zalm lit", 1);


  
  return;
}

