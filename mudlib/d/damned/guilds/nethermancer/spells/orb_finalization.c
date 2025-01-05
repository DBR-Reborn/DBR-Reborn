inherit "/std/spells/long_term_spell";

string petname;

void create() {
    ::create();
    set_property("name", "orb finalization");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 122);
    set_property("dev cost", 91);
    set_property("fast dev cost", 276);
    set_property("spell level", 20);
    set_property("caster message", "You attempt to finalize a soul of the netherworld.");
    set_property("target message", "");
    set_property("observer message", "$C attempts to finalize a soul of the netherworld.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "With this magic, a trained Nethermancer can imbue finalization upon a soul orb for either magical sacrifice of moderately poweful abilities or undead creation of notable pets. After the orb has been finalized, no additional souls can be added to it with other spells and every soul except one soul that the orb finalization is for will be destroyed. This magic can be used to finalize orbs for souls of the second nether category, and a listing of all valid souls that this spell can finalize is displayed below along with the minimum level the caster must be to successfully perform the finalization. This is a longterm spell (see help long-term), and it takes very much real time to cast. The overall time however can be reduced with the base values of the latent 'nether arts' skill."+ 
      "\n\nBlood Fiend (Level 20)\nVampiric Hound (Level 21)\nFanged Spirit (Level 23)\nBlack Essence (Level 25)\nRed Ghoul (Level 27)\nDark Knight (Level 30)\nBlood Knight (Level 32)\nEssence Warrior (Level 33)\n\nSyntax: 'cast *6 orb finalization at orb with fanged spirit'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("nether arts") * 20;
    int exp = caster->query_base_skill("nether erudition") / 2;
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
    if(args != "blood fiend" && args != "vampiric hound" && args != "fanged spirit" && args != "black essence" && args != "red ghoul" && args != "dark knight" && args != "blood knight" && args != "essence warrior") {
	message("info", "That is not a valid argument for this spell. See 'help spell orb finalization' for a list for valid souls to finalize.", caster);
	remove();
	return;
    }
    if(args == "blood fiend") {
	if(caster->query_level() < 20) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("blood fiend souls") < 1) {
	    message("info", "This orb does not contain a blood fiend soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (7200/power) - bonus;
	set_property("long term exp", 136*(200+exp));
    }
    if(args == "vampiric hound") {
	if(caster->query_level() < 21) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("vampiric hound souls") < 1) {
	    message("info", "This orb does not contain a vampiric hound soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (8100/power) - bonus;
	set_property("long term exp", 168*(200+exp));
    }
    if(args == "fanged spirit") {
	if(caster->query_level() < 23) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("fanged spirit souls") < 1) {
	    message("info", "This orb does not contain a fanged spirit soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (9000/power) - bonus;
	set_property("long term exp", 247*(200+exp));
    }
    if(args == "black essence") {
	if(caster->query_level() < 25) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("black essence souls") < 1) {
	    message("info", "This orb does not contain a black essence soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (10200/power) - bonus;
	set_property("long term exp", 353*(200+exp));
    }
    if(args == "red ghoul") {
	if(caster->query_level() < 27) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("red ghoul souls") < 1) {
	    message("info", "This orb does not contain a red ghoul soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (11400/power) - bonus;
	set_property("long term exp", 499*(200+exp));
    }
    if(args == "dark knight") {
	if(caster->query_level() < 30) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("dark knight souls") < 1) {
	    message("info", "This orb does not contain a dark knight soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (12600/power) - bonus;
	set_property("long term exp", 763*(200+exp));
    }
    if(args == "blood knight") {
	if(caster->query_level() < 32) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("blood knight souls") < 1) {
	    message("info", "This orb does not contain a blood knight soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (14400/power) - bonus;
	set_property("long term exp", 1002*(200+exp));
    }
    if(args == "essence warrior") {
	if(caster->query_level() < 33) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("essence warrior souls") < 1) {
	    message("info", "This orb does not contain an essence warrior soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (16200/power) - bonus;
	set_property("long term exp", 1141*(200+exp));
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
