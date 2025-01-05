inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "stun blast");
    set_property("skill", "paralysis magic");
    set_property("casting time", 4);
    set_property("base mp cost", 75);
    set_property("dev cost", 97);
    set_property("fast dev cost", 333);
    set_property("spell level", 14);
    set_property("moon", "warzau");
    set_property("caster message", "You fire a blast of stunning energy at $T!");
    set_property("target message", "$C fires a blast of stunning energy at you!");
    set_property("observer message", "$C fires a blast of stunning energy at $T.");
    set_property("must be present", 1);
    set_property("can resist", 1);
    set_property("combat spell", 1);
    set_property("duration", 10);
    set_property("target type", "living");
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 100%\n\nThis magic is a more powerful version of the spell 'mind freeze'. It enables an Assassin to fire a blast of powerful energy at a target rendering them shaken and paralyzed for a considerable length of time, which in most cases is a length of time where a stun removal ability is required to give him/her any sensible chance to get back into fair combat with the caster if used at high power.\n\nSyntax: 'cast *6 stun blast at spekkio'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    if(flag) {
	message("info", "You misdirect the energy and inadvertently paralyze yourself!", caster);
	at = caster;
    }

    if(random(10) < (caster->query_level() - at->query_level() + 10 + (power*2))) {
	at->set_paralyzed(props["duration"], "%^BOLD%^%^YELLOW%^You are paralyzed and cannot move.%^RESET%^");
	if(!flag) {
	    message("info", "%^BOLD%^%^YELLOW%^Your entire body is nastily paralyzed!%^RESET%^");
	    remove();
	    return;
	}
    }
    else {
	message("info", (string)caster->query_cap_name()+"'s spell was insufficient in attempting to paralyze you.", at);
	message("info", "Your spell was not sufficient enough to paralyze "+(string)at->query_cap_name()+".", caster);
	remove();
	return;
    }
}
