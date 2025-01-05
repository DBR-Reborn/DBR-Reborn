inherit "/std/spells/long_term_spell";

string petname;

void create() {
    ::create();
    set_property("name", "minor orb finalization");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 33);
    set_property("dev cost", 18);
    set_property("fast dev cost", 56);
    set_property("spell level", 1);
    set_property("caster message", "You attempt to finalize a soul of the netherworld.");
    set_property("target message", "");
    set_property("observer message", "$C attempts to finalize a soul of the netherworld.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This spell enables a Nethermancer to finalize a soul orb for either undead creation or magical sacrifice into various types of temporary powers. Once a soul orb is finalized with this magic, no further souls can be infused into it with any soul infusion spells and all souls except one of the souls the orb is finalized for will be completely dissipated. This spell is effective for finalizing soul orbs for souls of the first nether category, and all of the valid souls that can be finalized through the means of a casting are listed below. The minimum level that is mandatory to execute each finalization is displayed to the right of each soul name on the list. This is a longterm spell (see help long-term), and it takes very much real time to cast. The overall time however can be reduced with the base values of the latent 'minor nether arts' skill."+
      "\n\nBone Man (Level 1)\nRotted Zombie (Level 3)\nSkeletal Zombie (Level 4)\nRevenant (Level 5)\nBlood Hound (Level 7)\nBone Hound (Level 9)\nUndead Beast (Level 10)\nGhost (Level 12)\nGhast Dog (level 14)\nZombie Spirit (Level 15)\nSkeletal Essence (Level 18)\n\nSyntax: 'cast *6 minor orb finalization at orb with revenant'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("minor nether arts") * 10;
    int exp = caster->query_base_skill("minor nether erudition") / 2;
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
    if(args != "bone man" && args != "rotted zombie" && args != "skeletal zombie" && args != "revenant" && args != "blood hound" && args != "bone hound" && args != "undead beast" && args != "ghost" && args != "ghast dog" && args != "zombie spirit" && args != "skeletal essence") {
	message("info", "That is not a valid argument for this spell. See 'help spell minor orb finalization' for a list for valid souls to finalize.", caster);
	remove();
	return;
    }
    if(args == "bone man") {
	if(caster->query_level() < 1) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("bone man souls") < 1) {
	    message("info", "This orb does not contain a bone man soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (600/power) - bonus;
	set_property("long term exp", 2*(125+exp));
    }
    if(args == "rotted zombie") {
	if(caster->query_level() < 3) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("rotted zombie souls") < 1) {
	    message("info", "This orb does not contain a rotted zombie soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (900/power) - bonus;
	set_property("long term exp", 2*(125+exp));
    }
    if(args == "skeletal zombie") {
	if(caster->query_level() < 4) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("skeletal zombie souls") < 1) {
	    message("info", "This orb does not contain a skeletal zombie soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (1200/power) - bonus;
	set_property("long term exp", 3*(125+exp));
    }
    if(args == "revenant") {
	if(caster->query_level() < 5) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("revenant souls") < 1) {
	    message("info", "This orb does not contain a revenant soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (1500/power) - bonus;
	set_property("long term exp", 4*(125+exp));
    }
    if(args == "blood hound") {
	if(caster->query_level() < 7) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("blood hound souls") < 1) {
	    message("info", "This orb does not contain a blood hound soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (2100/power) - bonus;
	set_property("long term exp", 6*(125+exp));
    }
    if(args == "bone hound") {
	if(caster->query_level() < 9) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("bone hound souls") < 1) {
	    message("info", "This orb does not contain a bone hound soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (2700/power) - bonus;
	set_property("long term exp", 12*(125+exp));
    }
    if(args == "undead beast") {
	if(caster->query_level() < 10) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("undead beast souls") < 1) {
	    message("info", "This orb does not contain an undead beast soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (3600/power) - bonus;
	set_property("long term exp", 17*(125+exp));
    }
    if(args == "ghost") {
	if(caster->query_level() < 12) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("ghost souls") < 1) {
	    message("info", "This orb does not contain a ghost soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (4500/power) - bonus;
	set_property("long term exp", 33*(125+exp));
    }
    if(args == "ghast dog") {
	if(caster->query_level() < 14) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("ghast dog souls") < 1) {
	    message("info", "This orb does not contain a ghast dog soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (4500/power) - bonus;
	set_property("long term exp", 60*(125+exp));
    }
    if(args == "zombie spirit") {
	if(caster->query_level() < 15) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("zombie spirit souls") < 1) {
	    message("info", "This orb does not contain a zombie spirit soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (5700/power) - bonus;
	set_property("long term exp", 81*(125+exp));
    }
    if(args == "skeletal essence") {
	if(caster->query_level() < 18) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("skeletal essence souls") < 1) {
	    message("info", "This orb does not contain a skeletal essence soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (7200/power) - bonus;
	set_property("long term exp", 174*(125+exp));
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
