inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "dark breath");
    set_property("skill", "necromancy");
    set_property("casting time", 5);
    set_property("base mp cost", 355);
    set_property("dev cost", 477);
    set_property("fast dev cost", 1296);
    set_property("spell level", 44);
    set_property("moon", "warzau");
    set_property("caster message", "%^BOLD%^%^BLUE%^You breath darkness at $T.%^RESET%^");
    set_property("target message", "%^BOLD%^%^BLUE%^$C breathes darkness at you!%^RESET%^");
    set_property("observer message", "%^BOLD%^%^BLUE%^$C breathes darkness at $T.%^RESET%^");
    set_property("spell type", ({ }));
    //set_property("spell type", ({ "damage" }));
    //set_property("damage multiplier", 0);
    set_property("combat spell", 1);
    set_property("target type", "living");
    set_property("must be present", 1);
    set_property("can resist", 1);
    return;
}

void info() {
    message("help", "This is a spell used exclusively by the Death Dragon pets created by High Mortal Nethermancers. This spell is successfully landed without resistance will damage a target for exactly half of their current hit points regardless of their defense.", 
    this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
	
    at->add_hp(((int)at->query_hp() / 2) * -1);
    message("info", "%^RED%^The breath mangles your inner soul and you lose half of your hit points!%^RESET%^");
    at->kill_ob(caster, 1);
    return;
}
