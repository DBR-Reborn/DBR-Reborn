inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name", "energize dragon jewel");
    set_property("skill", "elemental magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 500);
    set_property("dev cost", 888);
    set_property("fast dev cost", 2960);
    set_property("spell level", 56);
    set_property("moon", "luna");
    set_property("caster message", "You utter a magical incantation.");
    set_property("target message", "");
    set_property("observer message", "$C begins to energize a dragon jewel");
    set_property("spell type", ({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This powerful spell is the sole long-term magic available to an Elemental Mage, and that being said it is indeed an extremely useful one for the most highly trained of those maguses to train. It allows the largest of elemental masses to be sacrificed and its power channeled into a dragon jewel available at certain magic shops throughout the realm to make it become eternally energized. Once energized, the jewel can then be used to make a powerful Elemental Dragon pet permanent, allowing for the creation of powerful forces to aid the mage in battle or defense of his valuables. This is a long-term spell (see help long-term), and it takes very much real time to cast. If you are interrupted while casting, you may pick up again at a later time.\n\nSyntax: 'cast *6 energize dragon jewel at jewel'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object *inv;
    int i;

    inv = all_inventory(environment(caster));
    inv = filter_array(inv, "filter_fun");

    for(i = 0;i < sizeof(inv);i++) {
	if(inv[i]->query_property("owner name") == (string)caster->query_name()) {
	    if(inv[i]->query_level() != 80) {
		message("info", "Your energy mass is not large enough to sacrifice for this spell.", caster);
		remove();
		return;
	    }

	    if(at->query_name() != "dragon jewel") {
		message("info", "This spell is only effective when cast upon a crystalline dragon jewel.", caster);
		remove();
		return;
	    }
	    if(at->query_property("energized") != 0) {
		message("info", "This jewel is already energized from this spell.", caster);
		caster->add_mp(props["mp cost"]);
		remove();
		return;
	    }
	    if(flag) {
		message("info", "You inadvertently destroy the precious dragon jewel along with your energy mass!", caster);
		message("info", (string)caster->query_cap_name()+" inadvertently destroys his crystalline dragon jewel!", environment(caster), ({ caster }));
		message("info", "%^BLUE%^The mass instantly vanishes!%^RESET%^", environment(caster));
		at->remove();
		inv[i]->remove();
		remove();
		return;
	    }
	    if(wizardp(this_player())) {
		inv[i]->remove();
		message("info", "%^BLUE%^The mass flows into the dragon jewel for its energizing!%^RESET%^", environment(caster));
		start_work(at, caster, 1, power);
		return;
	    }
	    inv[i]->remove();
	    message("info", "%^BLUE%^The mass flows into the dragon jewel for its energizing!%^RESET%^", environment(caster));
	    set_work_message("%^BOLD%^%^MAGENTA%^You energize the dragon jewel.%^RESET%^");
	    start_work(at, caster, 14400 - power*600, power); 
	    ::spell_func(caster, at, power, args, flag);
	}
    }
    return;
}

void finish_work(object caster, object at, int power) {
    object ob;

    if(power <= 0) {
	message("info", "BUG in energize dragon jewel spell....unable to complete.", environment(caster));
	remove();
	return;
    }
    message("info", "The dragon jewel is now energized!", caster);
    at->set_property("energized", 1);
    at->set_short("A crystalline jewel (%^BOLD%^%^YELLOW%^energized%^RESET%^)");
    at->set_long("This adeptly fashioned crystalline jewel, virtually perfect in its appearance as that of a fierce dragon, glows endlessly with a golden light having been energized with incredible elemental power. The energy of this jewel can now be used to make a specified Elemental Dragon permanent with the command 'energize dragon', but upon doing so this beautiful jewel will unfortunately shatter from the release of the power.");
    remove();
    return;
}

int filter_fun(object ob) {
    if(ob->query_name() == "energy mass") return 1;
    else return 0;
}
