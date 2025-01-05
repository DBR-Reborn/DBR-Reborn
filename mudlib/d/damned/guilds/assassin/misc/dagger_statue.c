#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("statue");
    set("id", ({ "statue", "blue statue", "dagger statue", "statue of a dagger", "blue statue of a dagger" }));
    set_short("%^BLUE%^A blue statue of a dagger%^RESET%^");
    set_long("This is a large blue statue of an upward pointing dagger, situated atop a layered rectangular grey stone base.");
    set_weight(10000000);
    set_value(0);
}
