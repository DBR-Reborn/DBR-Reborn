#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_ac(0);
    set_name("staff");
    set("id", ({ "staff", "ancient staff", "nether staff", "nether lord staff" }));
    set_short("An ancient staff");
    set_long("This staff appears as if it is thousands of years old. It is entirely fashioned of an aged wood that bears no resemblance to any wood ever seen by the eyes of those alive in todays world. Numerous small runes of power cover random spots of the wood and the interior of all the twisted wood at the top of the weapon glows endlessly with a frightening red light.");
    set_quality(6);
    set_type("two handed staff");
    set_property("no decay",1);
    set_property("brittle", 100);
    set_weight(80);
    set_material("an unknown wood");
    set_value(20000);
    set_wc(150, "crushing");
    set_wc(130, "infernal");
    set_wc(130, "time");
    set_wc(130, "unholy");
    /*set_verb("bludgeon");
    this_object()->set("vampiric", 1);
    this_object()->set_hit((: call_other, "/std/spells/shadows/vampiric_shadow", "vampiric_func", 20 :));*/
    return;
}
