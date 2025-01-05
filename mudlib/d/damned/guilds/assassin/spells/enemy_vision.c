inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "enemy vision");
    set_property("skill", "assassin's magic");
    set_property("casting time", 6);
    set_property("base mp cost", 57);
    set_property("dev cost", 52);
    set_property("fast dev cost", 177);
    set_property("spell level", 12);
    set_property("moon", "luna");
    set_property("caster message", "You intensively concentrate to magically trace the exact location of $T.");
    set_property("target message", "%^BOLD%^%^GREEN%^You get an odd feeling that you are somehow being watched.%^RESET%^");
    set_property("observer message", "$C intensively concentrates in an attempt to trace a target's location.");
    set_property("spell type", ({ }));
    set_property("target type", "living");
    set_property("can resist", 1);
    set_property("must be present", 0);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: None\n\nThis is a highly useful spell which allows an Assassin to very intensively concentrate his/her mental energies in an attempt to trace the location of the designated target. Once traced, the spell permits for a split second the caster to see everything in the room around the target almost as if he or she was looking through their eyes. Note however that when used the target will recieve a message alerting them of your action regardless if it succeeds or is resisted. Power of the spell affects success chance against magic resistance.\n\nSyntax: 'cast *6 enemy vision at subikahn'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;

    if(flag) {
	message("info", "Your misdirect the energies of your concentration and utterly botch the spell.", caster);
	remove();
	return;
    }
    if((int)at->query_level() - (int)caster->query_level() > power) {
	message("info", "Your magical prowess is not powerful enough to follow through with the spell against that particular target.", caster);
	message("info", (string)caster->query_cap_name()+" unsuccessfully attempted to magically trace your location.", at);
	remove();
	return;
    }
    message("info", "%^CYAN%^Looking through the vision provided by "+(string)at->query_cap_name()+"'s eyes, you see the following before you:", caster);
    if(!environment(at)) {
	message("info", "A void.", caster);
	remove();
	return;
    }
    message("room_description", "\n"+(string)environment(at)->query_long(0), caster);
    message("room_exits", (string)environment(at)->query_long_exits(), caster);
    message("living_item", (string)environment(at)->describe_living_contents(({})), caster);
    message("inanimate_item", (string)environment(at)->describe_item_contents(({})), caster);
    remove();
    return;
}
