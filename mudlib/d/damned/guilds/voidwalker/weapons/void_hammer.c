#include <move.h>
#include <colors.h>

inherit "/std/weapon";

object shad;

void create() {
	::create();
	set_ac(10);
	set_name("void hammer");
	set("id", ({ "hammer", "two handed hammer", "void hammer", "hammer of oberon", "void hammer of oberon" }));
	set_short("%^BOLD%^%^BLUE%^The Void Hammer of Oberon%^RESET%^");
	set_long("This is a noticeable large hammer with a large handle completely fashioned of pure silver. At its end is a perfectly square block of mcgrail inscribed with numerous runes which glows black and violet with void energy.");
	set_type("two handed blunt");
	set_quality(6);
	set_weight(200);
	set_property("no add quality", 1);
	set_property("no decay", 1);
	set_property("no save", 1);
	set_material("boernerine");
	set_value(5);
	set_verb("ionize");
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
