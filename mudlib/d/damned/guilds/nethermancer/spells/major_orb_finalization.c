inherit "/std/spells/long_term_spell";

string petname;

void create() {
    ::create();
    set_property("name", "major orb finalization");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 259);
    set_property("dev cost", 232);
    set_property("fast dev cost", 704);
    set_property("spell level", 35);
    set_property("caster message", "You attempt to finalize a soul of the netherworld.");
    set_property("target message", "");
    set_property("observer message", "$C attempts to finalize a soul of the netherworld.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This spell will give a well trained Nethermancer the power to finalize a soul orb for undead creation or magical sacrifice of very powerful creatures or abilities. When the orb is completely finalized by this spell, no extra souls can be infused to it with other magic and all souls except one of the ones that the orb is finalized for will be released. This spell allows finalization of orbs for souls of the third nether category, with a list of all the souls that are valid to use as arguments for the spell and the minimum level the caster is required to have attained to finalize an orb for that soul listed below. This is a long-term spell (see help long-term), and it takes very much real time to cast. The final time however can be lowered by the base values of the skill 'major nether arts."+
      "\n\nChaos Shadow (Level 35)\nSoul Knight (Level 38)\nShadow Beast (Level 39)\nDeathmage (Level 42)\nGravewyrm (Level 45)\n\nSyntax: 'cast *6 major orb finalization at orb with soul knight'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("major nether arts") * 25;
    int exp = caster->query_base_skill("major nether erudition") / 2;
    int finaltime;

    petname = args;

    if(!at->id("soul orb")) {
	message("info", "This spell may only be cast at a soul orb.", caster);
	remove();
	return;
    }
    if(at->query_property("soul orb finalize") > 0) {
	message("info", "This soul orb has already been finalized.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "%^BOLD%^%^RED%^You misdirect the finalization energies and blast your own body with them, instantly dropping your horribly damaged body to the floor!%^RESET%^", caster);
	caster->set_hp(-1);
	remove();
	return;
    }
    if(args != "chaos shadow" && args != "soul knight" && args != "shadow beast" && args != "deathmage" && args != "gravewyrm") {
	message("info", "That is not a valid argument for this spell. See 'help spell major orb finalization' for a list for valid souls to finalize.", caster);
	remove();
	return;
    }
    if(args == "chaos shadow") {
	if(caster->query_level() < 35) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("chaos shadow souls") < 1) {
	    message("info", "This orb does not contain a chaos shadow soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (18000/power) - bonus;
	set_property("long term exp", 1460*(200+exp));
    }
    if(args == "soul knight") {
	if(caster->query_level() < 38) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("soul knight souls") < 1) {
	    message("info", "This orb does not contain a soul knight soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (19800/power) - bonus;
	set_property("long term exp", 2060*(200+exp));
    }
    if(args == "shadow beast") {
	if(caster->query_level() < 39) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("shadow beast souls") < 1) {
	    message("info", "This orb does not contain a shadow beast soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (21600/power) - bonus;
	set_property("long term exp", 2296*(200+exp));
    }
    if(args == "deathmage") {
	if(caster->query_level() < 42) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("deathmage souls") < 1) {
	    message("info", "This orb does not contain a deathmage soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (24000/power) - bonus;
	set_property("long term exp", 3128*(200+exp));
    }
    if(args == "gravewyrm") {
	if(caster->query_level() < 45) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("gravewyrm souls") < 1) {
	    message("info", "This orb does not contain a gravewyrm soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (26400/power) - bonus;
	set_property("long term exp", 4167*(200+exp));
    }
    if(finaltime < 5) finaltime = 5;
    if(wizardp(caster)) finaltime = 1;
    message("info", "%^BOLD%^%^CYAN%^You encapsulate the soul orb in a sphere of magical power and begin the endeavour of finalization!%^RESET%^", caster);
    set_work_message("%^BOLD%^%^BLUE%^You finalize the orb.%^RESET%^");
    start_work(at, caster, finaltime, power);
    return;
}

void finish_work(object caster, object at, int power) {

    if(power <= 0) {
	message("info", "BUG", environment(caster));
	remove();
	return;
    }
    at->remove_all_properties();
    at->set_property(""+petname+" souls", 1);
    at->set_property("soul orb finalize", 1);
    message("info", "%^BOLD%^%^BLUE%^You have successfully finalized the soul orb! It may now either be sacrificed for temporary abilities or transformed into an undead pet with appropriate magics.%^RESET%^", caster);
    message("info", "%^BOLD%^%^BLUE%^"+(string)caster->query_cap_name()+" successfully finalizes a soul orb!", environment(caster), ({ caster }));
    at->set_property("total souls", 2);
}
