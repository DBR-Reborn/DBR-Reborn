#include "a1.h"
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room_any";

void create() {

  ::create();

  set("short", "Global %^YELLOW%^ALL%^RESET%^ skills");
  set("long", "This is the room that you can train Global %^YELLOW%^ALL%^RESET%^ skills.\n");

    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
  
  //  The following line is VERY, VERY important.
    set_join_room("/d/damned/guilds/join_rooms/child_join");

    add_exit("/d/daybreak/room/N1", "out");
    add_exit("/d/1tlny/spell_rooms/spell_room_all", "west");
    add_exit(PATH+"skill_room_combat", "down");

//NEW
add_skill("demonic preparation", 1);
add_skill("woodwork armour", 1);
add_skill("woodwork weapon", 1);
add_skill("repair wood weapon", 1);


add_skill("aether lore", 1);
add_skill("air lore", 1);
add_skill("appraisal", 1);
add_skill("assassination", 1);
add_skill("assassinations", 1);
add_skill("assassin's desire", 1);
add_skill("assassin's magic", 1);
add_skill("attack", 1);
add_skill("axe", 1);

//add_skill("backhand smash", 1);
add_skill("back stab", 1);
add_skill("balance weapon", 1);
add_skill("bash lock", 1);
add_skill("blacksmith", 1);
add_skill("blade", 1);
add_skill("blade magic", 1);
add_skill("block", 1);
add_skill("blunt", 1);
add_skill("body alteration", 1);
add_skill("body block", 1);
add_skill("carpentry", 1);
add_skill("chaos lore", 1);
add_skill("chaos magic", 1);
add_skill("cold lore", 1);
add_skill("combat awareness", 1);
add_skill("combo", 1);
add_skill("communion", 1);
add_skill("compare", 1);
//add_skill("compare (copy)", 1);
add_skill("concentrate", 1);
add_skill("conjuration", 1);
add_skill("consider", 1);
add_skill("consider lock", 1);
//add_skill("control change", 1);
add_skill("control demon", 1);
add_skill("control undead", 1);
add_skill("create greater nexus", 1);
add_skill("create lesser nexus", 1);
add_skill("create master nexus", 1);
add_skill("dance of daggers", 1);
add_skill("dark lore", 1);
add_skill("dark will", 1);
add_skill("desert lore", 1);
add_skill("desert stealth", 1);
add_skill("desert survival", 1);
add_skill("detect magic", 1);
add_skill("detect trap", 1);
add_skill("disarm trap", 1);
add_skill("disguise", 1);
add_skill("dodge", 1);
add_skill("dual attack", 1);
add_skill("duel mastery", 1);
add_skill("earth lore", 1);
add_skill("electricity lore", 1);
add_skill("elemental focus", 1);
add_skill("elementalism", 1);
add_skill("elemental magic", 1);
add_skill("elemental power", 1);
add_skill("elite nether arts", 1);
add_skill("elite nether erudition", 1);
add_skill("empowerment", 1);
add_skill("enchantment", 1);
add_skill("energy manipulation", 1);
add_skill("engrave", 1);
//add_skill("eternal rage", 1);
add_skill("fast casting", 1);
add_skill("fire lore", 1);
add_skill("flail", 1);
add_skill("focus casting", 1);
add_skill("focused attack", 1);
add_skill("focus of elements", 1);
add_skill("forbidden fury", 1);
add_skill("forbidden nether arts", 1);


add_skill("forge armour", 1);
add_skill("forge weapon", 1);
add_skill("genie lore", 1);
add_skill("grand elemental gathering", 1);
add_skill("gravity lore", 1);
add_skill("herb lore", 1);
add_skill("hide in shadows", 1);
add_skill("ice lore", 1);
add_skill("illusionism", 1);
add_skill("inertia lore", 1);
add_skill("inscribe aetha", 1);
add_skill("inscribe aether", 1);
add_skill("inscribe aldara zet", 1);
add_skill("inscribe anck athin", 1);
add_skill("inscribe colda", 1);
add_skill("inscribe colder", 1);
add_skill("inscribe crusha", 1);
add_skill("inscribe crusher", 1);
add_skill("inscribe cutta", 1);
add_skill("inscribe cutter", 1);
add_skill("inscribe disrupta", 1);
add_skill("inscribe disrupter", 1);
add_skill("inscribe electricita", 1);
add_skill("inscribe electriciter", 1);
add_skill("inscribe fira", 1);
add_skill("inscribe firer", 1);
add_skill("inscribe harah lit", 1);
add_skill("inscribe holya", 1);
add_skill("inscribe holyer", 1);
add_skill("inscribe impacta", 1);
add_skill("inscribe impacter", 1);
add_skill("inscribe impala", 1);
add_skill("inscribe impaler", 1);
add_skill("inscribe inferna", 1);
add_skill("inscribe inferner", 1);
add_skill("inscribe lifta", 1);
add_skill("inscribe malsa bonnes", 1);
add_skill("inscribe malsa koren", 1);
add_skill("inscribe malsa sen zora", 1);
add_skill("inscribe malsa xen", 1);
add_skill("inscribe paree", 1);
add_skill("inscribe plasa", 1);
add_skill("inscribe plasmer", 1);
add_skill("inscribe preciser", 1);
add_skill("inscribe quickness", 1);
add_skill("inscribe stressa", 1);
add_skill("inscribe stresser", 1);
add_skill("inscribe strika", 1);
add_skill("inscribe striker", 1);
add_skill("inscribe unholya", 1);
add_skill("inscribe unholyer", 1);
add_skill("inscribe vacumma", 1);
add_skill("inscribe vacummer", 1);
add_skill("inscribe xen mora", 1);
add_skill("inscribe zalm lit", 1);
add_skill("install lock", 1);
add_skill("instant casting", 1);
add_skill("invisibility art", 1);
add_skill("invisible walk", 1);
add_skill("invulnerability mastery", 1);
add_skill("jump kick", 1);
add_skill("kick", 1);
add_skill("knee", 1);
add_skill("knife", 1);
add_skill("lay on hands", 1);
add_skill("leather craft", 1);
add_skill("lightning strike", 1);
add_skill("limb breaker", 1);
add_skill("lock smithing", 1);
//add_skill("lore skill", 1);
add_skill("lumberjack", 1);
add_skill("magery", 1);
add_skill("magic mastery", 1);
add_skill("major nether arts", 1);
add_skill("major nether erudition", 1);
add_skill("martial arts", 1);
add_skill("mass properties", 1);
add_skill("master walk", 1);
add_skill("melee", 1);
add_skill("minor nether arts", 1);
add_skill("minor nether erudition", 1);
add_skill("mold circular ring", 1);
add_skill("mortal attack", 1);
add_skill("nature lore", 1);
add_skill("necromancy", 1);
add_skill("nether arts", 1);
add_skill("nether erudition", 1);
add_skill("nether magic", 1);
add_skill("nexus lore", 1);
add_skill("offhand training", 1);
add_skill("orb manipulation", 1);
add_skill("owedquar's weapon", 1);
add_skill("owedquar's will", 1);
add_skill("pain strike", 1);
add_skill("paralysis magic", 1);
add_skill("parasitic fixation", 1);
add_skill("parry", 1);
add_skill("peek", 1);
add_skill("perception", 1);
add_skill("phase", 1);
add_skill("pick locks", 1);
add_skill("pick pocket", 1);
add_skill("plasma lore", 1);
add_skill("poison lore", 1);

//add_skill("power slam", 1);
add_skill("prayer", 1);
add_skill("prayer to akhamshish", 1);

add_skill("prepare corpse", 1);
add_skill("prepare item", 1);
add_skill("prospecting", 1);
add_skill("repair weapon", 1);
add_skill("resist stun", 1);
add_skill("reverse punch", 1);
add_skill("reverse stroke", 1);
add_skill("rune lore", 1);
add_skill("shadow", 1);
add_skill("shadow lore", 1);
add_skill("shadow target", 1);
add_skill("shadow walk", 1);
add_skill("shield bash", 1);
add_skill("skin corpse", 1);
add_skill("sling", 1);
//add_skill("sneak attack", 1);
add_skill("sorcery", 1);
add_skill("soul channel", 1);
add_skill("spell sense", 1);
add_skill("stab", 1);
add_skill("stalk", 1);
add_skill("steal", 1);
add_skill("stealth", 1);
add_skill("stealth mastery", 1);
add_skill("strike mastery", 1);
add_skill("strong arm", 1);
//add_skill("sweep", 1);
add_skill("swiftness", 1);
add_skill("swimming", 1);
add_skill("telepathy", 1);

add_skill("thrown", 1);
add_skill("time lore", 1);
add_skill("trade lore", 1);
//add_skill("traerforge armour", 1);
add_skill("true strike", 1);
add_skill("two handed blade", 1);
add_skill("two handed blunt", 1);
add_skill("two handed flail", 1);
add_skill("two handed polearm", 1);
add_skill("two handed staff", 1);
//add_skill("undead suggestion", 1);
add_skill("unseen mime", 1);
add_skill("vacid lore", 1);
add_skill("vibrating palm", 1);
add_skill("vision magic", 1);
add_skill("water lore", 1);
add_skill("whirlwind attack", 1);
add_skill("wind lore", 1);
add_skill("black magic", 1);

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

