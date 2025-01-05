#include <move.h>
#include <colors.h>

inherit "/std/weapon";

object shad;

void create() {
    ::create();
    set("id", ({ "mace", "blunt", "mace of taul" }));
    set_name("mace");
    set("short", CMAGENTA + CBOLD + "Mace of Taul" + CRESET);
    set("long",

      "The mace of taul is standard model weapon.  It is not "+
      "glamorous or beautifull, but it works.");
    set_weight(120);
    set_type("blunt");
    set_wc(25, "impact");
    set_wc(25, "electricity");
    set_ac(10);
    set_parry_bonus(10);
    set_property("no save", 1);
    set_quality(6);
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_decay_rate(1500);
    set_auto_critical(([ "impact B" : 10 ]));
    set_property("enchantment", 3);
    set_value(0);
    set_property("no save",1);
    return;
}

