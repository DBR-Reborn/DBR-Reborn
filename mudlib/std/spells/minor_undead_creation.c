inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "minor undead creation");
    set_property("skill", "orb manipulation");
    set_property("duration", "permanent");
    set_property("casting time", 45);
    set_property("base mp cost", 39);
    set_property("dev cost", 10);
    set_property("fast dev cost", 30);
    set_property("spell level", 1);
    set_property("caster message", "You begin the dark ritual to raise an undead.");
    set_property("target message", "");
    set_property("observer message", "$C begins the dark ritual to raise an undead.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Through the use of this spell, a Nethermancer can create an undead pet from a single first nether category soul contained within a finalized soul orb. The spell 'minor orb finalization' must be cast upon the orb to finalize it at some point before casting this spell or it will always be unsuccessful until the aforementioned action is performed. The pet once activated will be permanent and will follow the owners commands (ask the pet for 'help' for more info). Ownership of the pet may be transferred at any time, and the undead can also be set to aggressive if necessary to attack any target not specifically told not to on sight. After the spell is cast and the undead is created, the finalized soul orb will be destroyed from the instant interior expansion of the soul. A list of all the valid undead that can be created by using this magic is displayed below alongside the minimum level requirements for each to be successfully created by the caster."+
      "\n\nBone Man (Level 1)\nRotted Zombie (Level 3)\nSkeletal Zombie (Level 4)\nRevenant (Level 5)\nBlood Hound (Level 7)\nBone Hound (Level 9)\nUndead Beast (Level 10)\nGhost (Level 12)\nGhast Dog (level 14)\nZombie Spirit (Level 15)\nSkeletal Essence (Level 18)\n\nSyntax: 'cast *6 minor undead creation at orb with ghast dog'", this_player());
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
    if(args != "bone man" && args != "rotted zombie" && args != "skeletal zombie" && args != "revenant" && args != "blood hound" && args != "bone hound" && args != "undead beast" && args != "ghost" && args != "ghast dog" && args != "zombie spirit" && args != "skeletal essence") {
	message("info", "That is not a valid argument for this spell. See 'help spell minor undead creation' for a list for valid undead that can be created.", caster);
	remove();
	return;
    }
    if(at->query_property(""+args+" souls") < 1) {
	message("info", "This orb is not finalized with a "+args+" soul.", caster);
	remove();
	return;
    }
    if(args == "bone man") {
	if(caster->query_level() < 1) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/bone_man.c");
    }
    if(args == "rotted zombie") {
	if(caster->query_level() < 3) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/rotted_zombie.c");
    }
    if(args == "skeletal zombie") {
	if(caster->query_level() < 4) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/skeletal_zombie.c");
    }
    if(args == "revenant") {
	if(caster->query_level() < 5) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/revenant.c");
    }
    if(args == "blood hound") {
	if(caster->query_level() < 7) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/blood_hound.c");
    }
    if(args == "bone hound") {
	if(caster->query_level() < 9) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/bone_hound.c");
    }
    if(args == "undead beast") {
	if(caster->query_level() < 10) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/undead_beast.c");
    }
    if(args == "ghost") {
	if(caster->query_level() < 12) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/ghost.c");
    }
    if(args == "ghast dog") {
	if(caster->query_level() < 14) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/ghast_dog.c");
    }
    if(args == "zombie spirit") {
	if(caster->query_level() < 15) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/zombie_spirit.c");
    }
    if(args == "skeletal essence") {
	if(caster->query_level() < 18) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/skeletal_essence.c");
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
