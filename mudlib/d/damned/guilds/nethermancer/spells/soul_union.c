inherit "/std/spells/long_term_spell";

string petname;

void create() {
    ::create();
    set_property("name", "soul union");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 181);
    set_property("dev cost", 119);
    set_property("fast dev cost", 362);
    set_property("spell level", 21);
    set_property("moon", "luna");
    set_property("caster message", "You begin to magically perform a union of damned souls.");
    set_property("target message","");
    set_property("observer message", "$C begins to magically perform a union of damned souls.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This spell allows a Nethermancer to conduct moderately powerful soul unions between souls of the second nether category. Once completed, the newly created solitary soul can be united with other souls of various intensities with other soul union magics, or the soul orb can be finalized for either sacrifice or creation of undead pets. This spell requires a charged greater nexus to present somewhere within the room of the caster as well as a soul orb to directly cast the spell upon (the orb can be bought in magic shops). This is a long-term spell (see help long-term), but its overall time can be reduced by the latent skill 'nether arts'. If you are interrupted while casting, you may resume the casting at a later time provided a nexus and the same soul orb is available. When casting the spell, an argument from the list below is required to specify the type of soul union to be executed. The list states both the souls required for and the minimum level required to perform the union."+
      "\n\nVampiric Hound (Level 21):         Blood Fiend(1), Ghast Dog(2)\nFanged Spirit (Level 23):          Blood Fiend(2), Zombie Spirit(2)\nBlack Essence (Level 25):          Ghost(6)\nRed Ghoul (Level 27):              Blood Fiend(3), Zombie Spirit(2),\n                                   Skeletal Essence(1)\nBlood Knight (Level 32):           Dark Knight(3), Fanged Spirit(2)\nEssence Warrior (Level 33):        Dark Knight(3), Black Essence(3)\n\nSyntax: 'cast *6 soul union at orb with essence warrior'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("nether arts") * 20;
    int exp = caster->query_base_skill("nether erudition") / 2;
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
    if(present("nexus", environment(caster))->query_name() == "lesser nexus") {
	message("info", "The nexus in the room is not powerful enough to perform this magic.", caster);
	remove();
	return;
    }
    if(args != "vampiric hound" && args != "fanged spirit" && args != "black essence" && args != "red ghoul" && args != "blood knight" && args != "essence warrior") {
	message("info", "That is not a valid argument for this spell. See 'help spell minor soul union' for a list for valid soul unions.", caster);
	remove();
	return;
    }
    if(args == "vampiric hound") {
	if(caster->query_level() < 21) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("blood fiend souls") < 1 || at->query_property("ghast dog souls") < 2) {
	    message("info", "There are not enough blood fiend and/or ghast dog souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (13500/power) - bonus;
	set_property("long term exp", 168*(200+exp));
    }
    if(args == "fanged spirit") {
	if(caster->query_level() < 23) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("blood fiend souls") < 2 || at->query_property("zombie spirit souls") < 2) {
	    message("info", "There are not enough blood fiend and/or zombie spirit souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (15300/power) - bonus;
	set_property("long term exp", 247*(200+exp));
    }
    if(args == "black essence") {
	if(caster->query_level() < 25) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("ghost souls") < 6) {
	    message("info", "There are not enough ghost souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (17100/power) - bonus;
	set_property("long term exp", 353*(200+exp));
    }
    if(args == "red ghoul") {
	if(caster->query_level() < 27) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("blood fiend souls") < 3 || at->query_property("zombie spirit souls") < 2 || at->query_property("skeletal essence souls") < 1) {
	    message("info", "There are not enough blood fiend, zombie spirit, and/or skeletal essence souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (18900/power) - bonus;
	set_property("long term exp", 499*(200+exp));
    }
    if(args == "blood knight") {
	if(caster->query_level() < 32) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("dark knight souls") < 3 || at->query_property("fanged spirit souls") < 2) {
	    message("info", "There are not enough dark knight and/or fanged spirit souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (21600/power) - bonus;
	set_property("long term exp", 1002*(200+exp));
    }
    if(args == "essence warrior") {
	if(caster->query_level() < 33) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("dark knight souls") < 3 || at->query_property("black essence souls") < 3) {
	    message("info", "There are not enough dark knight and/or black essence souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (22500/power) - bonus;
	set_property("long term exp", 1141*(200+exp));
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
    if(petname == "vampiric hound") {
	at->set_property("blood fiend souls", (at->query_property("blood fiend souls") - 1));
	at->set_property("ghast dog souls", (at->query_property("ghast dog souls") - 2));
	at->set_property("vampiric hound souls", (at->query_property("vampiric hound souls") + 1));
    }
    if(petname == "fanged spirit") {
	at->set_property("blood fiend souls", (at->query_property("blood fiend souls") - 2));
	at->set_property("zombie spirit souls", (at->query_property("zombie spirit souls") - 2));
	at->set_property("fanged spirit souls", (at->query_property("fanged spirit souls") + 1));
    }
    if(petname == "black essence") {
	at->set_property("ghost souls", (at->query_property("ghost souls") - 6));
	at->set_property("black essence souls", (at->query_property("black essence souls") + 1));
    }
    if(petname == "red ghoul") {
	at->set_property("blood fiend souls", (at->query_property("blood fiend souls") - 3));
	at->set_property("zombie spirit souls", (at->query_property("zombie spirit souls") - 2));
	at->set_property("skeletal essence souls", (at->query_property("skeletal essence souls") - 1));
	at->set_property("red ghoul souls", (at->query_property("red ghoul souls") + 1));
    }
    if(petname == "blood knight") {
	at->set_property("dark knight souls", (at->query_property("dark knight souls") - 3));
	at->set_property("fanged spirit souls", (at->query_property("fanged spirit souls") - 2));
	at->set_property("blood knight souls", (at->query_property("blood knight souls") + 1));
    }
    if(petname == "essence warrior") {
	at->set_property("dark knight souls", (at->query_property("dark knight souls") - 3));
	at->set_property("black essence souls", (at->query_property("black essence souls") - 3));
	at->set_property("essence warrior souls", (at->query_property("essence warrior souls") + 1));
    }
    message("info", "You finish joining the souls together to create a %^BOLD%^%^RED%^"+(string)petname+"%^RESET%^ soul!", caster);
    message("info", ""+(string)caster->query_cap_name()+" finishes performing a soul union.", environment(caster), ({ caster }));
    at->set_property("total souls", 2);
    remove();
    return;
}
