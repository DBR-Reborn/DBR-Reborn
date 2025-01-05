inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "time leap");
    set_property("skill", "assassin's magic");
    set_property("casting time", 32);
    set_property("base mp cost", 177);
    set_property("dev cost", 300);
    set_property("fast dev cost", 911);
    set_property("spell level", 40);
    set_property("moon", "luna");
    set_property("caster message", "%^B_CYAN%^%^WHITE%^You invoke a powerful spell of time shifting.%^RESET%^");
    set_property("observer message", "$C prepares a powerful ritual of time shifting.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 225%\n\nThis spell permits an Assassin through heavily concentrated magic to instantaneously shift his or her body through time to materialize at the exact location of an individual wherever in the realm they are located at the time, unlike with the 'teleportation' spell where there is a notable delay before the teleport actually takes place. In order to use this spell, a mental lock must be established on the target beforehand to know exactly where and when in time the Assassin is leaping. Also take note that any room with powers that nullify teleportation magics will render this spell useless regardless if a lock is established or not. Higher power of this spell directly influences the success chance of this spell when cast upon a target, as does the targets levels.\n\nSyntax: 'cast *6 time leap at madrigel'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    int diff;
    int x, y;
    string location;

    if(!(at = (object)caster->query("scry"))) {
	message("info", "You cannot use this spell without first establishing a mental lock.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(time() > (int)caster->query("scry time")) {
	message("info", "Your mental lock has unfortunately expired on your target.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(flag) {
	message("info", "%^CYAN%^Instead of time shifting yourself to "+(string)at->query_cap_name()+"'s location, you instead end up in the Vortex!%^RESET%^", caster);
	x=random(98);
	y=random(98);
	this_player()->move_player("/d/damned/virtual/room_"+x+"_"+y+".world");
	remove();
	return;
    }

    if(wizardp(at)) {
	message("info", "This spell may not be used to time shift to an immortals' location.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(at->is_player() && !interactive(at)) {
	message("info", "This spell may not be used to time shift to the location of a link-dead player.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(environment(at)->query_property("no teleport")) {
	message("info", "Your attempt to time shift to "+(string)at->query_cap_name()+"'s location is negated by a greater power.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    diff = (int)at->query_level() - (int)caster->query_level();
    diff += 23 - (power * 3);
    if(random(20) <= diff) {
	message("info", "You complete your incantation, but it unfortunately was not powerful enough to allow for time shifting and teleportation.", caster);
	message("info", "%^GREEN%^"+(string)caster->query_cap_name()+" unsuccessfully attempted a time shifting to your location.%^RESET%^", at);
	remove();
	return;
    }
    message("info", "%^B_GREEN%^%^WHITE%^You instantly shift your body through time and end up instantaneously at "+(string)at->query_cap_name()+"'s location!%^RESET%^", caster);
    caster->move_player(environment(at), 0);
    remove();
    return;
}
