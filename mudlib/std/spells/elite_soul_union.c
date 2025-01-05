inherit "/std/spells/long_term_spell";

string petname;

void create() {
    ::create();
    set_property("name", "elite soul union");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 529);
    set_property("dev cost", 245);
    set_property("fast dev cost", 735);
    set_property("spell level", 48);
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
    message("help", "This magic enables a Nethermancer to will extraordinarily potent souls of the fourth nether category into creation by conjoining numerous other souls together as one. When the union is completed, the new soul can be further united with other souls, or its soul orb can be finalized for either magical sacrifice or undead creation. A charged master nexus is mandatory to cast this spell, as is a soul orb in the caster's inventory (orbs are available in several magic shops). This is a long-term spell (see help long-term), but its overall time can be reduced by the latent skill 'elite nether arts'. If you are interrupted while casting, you may resume the casting at a later time provided a nexus and the same soul orb is available. When casting the spell, an argument from the list below is required to specify the type of soul union to be executed. The list states both the souls required for and the minimum level required to perform the union."+
      "\n\nShadowflame Templar (Level 48):    Soul Knight(4), Shadow Beast(3),\n                                   Deathmage(2)\nDeath Dragon (Level 52):           Gravewyrm(7), Deathmage(1)\nNether Lord (Level 55):            Soul Knight(6), Shadow Beast(6),\n                                   Deathmage(6)\n\nSyntax: 'cast *6 elite soul union at orb with nether lord'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("elite nether arts") * 30;
    int exp = caster->query_base_skill("elite nether erudition") / 2;
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
    if(present("nexus", environment(caster))->query_name() != "master nexus") {
	message("info", "The nexus in the room is not powerful enough to perform this magic.", caster);
	remove();
	return;
    }
    if(args != "shadowflame templar" && args != "death dragon" && args != "nether lord") {
	message("info", "That is not a valid argument for this spell. See 'help spell minor soul union' for a list for valid soul unions.", caster);
	remove();
	return;
    }
    if(args == "shadowflame templar") {
	if(caster->query_level() < 48) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("soul knight souls") < 4 || at->query_property("shadow beast souls") < 3 || at->query_property("deathmage souls") < 2) {
	    message("info", "There are not enough soul knight, shadow beast, and/or deathmage souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (40500/power) - bonus;
	set_property("long term exp", 5446*(200+exp));
    }
    if(args == "death dragon") {
	if(caster->query_level() < 52) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("gravewyrm souls") < 7 || at->query_property("deathmage souls") < 1) {
	    message("info", "There are not enough gravewyrm and/or deathmage souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (44100/power) - bonus;
	set_property("long term exp", 4723*(150+exp));
    }
    if(args == "nether lord") {
	if(caster->query_level() < 55) {
	    message("info", "You are not yet high enough level to perform this specific soul union.", caster);
	    remove();
	    return;
	}
	if(at->query_property("soul knight souls") < 6 || at->query_property("shadow beast souls") < 6 || at->query_property("deathmage souls") < 6) {
	    message("info", "There are not enough soul knight, shadow beast, and/or deathmage souls in this orb with which to perform this union.", caster);
	    remove();
	    return;
	}
	finaltime = (49500/power) - bonus;
	set_property("long term exp", 4723*(150+exp));
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
    if(petname == "shadowflame templar") {
	at->set_property("soul knight souls", (at->query_property("soul knight souls") - 4));
	at->set_property("shadow beast souls", (at->query_property("shadow beast souls") - 3));
	at->set_property("deathmage souls", (at->query_property("deathmage souls") - 2));
	at->set_property("shadowflame templar souls", (at->query_property("shadowflame templar souls") + 1));
    }
    if(petname == "death dragon") {
	at->set_property("gravewyrm souls", (at->query_property("gravewyrm souls") - 7));
	at->set_property("deathmage souls", (at->query_property("deathmage souls") - 1));
	at->set_property("death dragon souls", (at->query_property("death dragon souls") + 1));
    }
    if(petname == "nether lord") {
	at->set_property("soul knight souls", (at->query_property("soul knight souls") - 6));
	at->set_property("shadow beast souls", (at->query_property("shadow beast souls") - 6));
	at->set_property("deathmage souls", (at->query_property("deathmage souls") - 6));
	at->set_property("nether lord souls", (at->query_property("nether lord souls") + 1));
    }
    message("info", ""+(string)caster->query_cap_name()+" finishes performing a soul union.", environment(caster), ({ caster }));
    at->set_property("total souls", 2);
    remove();
    return;
}
