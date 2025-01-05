#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("statue");
    set("id", ({ "statue", "blue statue", "robed statue", "figure statue", "statue of a robed figure", "blue statue of a robed figure", "statue of a figure", "blue statue of a robed figure" }));
    set_short("%^BLUE%^A blue statue of a robed figure%^RESET%^");
    set_long("This is a life sized deep blue statue of a robed figure, with nothing but darkness seen through its hood and its entire body completely covered including the hands and feet areas. It stands tall atop a rectangular grey stone base comprised of several differently sized layers.");
    set_weight(10000000);
    set_value(0);
}
