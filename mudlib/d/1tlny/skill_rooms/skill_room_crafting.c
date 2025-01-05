#include "a1.h"
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room_any";

void create() {

  ::create();

  set("short", "Global %^YELLOW%^CRAFTING%^RESET%^ skills");
  set("long", "This is the room that you can train Global %^YELLOW%^CRAFTING%^RESET%^ skills.\n");

    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
  
  //  The following line is VERY, VERY important.
    set_join_room("/d/damned/guilds/join_rooms/child_join");

    add_exit(PATH+"skill_room_combat", "up");
    add_exit(PATH+"skill_room_lore", "down");

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

add_skill("forge armour", 2);
add_skill("forge weapon", 2);
add_skill("blacksmith", 2);
add_skill("balance weapon", 2);
add_skill("prospecting", 2);
add_skill("repair weapon", 2);
add_skill("repair wood weapon", 2);

add_skill("skin corpse", 3);
add_skill("leather craft", 3);

add_skill("lumberjack", 3);
add_skill("carpentry", 3);

add_skill("install lock", 4);
add_skill("lock smithing", 4);
add_skill("bash lock", 4);
add_skill("consider lock", 4);
add_skill("pick locks", 4);


  
  return;
}

