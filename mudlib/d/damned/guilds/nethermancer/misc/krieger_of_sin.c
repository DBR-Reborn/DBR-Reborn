#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_ac(0);
    set_name("dagger");
    set("id", ({ "dagger", "sin dagger", "krieger", "sin krieger", "krieger of sin" }));
    set_short("%^BOLD%^%^RED%^Krieger of Sin%^RESET%^");
    set_long("This is without question the most fearsome weapon your eyes have ever glanced themselves upon. It is a severely oversized dagger that could never be wielded by a normal sized being, but would be perfect for something with gigantic hands that could move them quickly. The entirety of the blade is fashioned of a mysterious mineral that is adorned with multiple glowing crystals, and the hilt is one hundred percent well cut ruby. Powerful random colors of energy course over the blade at all times, so many that never twice do the same combinations of colors appear. This weapon is the truest definiton of power that you have ever held in your hand, and there is not the slightest doubt in your mind of that fact.");
    set_quality(6);
    set_type("knife");
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_property("brittle", 150);
    set_enh_critical(7);
    set_weight(77);
    set_material("metal/tornaug");
    set_value(100000);
    set_wc(250, "cutting");
    set_wc(200, "aether");
    set_wc(200, "electricity");
    set_wc(200, "time");
    set_wc(200, "reflection");
    set_wc(200, "sonic");
    set_verb("dessicate");
    this_object()->set("vampiric", 1);
    this_object()->set_hit((: call_other, "/d/damned/guilds/nethermancer/misc/ed_func", "vampiric_func", 50 :));
    return;
}
