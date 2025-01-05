// Wizard: Gellor
// Rug
// rug.c
#include <std.h>
inherit OBJECT;
void create() {
        ::create();
        set_name("a rug");
        set("id",({"rug"}));
        set("short","A cheap looking rug");
        set("long","This is a cheap rug. It is made of some sort of "
        			    "soft woven plant fibers which have turned brown "
                   "over time.");
        set_weight(200);
        set_value(0);
}
