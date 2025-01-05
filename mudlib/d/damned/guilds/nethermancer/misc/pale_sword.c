#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_ac(0);
    set_name("white sword");
    set("id", ({ "sword", "pale sword", "white sword", "white pale sword", "pale white sword" }));
    set_short("A pale white sword");
    set_long("This sword appears to be completely uniform in color, an extraordinarily pale white that looks as if its brightness alone could blind the eye that glanced upon it for longer than a few seconds. Its blade extends a modest three feet but looks horribly sharp on both sides and especially at its point.");
    set_quality(6);
    set_type("blade");
    set_property("no add quality", 1);
    set_weight(50);
    set_material("metal/boernerine");
    set_value(5555);
    set_wc(100, "cutting");
    set_wc(85, "reflection");
    set_wc(85, "fire");
    set_verb("tear");
    return;
}
