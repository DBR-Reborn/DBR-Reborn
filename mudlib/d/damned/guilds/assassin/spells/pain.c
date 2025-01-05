inherit "/std/spells/spell";

object cas;

void create() {
    ::create();
    set_property("name", "pain");
    set_property("skill", "paralysis magic");
    set_property("casting time", 8);
    set_property("base mp cost", 185);
    set_property("dev cost", 325);
    set_property("fast dev cost", 999);
    set_property("spell level", 42);
    set_property("moon", "warzau");
    set_property("caster message", "You unleash powerful clear black energy at $T!");
    set_property("target message", "$C unleashes powerful clear black energy at you!");
    set_property("observer message", "$C unleashes powerful clear black energy at $T.");
    set_property("must be present", 1);
    set_property("no borrow", 1);
    set_property("can resist", 1);
    set_property("combat spell", 1);
    set_property("duration", 6);
    set_property("target type", "living");
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 250%\n\nThis is an excessively powerful stunning attack and by far the most devastating available to any of Daybreak Ridge's professions. It enables its caster to unleash powerful streams of clear black energy directly at its targets inner essence bypassing all of his/her mortal possessions that shield it. If successful, the target will be paralyzed for a fair amount of time but in addition to the paralysis will be stricken with recurring pain from the damage done to the soul every round the spell is active. Even if the stun is removed by a potion or another spell, the pain will still continue its harming until the duration expires regardless of any interventions. Due to its powerful nature this spell cannot be borrowed by an Arcane-Imbuer for scrolling.\n\nSyntax: 'cast *6 pain at gimli'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    if(flag) {
	message("info", "You misdirect the magical power and inadvertently mangle your own soul!", caster);
	at = caster;
    }

    if(random(10) < (caster->query_level() - at->query_level() + 10 + (power*2))) {
	at->set_paralyzed(props["duration"], "%^BOLD%^%^MAGENTA%^Your soul is aching in hurt and you remain motionless.%^RESET%^");
	if(!flag) {
	    message("info", "%^BOLD%^%^MAGENTA%^Your soul is mangled and you stop dead in your tracks!%^RESET%^", at);
	    call_out("pain_func", 2, at, props["duration"]/2);
	    cas = caster;
	    return;
	}
    }
    else {
	message("info", (string)caster->query_cap_name()+" unsuccessfully tried to mangle your soul.", at);
	message("info", "Your spell was insufficient in attempting to mangle "+(string)at->query_cap_name()+"'s soul.", caster);
	remove();
	return;
    }
}

void pain_func(object at, int iterations) {

    if(!at) {
	remove();
	return;
    }
    iterations--;
    message("info", "%^MAGENTA%^Your body is racked with pain!%^RESET%^", at);
    at->add_hp(-1 * random(100));
    at->kill_ob(cas, 1);
    if(iterations <= 0) {
	remove();
	return;
    }
    call_out("pain_func", 2, at, iterations);
    return;
}
