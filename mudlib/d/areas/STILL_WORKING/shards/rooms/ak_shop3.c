#include "../shards.h"
#include <rooms.h>
#define STATS ({ "strength", "intelligence", "dexterity", \
"charisma", "wisdom", "constitution" })

inherit "std/room";

varargs int check_pts(object tp, int pts, int flag);

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set("short","The Futility of the Future");
   set("long",
"The walls of this building are covered with papers. While most have been ripped to shreds, you can still tell what they must have announced incredible quests from divine beings, and the rewards you would have gotten from completing them. \n"
"\nThere is still a sign left on the east wall.");
   add_exit(ROOMS+"ak_marksw", "east");
   set_items( (["sign": (: call_other, this_object(), "read_sign" :) ]) );
}

int read_sign() {
  string help_str;

  help_str =
"You may spend quest points on the following things:\n"
"\n"
"#  Item                              Cost (quest points):\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
"1.  50 development points            1\n"
"2.  50 mithril pieces                1\n"
"3.  +1% Luck (bonus to all skills)   12\n"
"4.  +5% Luck                         55\n"
"5.  50% telepathy skill              15\n"
"6.  80% telepathy skill              45\n"
"7.  +10 magic points (max)           5\n"
"8.  +10 hit points (max)             4\n"
"9.  +5% magic resistance             21\n"
"10. +1 to any stat                   4\n"
"11. Limb Regeneration                40\n"
"12. +1 night vision                  15\n"
"13. +3 AC (tough skin - once only)   20\n"
"14. +7 AC (chitin - once only)       40\n"
"15. Ambidextry (no offhand penalty)  40\n"
"16. 25% faster metabolism            55\n"
"17. 10% faster healing               15\n"
"18. 10% faster mp regeneration       20\n"
"19. Fast learning: -1 dev cost to    12\n"
"       everything!\n"
"\nType 'purchase #' to purchase an item.";
  this_player()->more(explode(help_str, "\n"));
  return 1;
}




