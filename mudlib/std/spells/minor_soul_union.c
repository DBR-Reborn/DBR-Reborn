inherit "/std/spells/long_term_spell";

string petname;

void create() {
    ::create();
    set_property("name", "minor soul union");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 60);
    set_property("dev cost", 25);
    set_property("fast dev cost", 75);
    set_property("spell level", 4);
    set_property("moon", "luna");
    set_property("caster message", "You begin to magically perform a union of damned souls.");
    set_property("target message","");
    set_property("observer message", "$C begins to magically perform a union of damned souls.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("long term exp", 250);
    return;
}

void info() {
    message("help", "This spell permits a Nethermancer to perform numerous different types of soul unions amongst souls of the first nether category. After the union completes, the new single soul can be either united with other different types of souls, or its soul orb can be finalized for future undead creation or magical sacrificing. To use this spell, a charged lesser nexus is mandatory as well as a soul orb in the possession of the caster (available for purchase at most magic shops). This is a long-term spell (see help long-term), but its overall time can be reduced by the latent skill 'minor nether arts'. If you are interrupted while casting, you may resume the casting at a later time provided a nexus and the same soul orb is available. When casting the spell, an argument from the list below is required to specify the type of soul union to be executed. The list states both the souls required for and the minimum level required to perform the union."+
      "\n\nSkeletal Zombie (Level 4):         Rotted Zombie(1), Bone Man(2)\nRevenant (Level 5):                Rotted Zombie(3)\nBone Hound (Level 9):              Blood Hound(1), Bone Man(3)\nUndead Beast (Level 10):           Blood Hound(2), Rotted Zombie(2)\nGhast Dog (Level 14):              Ghost(1), Undead Beast(1)\nZombie Spirit (Level 15):          Ghost(2), Revenant(2)\nSkeletal Essence (Level 18):       Ghost(2), Revenant(1), Skel. Zombie(1)\n\nSyntax: 'cast *6 minor soul union at orb with skeletal essence'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("minor nether arts") * 10;
    int exp = caster->query_base_skill("minor nether erudition") / 2;
    int finaltime;

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
    if(args != "skeletal zombie" && args != "revenant" && args != "bone hound" && args != "undead beast" && args != "ghast dog" && args != "zombie spirit" && args != "skeletal essence") {
	message("info", "That is not a valid argument for this spell. See 'help spell minor soul union' for a list for valid soul unions.", caster);
	remove();
	return;
    }
    if(args == "skeletal zombie") {
	if(caster->query_level() < 4) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("bone man souls") < 2 || at->query_property("rotted zombie souls") < 1) {
	    message("info", "There are not enough bone man and/or rotted zombie souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (2700/power) - bonus;
	set_property("long term exp", 3*(125+exp));
    }
    if(args == "revenant") {
	if(caster->query_level() < 5) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("rotted zombie souls") < 3) {
	    message("info", "There are not enough rotted zombie souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (4500/power) - bonus;
	set_property("long term exp", 4*(125+exp));
    }
    if(args == "bone hound") {
	if(caster->query_level() < 9) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("bone man souls") < 3 || at->query_property("blood hound souls") < 1) {
	    message("info", "There are not enough blood hound and/or bone man souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (8100/power) - bonus;
	set_property("long term exp", 12*(125+exp));
    }
    if(args == "undead beast") {
	if(caster->query_level() < 10) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("rotted zombie souls") < 2 || at->query_property("blood hound souls") < 2) {
	    message("info", "There are not enough blood hound and/or rotted zombie souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (9900/power) - bonus;
	set_property("long term exp", 17*(125+exp));
    }
    if(args == "ghast dog") {
	if(caster->query_level() < 14) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("ghost souls") < 1 || at->query_property("undead beast souls") < 1) {
	    message("info", "There are not enough ghost and/or undead beast souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (11700/power) - bonus;
	set_property("long term exp", 60*(125+exp));
    }
    if(args == "zombie spirit") {
	if(caster->query_level() < 15) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("ghost souls") < 2 || at->query_property("revenant souls") < 2) {
	    message("info", "There are not enough ghost and/or revenant souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (13500/power) - bonus;
	set_property("long term exp", 81*(125+exp));
    }
    if(args == "skeletal essence") {
	if(caster->query_level() < 18) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("ghost souls") < 2 || at->query_property("revenant souls") < 1 || at->query_property("skeletal zombie souls") < 1) {
	    message("info", "There are not enough ghost, revenant, and/or skeletal zombie souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (15300/power) - bonus;
	set_property("long term exp", 174*(125+exp));
    }
    if(finaltime < 5) finaltime = 5;
    if(wizardp(caster)) finaltime = 1;
    message("info", "%^ORANGE%^You establish a link with the nexus in the room and begin joining the souls!%^RESET%^", caster);
    set_work_message("%^BOLD%^%^BLUE%^You join the souls.%^RESET%^");
    caster->set("nexus long term", 1);
    start_work(at, caster, finaltime, power);
    petname = args;
    return;
}

void finish_work(object caster, object at, int power) {

    if(power <= 0) {
	message("info", "BUG", environment(caster));
	remove();
	return;
    }
    if(petname == "skeletal zombie") {
	at->set_property("bone man souls", (at->query_property("bone man souls") - 2));
	at->set_property("rotted zombie souls", (at->query_property("rotted zombie souls") - 1));
	at->set_property("skeletal zombie souls", (at->query_property("skeletal zombie souls") + 1));
    }
    if(petname == "revenant") {
	at->set_property("rotted zombie souls", (at->query_property("rotted zombie souls") - 3));
	at->set_property("revenant souls", (at->query_property("revenant souls") + 1));
    }
    if(petname == "bone hound") {
	at->set_property("bone man souls", (at->query_property("bone man souls") - 3));
	at->set_property("blood hound souls", (at->query_property("blood hound souls") - 1));
	at->set_property("bone hound souls", (at->query_property("bone hound souls") + 1));
    }
    if(petname == "undead beast") {
	at->set_property("rotted zombie souls", (at->query_property("rotted zombie souls") - 2));
	at->set_property("blood hound souls", (at->query_property("blood hound souls") - 2));
	at->set_property("undead beast souls", (at->query_property("undead beast souls") + 1));
    }
    if(petname == "ghast dog") {
	at->set_property("ghost souls", (at->query_property("ghost souls") - 1));
	at->set_property("undead beast souls", (at->query_property("undead beast souls") - 1));
	at->set_property("ghast dog souls", (at->query_property("ghast dog souls") + 1));
    }
    if(petname == "zombie spirit") {
	at->set_property("ghost souls", (at->query_property("ghost souls") - 2));
	at->set_property("revenant souls", (at->query_property("revenant souls") - 2));
	at->set_property("zombie spirit souls", (at->query_property("zombie spirit souls") + 1));
    }
    if(petname == "skeletal essence") {
	at->set_property("ghost souls", (at->query_property("ghost souls") - 2));
	at->set_property("revenant souls", (at->query_property("revenant souls") - 1));
	at->set_property("skeletal zombie souls", (at->query_property("skeletal zombie souls") - 1));
	at->set_property("skeletal essence souls", (at->query_property("skeletal essence souls") + 1));
    }
    message("info", "You finish joining the souls together to create a %^BOLD%^%^RED%^"+(string)petname+"%^RESET%^ soul!", caster);
    message("info", ""+(string)caster->query_cap_name()+" finishes performing a soul union.", environment(caster), ({ caster }));
    at->set_property("total souls", 2);
    remove();
    return;
}
