inherit "/std/spells/long_term_spell";

string petname;

void create() {
    ::create();
    set_property("name", "elite orb finalization");
    set_property("skill", "nether magic");
    set_property("duration", "permanent");
    set_property("casting time", 4);
    set_property("base mp cost", 447);
    set_property("dev cost", 388);
    set_property("fast dev cost", 1202);
    set_property("spell level", 48);
    set_property("caster message", "You attempt to finalize a soul of the netherworld.");
    set_property("target message", "");
    set_property("observer message", "$C attempts to finalize a soul of the netherworld.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Through the means of this spell, a master Nethermancer can magically finalize a soul orb for magical sacrifice of extraordinarily powerful abilities or for the creation of some of Daybreak Ridge's most powerful creatures. After the completion of finalization, no additional souls can be infused into the soul orb, and every soul present within that orb is eliminated except one soul of the soul type that the orb finalization is for. Orbs for souls of the fourth nether category can be finalized with this magic, and a list of all valid soul arguments including the mandatory level the caster must be at to successfully execute the finaliztion is listed directly below. This is a long-term spell (see help long-term), and requires very much real time to finish. The overall final time however can be significantly reduced by the base values of the 'elite nether arts' skill."+
      "\n\nShadowflame Templar (Level 48)\nDeath Dragon (Level 52)\nNether Lord (Level 55)\n\nSyntax: 'cast *6 elite orb finalization at orb with shadowflame templar'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    int bonus = caster->query_base_skill("elite nether arts") * 30;
    int exp = caster->query_base_skill("elite nether erudition") / 2;
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
    if(args != "shadowflame templar" && args != "death dragon" && args != "nether lord") {
	message("info", "That is not a valid argument for this spell. See 'help spell elite orb finalization' for a list for valid souls to finalize.", caster);
	remove();
	return;
    }
    if(args == "shadowflame templar") {
	if(caster->query_level() < 48) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("shadowflame templar souls") < 1) {
	    message("info", "This orb does not contain a shadowflame templar soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (30000/power) - bonus;
	set_property("long term exp", 5446*(200+exp));
    }
    if(args == "death dragon") {
	if(caster->query_level() < 52) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("death dragon souls") < 1) {
	    message("info", "This orb does not contain a death dragon soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (35000/power) - bonus;
	set_property("long term exp", 4723*(150+exp));
    }
    if(args == "nether lord") {
	if(caster->query_level() < 55) {
	    message("info", "You are not yet high enough level to finalize an orb for this particular soul.", caster);
	    remove();
	    return;
	}
	if(at->query_property("nether lord souls") < 1) {
	    message("info", "This orb does not contain a nether lord soul to be finalized for.", caster);
	    remove();
	    return;
	}
	finaltime = (40000/power) - bonus;
	set_property("long term exp", 4723*(150+exp));
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
