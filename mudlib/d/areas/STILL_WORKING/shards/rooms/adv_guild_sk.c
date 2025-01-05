//    The skill room of the adventurer's guild.
//
//    DarkeLIB 0.1
//    -Diewarzau 5/7/96
#include "../shards.h"
#include <std.h>
#define DEFAULT_SCREEN_SIZE 75
#define EXCLUDE ({ "control_change.c", "long_term.c", "skill.c", "lore_skill.c" })

inherit ROOM;

int calc_skill_inc(object who, string skill);
int dev_cost(object who, string skill);
int filter_skill(string file, mixed *info);
int skill_filter(string skill, int i);

void create() {
  ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Irony");
    set("long",
"The sheer size of this room indicates that it must have been a gymnasium at one point. Ironically enough, on one side of it, you spot destroyed bookshelves, and long-gone books. What would mental prowess be doing in a place of physical prowess?");
    add_exit(ROOMS+"adv_guild_sp", "west");
    add_exit(ROOMS+"adv_guild_entrance", "north");
}
