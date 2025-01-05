#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("statue");
    set("id", ({ "statue", "blue statue", "shield statue", "statue of a shield", "blue statue of a shield" }));
    set_short("%^BLUE%^A blue statue of a shield%^RESET%^");
    set_long("This is a wide statue of a considerably large shield, with several different symbols inscribed on its front side facing those who directly enter the room. It stands straight up atop a grey stone base with several rectangular layers.");
    set_weight(10000000);
    set_value(0);
}
