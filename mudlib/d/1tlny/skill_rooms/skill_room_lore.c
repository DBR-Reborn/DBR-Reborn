#include "a1.h"
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room_any";

void create() {

  ::create();

  set("short", "Global %^YELLOW%^LORE%^RESET%^ skills");
  set("long", "This is the room that you can train Global %^YELLOW%^LORE%^RESET%^ skills.\n");

    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
  
  //  The following line is VERY, VERY important.
    set_join_room("/d/damned/guilds/join_rooms/child_join");


    add_exit(PATH+"skill_room_crafting", "up");
    add_exit(PATH+"skill_room_other", "down");


add_skill("aether lore", 1);
add_skill("air lore", 1);
add_skill("chaos lore", 1);
add_skill("cold lore", 1);
add_skill("earth lore", 1);
add_skill("electricity lore", 1);
add_skill("fire lore", 1);
add_skill("ice lore", 1);
add_skill("inertia lore", 1);
add_skill("nexus lore", 1);
add_skill("plasma lore", 1);
add_skill("vacid lore", 1);
add_skill("water lore", 1);
add_skill("wind lore", 1);

add_skill("nature lore", 2);
add_skill("dark lore", 2);
add_skill("desert lore", 2);
add_skill("genie lore", 2);
add_skill("gravity lore", 2);
add_skill("herb lore", 2);

add_skill("poison lore", 3);
add_skill("time lore", 3);
add_skill("shadow lore", 3);
add_skill("rune lore", 3);

add_skill("elemental focus", 4);
add_skill("elementalism", 4);
add_skill("elemental magic", 4);
add_skill("elemental power", 4);
add_skill("grand elemental gathering", 4);
add_skill("focus of elements", 4);

  
  return;
}

