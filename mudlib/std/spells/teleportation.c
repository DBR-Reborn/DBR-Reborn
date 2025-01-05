inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "teleportation");
    set_property("skill", "assassin's magic");
     set_property("casting time", 32);
    set_property("base mp cost", 67);
    set_property("dev cost", 93);
    set_property("fast dev cost", 298);
    set_property("spell level", 17);
    set_property("moon", "luna");
    set_property("caster message", "%^CYAN%^You invoke a spell of teleporation.%^RESET%^");
    set_property("observer message", "$C prepares a ritual of magical teleporation.");
    set_property("target message", "%^GREEN%^You sense someone preparing to teleport to your location.%^RESET%^");
    set_property("target observer message", "%^GREEN%^A magical light shines near $T.%^RESET%^");
    set_property("spell type",({ }));
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 75%\n\nThis magic enables an Assassin to teleport his or her body to a predetermined location determined by the position of a player fixed with a mental lock. Once the spell is cast, there will be a thirty second delay as the invocations are made and the power to perform the teleporting act is correctly focused. At the end of this delay, the Assassin will teleport to the location where the locked target was at the beginning of the delay, NOT at the end. Higher power of this spell affects only the success chances of this spell when utilized.\n\nSyntax: 'cast *6 teleportation'", this_player());

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
	message("info", "%^CYAN%^Instead of teleporting yourself to "+(string)at->query_cap_name()+", you instead end up in the Warp!%^RESET%^", caster);
	x=random(98);
	y=random(98);
	this_player()->move_player("/d/damned/virtual/room_"+x+"_"+y+".world");
	remove();
	return;
    }

    if(wizardp(at)) {
	message("info", "This spell may not be used to teleport to an immortal.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(at->is_player() && !interactive(at)) {
	message("info", "This spell may not be used to teleport to a link-dead player.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(environment(at)->query_property("no teleport")) {
	message("info", "Your attempt to teleport to "+(string)at->query_cap_name()+" is negated by a greater power.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    diff = (int)at->query_level() - (int)caster->query_level();
    diff += 23 - (power * 3);
    if(random(20) <= diff) {
	message("info", "You complete your incantation, but it unfortunately was not powerful enough to allow for teleporation.", caster);
	message("info", "%^GREEN%^"+(string)caster->query_cap_name()+" unsuccessfully attempted to begin teleporting to your location.%^RESET%^", at);
	remove();
	return;
    }
   //caster->move_player(environment(at), 0);
    location = file_name(environment(at));
    call_out("teleport_func", 15, caster, at, location);
}

void teleport_func(object caster, object at, string location) {
    message("info", "%^CYAN%^You complete your ritual and magically teleport from your location!%^RESET%^", caster);
    caster->move_player(location, 0);
    remove();
    return;
}
