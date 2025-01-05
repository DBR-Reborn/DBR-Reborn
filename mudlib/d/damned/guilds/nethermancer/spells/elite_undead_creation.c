inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "elite undead creation");
    set_property("skill", "orb manipulation");
    set_property("duration", "permanent");
    set_property("casting time", 150);
    set_property("base mp cost", 498);
    set_property("dev cost", 475);
    set_property("fast dev cost", 1471);
    set_property("spell level", 48);
    set_property("caster message", "You begin the dark ritual to raise an undead.");
    set_property("target message", "");
    set_property("observer message", "$C begins the dark ritual to raise an undead.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "With this magic a powerful Nethermancer is able to create some of the most devastating undead pets in Daybreak Ridge from transforming nether category four souls captured within finalized soul orbs. To finalize a soul orb, the spell 'elite orb finalization' is required to be cast upon one at some point in time. If the orb does not have finalized status when this spell is cast, the spell will always fail to succeed. The undead created from this spell is permanent and will follow all the commands given by its master (the undead may be asked for 'help' for further info). The pet is allowed to be set to aggressive when its owner deems it necessary, but unlike with lower Nethermancer pets ownership may NOT be transferred. When the soul is completely transformed, the orb it was inside of will explode outwards from the soul's rapid expansion. Listed below are all valid undeads that can be created through the use of this spell, including the mandatory levels the caster must have to perform the magic."+
      "\n\nShadowflame Templar (Level 48)\nDeath Dragon (Level 52)\nNether Lord (Level 55)\n\nSyntax: 'cast *6 major undead creation at orb with death dragon'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object ob;
    if(power > 10) power = 10;

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
    if(args != "shadowflame templar" && args != "death dragon" && args != "nether lord") {
	message("info", "That is not a valid argument for this spell. See 'help spell undead creation' for a list for valid undead that can be created.", caster);
	remove();
	return;
    }
    if(at->query_property(""+args+" souls") < 1) {
	message("info", "This orb is not finalized with a "+args+" soul.", caster);
	remove();
	return;
    }
    if(args == "shadowflame templar") {
	if(caster->query_level() < 48) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/shadowflame_templar.c");
	message("shout", "%^BOLD%^%^BLUE%^A storm of shadow and flame rages among the clouds as a powerful undead templar steps from the great beyond into this world!%^RESET%^", users());
    }
    if(args == "death dragon") {
	if(caster->query_level() < 52) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/death_dragon.c");
	message("shout", "%^BOLD%^%^CYAN%^An earth shattering roar is heard across the land as a devastating and grand undead dragon of death is born!%^RESET%^", users());
    }
    if(args == "nether lord") {
	if(caster->query_level() < 55) {
	    message("info", "You have not yet reached high enough level to create this undead pet.", caster);
	    remove();
	    return;
	}
	ob = new("/d/damned/guilds/nethermancer/pets/nether_lord.c");
	message("shout", "%^BOLD%^%^RED%^Blood red lightning flashes across the skies as the eerie laugh of a purely dark sorcerer awakening within this realm echoes completely throughout the land, sending a frightening chill down your entire body!%^RESET%^", users());
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
