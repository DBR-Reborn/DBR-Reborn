#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("teleport item");
    set("id", ({ "teleport item" }));
    set_short("");
    set_long("?????");
    set_property("no get", 1);
    return;
}
