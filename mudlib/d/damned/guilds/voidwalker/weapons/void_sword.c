#include <move.h>
#include <colors.h>

inherit "/std/weapon";

object shad;

void create() {
	::create();
	set_ac(10);
	set_name("void sword");
	set("id", ({ "sword", "two handed sword", "void sword", "sword of oberon", "void sword of oberon" }));
	set_short("%^BOLD%^%^BLUE%^The Void Sword of Oberon%^RESET%^");
	set_long("This is a very powerful weapon adeptly crafted of perfectly pure boernerine. The handle is wrapped in mystic silver, and its blade is covered with ancient inscriptions and shimmers black and violet endlessly.");
	set_type("two handed blade");
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
	message("info", "" + "The Sword of Oberon disappears.",
	  environment());
    if(shad) shad->external_destruct(shad);
    remove();
    return;
}

void set_shadow(object ob) {
    shad = ob;
}
