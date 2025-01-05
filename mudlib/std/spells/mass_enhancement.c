inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "mass enhancement");
    set_property("skill", "elemental magic");
    set_property("casting time", 15);
    set_property("base mp cost", 75);
    set_property("dev cost", 100);
    set_property("fast dev cost", 290);
    set_property("spell level", 20);
    set_property("moon", "luna");
    set_property("caster message", "You fill $T with great elemental power!");
    set_property("target message", "");
    set_property("observer message", "$C fills $T with great elemental power.");
    set_property("spell type", ({ }));
    set_property("duration", "permanent");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This is a very powerful spell which can give the energy masses that follow Elemental Mages and supply them with their power extra elemental properties. Once the mass has been enhanced with this spell, ALL spells cast draining energy from that mass will contain the original element PLUS the element or elements added with this spell. The size of the mass determines how many times this spell can be used on it in total if at all (see help files for energy mass summoning spells). The skill level of the lore used in the argument will determine the intensity of the element added to the mass. That intensity is also affected by the power of this spell multiplied by 1/6, with effectivness maxing at *6.\n\nSyntax: 'cast *6 mass enhancement at mass with ice'.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    int loreskill;

    loreskill = caster->query_skill(args+" lore");

    if(power > 6) {
	power = 6;
    }

    if((string)at->query_name() != "energy mass") {
	message("info", "This spell must be cast upon an energy mass.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "You fill the mass with an extreme amount of useless energy, disallowing any further enhancement.", caster);
	at->set_property("added lores", (at->query_property("lore total") - 1));
	remove();
	return;
    }
    if((int)caster->query_skill((string)args+" lore") == 0) {
	message("info", "You do not have the skill '"+(string)args+" lore', which is required to enhance an energy mass with power of that element.", caster);
	remove();
	return;
    }
    if((string)at->query_property("lore name") == (string)args || (string)at->query_property("lore name two") == (string)args || (string)at->query_property("lore name three") == (string)args || (string)at->query_property("lore name four") == (string)args) {
	message("info", "The energy mass already has elemental power from that lore.", caster);
	remove();
	return;
    }
if((string)at->query_name() == "energy mass") {
	if(at->query_property("added lores") < (at->query_property("lore total"))) {
	    if(at->query_property("added lores") == (at->query_property("lore total") - 1)) {
		message("info", "You cannot add any more elemental power to that particular mass.", caster);
		remove();
		return;
	    }
	    if(at->query_property("added lores") == 0) {
		at->set_property("lore power two", (loreskill/6)*power);
		at->set_property("lore name two", (string)args);
		at->set_property("added lores", (at->query_property("added lores") + 1));
		message("info", "You empower the mass with the element of "+args+"!", caster);
		return;
	    }
	    if(at->query_property("added lores") == 1) {
		at->set_property("lore power three", (loreskill/6)*power);
		at->set_property("lore name three", (string)args);
		at->set_property("added lores", (at->query_property("added lores") + 1));
		message("info", "You empower the mass with the element of "+args+"!", caster);
		return;
	    }
	    if(at->query_property("added lores") == 2) {
		at->set_property("lore power four", (loreskill/6)*power);
		at->set_property("lore name four", (string)args);
		at->set_property("added lores", (at->query_property("added lores") + 1));
		message("info", "You empower the mass with the element of "+args+"!", caster);
		return;
	    }
	}
    }
    return;
}
