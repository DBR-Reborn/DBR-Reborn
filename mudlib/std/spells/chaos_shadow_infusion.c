inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name", "chaos shadow infusion");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 288);
    set_property("dev cost", 180);
    set_property("fast dev cost", 540);
    set_property("spell level", 35);
    set_property("moon", "luna");
    set_property("caster message", "You begin to call forth the power required to perform a soul infusion.");
    set_property("target message","");
    set_property("observer message", "$C begins to infuse a soul into an orb.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("long term exp", 292000);
    return;
}

void info() {
    message("help", "Through this magic, a Nethermancer gains the ability to perform the most powerful direct soul infusion available in their profession, the infusion into a soul orb of a very powerful chaos shadow soul. When the long-term is finished and successful, the soul can be united with other souls of various types with a soul union magic, or the soul orb can be finalized with a different magic for sacrifice or creation of an undead chaos shadow pet. Execution of this spell is only possible if a charged greater nexus is in the same room of the caster, and a soul orb must be in the hands of the caster for the spell to be cast upon (the soul orbs can be bought at magic shops). This is a long-term spell (see help long-term), but its overall time can be reduced by the latent skill 'major nether arts'. If you are interrupted while casting, you may resume the casting at a later time provided a nexus and the same soul orb is available.\n\nSyntax: 'cast *6 chaos shadow infusion at orb'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("major nether arts") * 25;
    int exp = caster->query_base_skill("major nether erudition") / 2;
    int finaltime = (18000/power) - bonus;
    if(finaltime < 5) finaltime = 5;
    if(wizardp(caster)) finaltime = 1;
    set_property("long term exp", 1460*(200+exp));

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
    if(present("nexus", environment(caster))->query_name() == "lesser nexus") {
	message("info", "The nexus in the room is not powerful enough to perform this magic.", caster);
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
    message("info", "You finish infusing a %^BOLD%^%^RED%^chaos shadow%^RESET%^ soul into the soul orb!", caster);
    message("info", ""+(string)caster->query_cap_name()+" successfully infuses a Chaos Shadow soul into a soul orb.", environment(caster), ({ caster }));
    at->set_property("chaos shadow souls", (at->query_property("chaos shadow souls") + 1));
    at->set_property("total souls", 2);
    remove();
    return;
}
