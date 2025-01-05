// Wizard: Gellor
// rock
// rock.c
#include <std.h>
inherit OBJECT;
void create() {
        ::create();
        set_name("a rock");
        set("id",({"rock"}));
        set("short","a brown rock");
        set("long","This is a brown colored rock.");
        set_weight(750);
        set_value(0);
}
