inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "major undead creation");
    set_property("skill", "orb manipulation");
    set_property("duration", "permanent");
    set_property("casting time", 100);
    set_property("base mp cost", 302);
    set_property("dev cost", 273);
    set_property("fast dev cost", 834);
    set_property("spell level", 35);
    set_property("caster message", "You begin the dark ritual to raise an undead.");
    set_property("target message", "");
    set_property("observer message", "$C begins the dark ritual to raise an undead.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This magic allows a Nethermancer to transform a nether category three soul trapped within a finalized soul orb into a powerful undead follower. In order to finalize a soul orb for use with this spell, the spell 'major orb finalization' must be applied to it. If the orb is not finalized before casting this spell, the spell is guaranteed to fail. After its creation, the undead is permanent and will follow all orders given by its owner (for more info ask the pet for 'help'). The pet may be set to aggressive if the owner wishes it, and ownership can be transferred to another player at any time. Upon the soul transforming into an undead, its soul orb will shatter from the outward expansion of the soul during its transformation. A listing of all undeads that can be created with this magic is displayed below, with the minimum level required for each creation listed next to each individual pet."+
      "\n\nChaos Shadow (Level 35)\nSoul Knight (Level 38)\nShadow Beast (Level 39)\nDeathmage (Level 42)\nGravewyrm (Level 45)\n\nSyntax: 'cast *6 major undead creation at orb with deathmage'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object ob;
    if(power > 12) power = 12;

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
    if(args != "chaos shadow" && args != "soul knight" && args != "shadow beast" && args != "deathmage" && args != "gravewyrm") {
	message("info", "That is not a valid argument for this spell. See 'help spell undead creation' for a list for valid undead that can be created.", caster);
	remove();
	return;
    }
    if(at->query_property(""+args+" souls") < 1) {
	message("info", "This orb is not finalized with a "+args+" soul.", caster);
	remove();
	return;
    }
    if(args == "chaos shadow") {
	if(caster->query_level() < 35) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/chaos_shadow.c");
    }
    if(args == "soul knight") {
	if(caster->query_level() < 38) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/soul_knight.c");
    }
    if(args == "shadow beast") {
	if(caster->query_level() < 39) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/shadow_beast.c");
    }
    if(args == "deathmage") {
	if(caster->query_level() < 42) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/deathmage.c");
    }
    if(args == "gravewyrm") {
	if(caster->query_level() < 45) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/gravewyrm.c");
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
