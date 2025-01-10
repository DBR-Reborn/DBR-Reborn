#include <move.h>
#include <colors.h>

inherit "/std/weapon";

object shad;

void create() {
	::create();
	set_ac(5);
	set_name("vacuum hammer");
	set("id", ({ "hammer", "two handed hammer", "vacuum hammer", "hammer of oberon", "vacuum hammer of oberon" }));
	set_short("%^BOLD%^%^BLACK%^The Vacuum Hammer of Oberon%^RESET%^");
	set_long("This is a noticeable large hammer completely fashioned of boernerine. At its end is a square block of boernerine inscribed with one rune which seems to be draining the air around it.");
	set_type("two handed blunt");
	set_quality(6);
	set_weight(150);
	set_property("no add quality", 1);
	set_property("no decay", 1);
	set_property("no save", 1);
	set_material("boernerine");
	set_parry_bonus(10);
	set_value(0);
	set_verb("dim");
	set_wield("You now feel the power of Oberon's might");
	set_unwield("You no longer feel the power of Oberon's might");
	return;
}
int drop() {
    remove_delayed_call("dest_me");
    delayed_call("dest_me", 1);
    return 0;
}

void dest_me() {
    if(environment())
	message("info", "" + "The Hammer of Oberon disappears.",
	  environment());
    if(shad) shad->external_destruct(shad);
    remove();
    return;
}

void set_shadow(object ob) {
    shad = ob;
}
