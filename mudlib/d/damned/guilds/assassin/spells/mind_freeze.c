inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "mind freeze");
    set_property("skill", "paralysis magic");
    set_property("casting time", 2);
    set_property("base mp cost", 45);
    set_property("dev cost", 66);
    set_property("fast dev cost", 202);
    set_property("spell level", 7);
    set_property("moon", "warzau");
    set_property("caster message", "You temporarily put $T's mind in stasis!");
    set_property("target message", "$C temporarily puts your mind into stasis!");
    set_property("observer message", "$C temporarily puts $T's mind into stasis.");
    set_property("must be present", 1);
    set_property("can resist", 1);
    set_property("combat spell", 1);
    set_property("duration", 2);
    set_property("target type", "living");
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: None\n\nThis spell attempts to temporarily freeze the mind and thoughts of its target, rendering them paralyzed and unable to retaliate in combat. The duration of this spell is extremely short at only one round per power level, meaning this spell cannot be relied on to win an entire battle but instead just to gain a small upper hand.\n\nSyntax: 'cast *6 mind freeze at kerozion'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    if(flag) {
	message("info", "Instead of freezing "+(string)at->query_cap_name()+"'s mind, you freeze your own!", caster);
	at = caster;
    }

    if(random(10) < (caster->query_level() - at->query_level() + 10 + (power*2))) {
	at->set_paralyzed(props["duration"], "%^RED%^Your mind is frozen prohibiting all movement.%^RESET%^");
	if(!flag) {
	    message("info", "%^RED%^Your mind has been frozen!%^RESET%^", at);
	    remove();
	    return;
	}
    }
    else {
	message("info", "Your emotional will prevents your mind from being frozen.", at);
	message("info", "You are unsuccessful in your attempt to freeze "+at->query_cap_name()+"'s mind.", caster); 
	remove();
	return;
    }
}
