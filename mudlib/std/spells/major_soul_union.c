inherit "/std/spells/long_term_spell";

string petname;

void create() {
    ::create();
    set_property("name", "major soul union");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 322);
    set_property("dev cost", 195);
    set_property("fast dev cost", 585);
    set_property("spell level", 38);
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
    message("help", "With this spell, a Nethermancer can create very powerful souls of the third nether category by the means of uniting several others together. After the union is finished, the soul created can either be united with other different souls, or the caster may finalize the orb the soul is contained within for the purposes of either undead pet creation of sacrifice. To invoke this magic, a charged greater nexus must be present in the same room as the caster, and a soul orb must be in his/her possession (orbs are available at many magic shops). This is a long-term spell (see help long-term), but its overall time can be reduced by the latent skill 'major nether arts'. If you are interrupted while casting, you may resume the casting at a later time provided a nexus and the same soul orb is available. When casting the spell, an argument from the list below is required to specify the type of soul union to be executed. The list states both the souls required for and the minimum level required to perform the union."+
      "\n\nSoul Knight (Level 38):            Chaos Shadow(4), Blood Knight(2)\nShadow Beast (Level 39):           Chaos Shadow(3), Red Ghoul(3)\nDeathmage (Level 42):              Chaos Shadow(5), Essence Warrior(5)\nGravewyrm (Level 45):              Chaos Shadow(3), Black Essence(4),\n                                   Blood Knight(3)\n\nSyntax: 'cast *6 major soul union at orb with gravewyrm'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("major nether arts") * 25;
    int exp = caster->query_base_skill("major nether erudition") / 2;
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
    if(args != "soul knight" && args != "shadow beast" && args != "deathmage" && args != "gravewyrm") {
	message("info", "That is not a valid argument for this spell. See 'help spell major soul union' for a list for valid soul unions.", caster);
	remove();
	return;
    }
    if(args == "soul knight") {
	if(caster->query_level() < 38) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("chaos shadow souls") < 4 || at->query_property("blood knight souls") < 2) {
	    message("info", "There are not enough chaos shadow and/or blood knight souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (22500/power) - bonus;
	set_property("long term exp", 2060*(200+exp));
    }
    if(args == "shadow beast") {
	if(caster->query_level() < 39) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("chaos shadow souls") < 3 || at->query_property("red ghoul souls") < 3) {
	    message("info", "There are not enough chaos shadow and/or red ghoul souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (24300/power) - bonus;
	set_property("long term exp", 2296*(200+exp));
    }
    if(args == "deathmage") {
	if(caster->query_level() < 42) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("chaos shadow souls") < 5 || at->query_property("essence warrior souls") < 5) {
	    message("info", "There are not enough chaos shadow and/or essence warrior souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (27000/power) - bonus;
	set_property("long term exp", 3128*(200+exp));
    }
    if(args == "gravewyrm") {
	if(caster->query_level() < 45) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("chaos shadow souls") < 3 && at->query_property("black essence souls") < 4 && at->query_property("blood knight souls") < 3) {
	    message("info", "There are not enough chaos shadow, black essence, and/or blood knight souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (29700/power) - bonus;
	set_property("long term exp", 4167*(200+exp));
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
    if(petname == "soul knight") {
	at->set_property("chaos shadow souls", (at->query_property("chaos shadow souls") - 4));
	at->set_property("blood knight souls", (at->query_property("blood knight souls") - 2));
	at->set_property("soul knight souls", (at->query_property("soul knight souls") + 1));
    }
    if(petname == "shadow beast") {
	at->set_property("chaos shadow souls", (at->query_property("chaos shadow souls") - 3));
	at->set_property("red ghoul souls", (at->query_property("red ghoul souls") - 3));
	at->set_property("shadow beast souls", (at->query_property("shadow beast souls") + 1));
    }
    if(petname == "deathmage") {
	at->set_property("chaos shadow souls", (at->query_property("chaos shadow souls") - 5));
	at->set_property("essence warrior souls", (at->query_property("essence warrior souls") - 5));
	at->set_property("deathmage souls", (at->query_property("deathmage souls") + 1));
    }
    if(petname == "gravewyrm") {
	at->set_property("chaos shadow souls", (at->query_property("chaos shadow souls") - 3));
	at->set_property("black essence souls", (at->query_property("black essence souls") - 4));
	at->set_property("blood knight souls", (at->query_property("blood knight souls") - 3));
	at->set_property("gravewyrm souls", (at->query_property("gravewyrm souls") + 1));
    }
    message("info", "You finish joining the souls together to create a %^BOLD%^%^RED%^"+(string)petname+"%^RESET%^ soul!", caster);
    message("info", ""+(string)caster->query_cap_name()+" finishes performing a soul union.", environment(caster), ({ caster }));
    at->set_property("total souls", 2);
    remove();
    return;
}
