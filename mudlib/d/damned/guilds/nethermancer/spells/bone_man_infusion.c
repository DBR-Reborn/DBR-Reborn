inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name", "bone man infusion");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 40);
    set_property("dev cost", 10);
    set_property("fast dev cost", 31);
    set_property("spell level", 1);
    set_property("moon", "luna");
    set_property("caster message", "You begin to call forth the power required to perform a soul infusion.");
    set_property("target message","");
    set_property("observer message", "$C begins to infuse a soul into an orb.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("long term exp", 250);
    return;
}

void info() {
    message("help", "This spell allows a Nethermancer to infuse the soul of a Bone Man pet into a soul orb. Once the soul is infused, it can either be united with other souls using a soul union spell or its orb can be finalized for sacrifice or undead creation. This spell requires a charged lesser nexus present in the room to cast, and must be cast at a soul orb (available at magic shops). This is a long-term spell (see help long-term), but its overall time can be reduced by the latent skill 'minor nether arts'. If you are interrupted while casting, you may resume the casting at a later time provided a nexus and the same soul orb is available.\n\nSyntax: 'cast *6 bone man infusion at orb'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("minor nether arts") * 10;
    int exp = caster->query_base_skill("minor nether erudition") / 2;
    int finaltime = (1800/power) - bonus;
    if(finaltime < 5) finaltime = 5;
    if(wizardp(caster)) finaltime = 1;
    set_property("long term exp", 2*(125+exp));

    if(!at->id("soul orb")) {
	message("info", "This spell may only be cast at a soul orb.", caster);
	remove();
	return;
    }
    if(!present("nexus", environment(caster))) {
	message("info", "A nexus must be present in the room in order to cast this spell.", caster);
	remove();
	return;
    }
    if(at->query_property("fumbled") > 0) {
	message("info", "This soul orb is destabilized and cannot recieve any more souls.", caster);
	remove();
	return;
    }
    if(at->query_property("soul orb finalize") > 0) {
	message("info", "This soul orb has been finalized for sacrifice or undead creation and therefore cannot recieve any more souls.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "You accidently destabilize the soul orb, preventing it from recieving any new souls!", caster);
	at->set_property("fumbled", 1);
	remove();
	return;
    }
    message("info", "%^BOLD%^%^GREEN%^You establish a link with the nexus in the room and commence infusing the soul!%^RESET%^", caster);
    set_work_message("%^BOLD%^%^BLUE%^You infuse the soul.%^RESET%^");
    caster->set("nexus long term", 1);
    start_work(at, caster, finaltime, power);
    return;
}

void finish_work(object caster, object at, int power) {

    if(power <= 0) {
	message("info", "BUG", environment(caster));
	remove();
	return;
    }
    message("info", "You finish infusing a %^BOLD%^%^RED%^bone man%^RESET%^ soul into the soul orb!", caster);
    message("info", ""+(string)caster->query_cap_name()+" successfully infuses a Bone Man soul into a soul orb.", environment(caster), ({ caster }));
    at->set_property("bone man souls", (at->query_property("bone man souls") + 1));
    at->set_property("total souls", 2);
    remove();
    return;
}
