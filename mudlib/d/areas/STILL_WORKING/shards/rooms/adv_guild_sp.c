//  The spell room of the adventurer's guild.
//
//    DarkeLIB 0.1
//    -Diewarzau 5/7/96
#include "../shards.h"
#include <std.h>
#define DEFAULT_SCREEN_SIZE 75
#define EXCLUDE ({ "long_term_spell.c", "spell.c", \
  "weapon_stack_logic.c", "weapon_stack.c", \
  "shadow.c", "claim_activate.c" })

inherit ROOM;

int dev_cost(object who, string spell);
int filter_spell(string file, mixed *info);
int spell_filter(string spell, int i);

void create() {
  ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Silence Before the Storm");
    set("long",
"Unlike the gymnasium you passed before, this is quite obviously a library. Or at least, it used to be a library. Someone took a great deal of effort to rip the pages out of each and every book, leaving them on the floor in a completely disorganized mess. A couple of the papers have familiar names - they are long-lost magical tomes. You suppose that they will be staying lost.");
    add_exit(ROOMS+"adv_guild_sk", "east");
}
