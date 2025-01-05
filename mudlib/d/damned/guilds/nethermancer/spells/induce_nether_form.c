inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name", "induce nether form");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 220);
    set_property("dev cost", 182);
    set_property("fast dev cost", 586);
    set_property("spell level", 28);
    set_property("moon", "luna");
    set_property("caster message", "You channel a continuous stream of nether energy into $T's body!");
    set_property("target message","$C channels a continuous stream of nether energy into your body!");
    set_property("observer message", "$C channels a continuous stream of nether energy into $T's body.");
    set_property("spell type",({ }));
    set_property("target type", "living");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This magic permits an accomplished Nethermancer to channel a considerable amount of nether energy from a charged nexus into the body of an undead creation, inducing a powerful body state for the creature referred to as nether form. When an undead is in nether form it will be completely immune to all stunning, bleeding, and poisonous attacks that can be inflicted upon it, and it will also gain the ability to see the invisible. Nether form is permanent once it has been induced, and no ability available to players can successfully remove it. The nexus required for this spell to work must be at least a greater nexus, and the spell itself will only work on pets that are in the direct ownership of the caster. This is a long-term spell (see help long-term for details), and can require a significant time investment to finish. If you are interrupted while casting, you may continue again at a later time.\n\nSyntax: 'cast *6 induce nether form at bone man'\n\nNOTE: This spell will not work on the Eternal Darkness.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    int finaltime;

    if(!present("nexus", environment(caster))) {
	message("info", "This spell requires a nexus to be present in the room in order to cast.", caster);
	remove();
	return;
    }
    if(present("nexus", environment(caster))->query_name() == "lesser nexus") {
	message("info", "Only greater and master nexuses can be used to cast this spell.", caster);
	remove();
	return;
    }
    if(!at->query_property("nethermancer pet")) {
	message("info", "This spell may only be cast upon Nethermancer created undeads.", caster);
	remove();
	return;
    }
    if(at->query_owner() != caster->query_true_name()) {
	message("info", "You may not induce nether form on undeads that are not owned by you.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "You channel far too much energy into the undead and inadvertently destroy it!", caster);
	at->die();
	remove();
	return;
    }
    if(at->query_property("pet name") == "eternal darkness") {
	message("info", "The Eternal Darkness cannot recieve nether form.", caster);
	remove();
	return;
    }
    if(at->query_property("nether form")) {
	message("info", "This undead is already in nether form.", caster);
	remove();
	return;
    }
    if(at->query_property("pet name") == "bone man") finaltime = 900/power;
    if(at->query_property("pet name") == "rotted zombie") finaltime = 1260/power;
    if(at->query_property("pet name") == "skeletal zombie") finaltime = 1800/power;
    if(at->query_property("pet name") == "revenant") finaltime = 2260/power;
    if(at->query_property("pet name") == "blood hound") finaltime = 2700/power;
    if(at->query_property("pet name") == "bone hound") finaltime = 3240/power;
    if(at->query_property("pet name") == "undead beast") finaltime = 3960/power;
    if(at->query_property("pet name") == "ghost") finaltime = 4500/power;
    if(at->query_property("pet name") == "ghast dog") finaltime = 4860/power;
    if(at->query_property("pet name") == "zombie spirit") finaltime = 5400/power;
    if(at->query_property("pet name") == "skeletal essence") finaltime = 6300/power;
    if(at->query_property("pet name") == "blood fiend") finaltime = 7200/power;
    if(at->query_property("pet name") == "vampiric hound") finaltime = 7560/power;
    if(at->query_property("pet name") == "fanged spirit") finaltime = 8100/power;
    if(at->query_property("pet name") == "black essence") finaltime = 9000/power;
    if(at->query_property("pet name") == "red ghoul") finaltime = 9900/power;
    if(at->query_property("pet name") == "dark knight") finaltime = 10800/power;
    if(at->query_property("pet name") == "blood knight") finaltime = 11700/power;
    if(at->query_property("pet name") == "essence warrior") finaltime = 13500/power;
    if(at->query_property("pet name") == "chaos shadow") finaltime = 14400/power;
    if(at->query_property("pet name") == "soul knight") finaltime = 16200/power;
    if(at->query_property("pet name") == "shadow beast") finaltime = 18000/power;
    if(at->query_property("pet name") == "deathmage") finaltime = 19800/power;
    if(at->query_property("pet name") == "gravewyrm") finaltime = 21600/power;
    if(at->query_property("pet name") == "shadowflame templar") finaltime = 54000/power;
    if(at->query_property("pet name") == "death dragon") finaltime = 81000/power;
    if(at->query_property("pet name") == "nether lord") finaltime = 108000/power;
    set_property("long term exp", finaltime*40);
    if(wizardp(caster)) finaltime = 1;
    message("info", "%^BOLD%^%^CYAN%^A powerful stream of energy successfully connects to "+(string)at->query_cap_name()+"'s body and commences its transformation into nether form!%^RESET%^", caster);
    set_work_message("%^BOLD%^%^BLUE%^You infuse nexus energy into the undead.%^RESET%^");
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
    at->set_property("no bleed", 1);
    at->set_property("see invis", 1);
    at->set_property("nether form", 1);
    message("info", "%^BOLD%^%^CYAN%^"+(string)at->query_cap_name()+"'s body is completely enveloped in a powerful cyan aura as it completes its transformation into nether form!%^RESET%^", environment(caster));
    at->set_short(at->query_property("pet short")+" %^BOLD%^%^GREEN%^(%^CYAN%^nether form%^GREEN%^)%^RED%^");
    remove();
    return;
}
