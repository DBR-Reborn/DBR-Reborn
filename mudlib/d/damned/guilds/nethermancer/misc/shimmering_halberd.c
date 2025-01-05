#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_ac(0);
    set_name("halberd");
    set("id", ({ "dark halberd", "purple halberd", "shimmering halberd", "dark purple halberd", "dark purple shimmering halberd" }));
    set_short("A dark purple halberd, %^BOLD%^%^WHITE%^it shimmers faintly%^RESET%^");
    set_long("This halberd at first glance looks as if it is very powerful, fashioned of a darkened mithril and carrying a terribly sharp blade on its end. Numerous red runes cover the entire weapon, with a nasty glow emanating from each of them every time the weapon moves for any reason.");
    set_quality(6);
    set_type("two handed polearm");
    set_property("no add quality", 1);
    set_weight(100);
    set_material("metal/mithril");
    set_value(10000);
    set_enh_critical(6);
    set_property("brittle", 50);
    set_wc(125, "impaling");
    set_wc(111, "unholy");
    set_wc(111, "fire");
    set_verb("impale");
    return;
}
