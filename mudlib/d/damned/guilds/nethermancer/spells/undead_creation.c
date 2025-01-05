inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "undead creation");
    set_property("skill", "orb manipulation");
    set_property("duration", "permanent");
    set_property("casting time", 70);
    set_property("base mp cost", 172);
    set_property("dev cost", 108);
    set_property("fast dev cost", 316);
    set_property("spell level", 20);
    set_property("caster message", "You begin the dark ritual to raise an undead.");
    set_property("target message", "");
    set_property("observer message", "$C begins the dark ritual to raise an undead.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This spell gives a Nethermancer the power to give life to an undead pet of the second nether category from a soul encaptured inside of a finalized soul orb. To finalize a soul orb, the spell 'orb finalization' must be cast on the orb at some time prior to casting this magic, or else the spell will fail on the non-finalized orb. Once created, the undead pet is permanent and will obey the orders of its owner (the pet may be asked for 'help' for further info). The undead is permitted to be set to aggressive at any time by its owner, and the owner has the ability to transfer ownership to a person he or she feels worthy. When the soul is transformed into the undead, the soul orb it was contained in will be destroyed from the sheer outward force of the soul expanding from inside. Below is a listing of all the undeads that can be created by using this spell, as well as the minimum level the caster is required to have in order to create that particular undead."+
      "\n\nBlood Fiend (Level 20)\nVampiric Hound (Level 21)\nFanged Spirit (Level 23)\nBlack Essence (Level 25)\nRed Ghoul (Level 27)\nDark Knight (Level 30)\nBlood Knight (Level 32)\nEssence Warrior (Level 33)\n\nSyntax: 'cast *6 undead creation at orb with blood knight'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object ob;

    if(!at->id("soul orb")) {
	message("info", "This spell may only be cast at a soul orb.", caster);
	remove();
	return;
    }
    if(at->query_property("soul orb finalize") < 1) {
	message("info", "The soul orb has not yet been finalized and cannot be transformed into an undead.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "%^BOLD%^%^RED%^You inadvertently misdirect the energy and remove the soul orb's finalization!", caster);
	at->set_property("soul orb finalize", 0);
	at->set_short("A soul orb");
	remove();
	return;
    }
    if(args != "blood fiend" && args != "vampiric hound" && args != "fanged spirit" && args != "black essence" && args != "red ghoul" && args != "dark knight" && args != "blood knight" && args != "essence warrior") {
	message("info", "That is not a valid argument for this spell. See 'help spell undead creation' for a list for valid undead that can be created.", caster);
	remove();
	return;
    }
    if(at->query_property(""+args+" souls") < 1) {
	message("info", "This orb is not finalized with a "+args+" soul.", caster);
	remove();
	return;
    }
    if(args == "blood fiend") {
	if(caster->query_level() < 20) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/blood_fiend.c");
    }
    if(args == "vampiric hound") {
	if(caster->query_level() < 21) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/vampiric_hound.c");
    }
    if(args == "fanged spirit") {
	if(caster->query_level() < 23) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/fanged_spirit.c");
    }
    if(args == "black essence") {
	if(caster->query_level() < 25) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/black_essence.c");
    }
    if(args == "red ghoul") {
	if(caster->query_level() < 27) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/red_ghoul.c");
    }
    if(args == "dark knight") {
	if(caster->query_level() < 30) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/dark_knight.c");
    }
    if(args == "blood knight") {
	if(caster->query_level() < 32) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/blood_knight.c");
    }
    if(args == "essence warrior") {
	if(caster->query_level() < 33) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/essence_warrior.c");
    }
    ob->set_short(ob->query_property("pet short"));
    ob->set_up(power);
    ob->set_owner((string)caster->query_name());
    ob->move(environment(caster));
    message("info", "%^BOLD%^%^MAGENTA%^The orb shatters as its soul radiply expands outward, forming itself into a %^BOLD%^%^RED%^"+(string)args+"%^MAGENTA%^!%^RESET%^", caster);
    message("info", "%^BOLD%^%^MAGENTA%^"+(string)caster->query_cap_name()+"'s orb shatters as its soul radiply expands outward, forming itself into a %^BOLD%^%^RED%^"+(string)args+"%^MAGENTA%^!%^RESET%^", environment(caster), ({ caster }));
    at->remove();
    remove();
    return;
}
