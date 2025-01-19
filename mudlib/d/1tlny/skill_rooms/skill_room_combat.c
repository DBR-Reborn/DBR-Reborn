#include "a1.h"
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room_any";

void create() {

  ::create();

  set("short", "Global %^YELLOW%^COMBAT%^RESET%^ skills");
  set("long", "This is the room that you can train Global %^YELLOW%^COMBAT%^RESET%^ skills.\n");

    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
  
  //  The following line is VERY, VERY important.
    set_join_room("/d/damned/guilds/join_rooms/child_join");

    add_exit(PATH+"skill_room_all", "up");
    add_exit(PATH+"skill_room_crafting", "down");

add_skill("attack", 1);
add_skill("axe", 1);
add_skill("back stab", 1);
add_skill("blade", 1);
add_skill("block", 1);
add_skill("blunt", 1);
add_skill("body block", 1);
add_skill("combat awareness", 1);
add_skill("combo", 1);  //Whirlwind
add_skill("dodge", 1);
add_skill("dual attack", 1);
add_skill("flail", 1);
add_skill("jump kick", 1);
add_skill("kick", 1);
add_skill("knee", 1);
add_skill("knife", 1);
add_skill("limb breaker", 1);
add_skill("martial arts", 1);
add_skill("melee", 1);
add_skill("offhand training", 1);
add_skill("parry", 1);
add_skill("resist stun", 1);
add_skill("reverse punch", 1);
add_skill("reverse stroke", 1);
add_skill("shield bash", 1);
add_skill("thrown", 1);
add_skill("two handed blade", 1);
add_skill("two handed blunt", 1);
add_skill("two handed flail", 1);
add_skill("two handed polearm", 1);
add_skill("two handed staff", 1);
add_skill("whirlwind attack", 1);


add_skill("true strike", 1);


add_skill("mortal attack", 1);
add_skill("lightning strike", 1);
add_skill("sling", 1);
add_skill("stab", 1);
add_skill("strong arm", 1);
add_skill("swiftness", 1);
add_skill("fast attack", 1);
add_skill("head butt", 1);



  
  return;
}

