#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("statue");
    set("id", ({ "statue", "blue statue", "axe statue", "statue of an axe", "blue statue of an axe" }));
    set_short("%^BLUE%^A blue statue of an axe%^RESET%^");
    set_long("This is a considerably large statue of an double edged axe with the two blades being of perfectly equal size. It protrudes upward from a grey multi layered rectangular stone base.");
    set_weight(10000000);
    set_value(0);
}
