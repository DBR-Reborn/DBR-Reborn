inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "mass diffusion");
    set_property("skill", "elemental magic");
    set_property("casting time", 20);
    set_property("base mp cost", 50);
    set_property("dev cost", 7);
    set_property("fast dev cost", 24);
    set_property("spell level", 1);
    set_property("moon", "luna");
    set_property("caster message", "You infuse $T with shimmering energy.");
    set_property("target message", "$C infuses you with shimmering energy.");
    set_property("observer message", "$C infuses $T with shimmering energy.");
    set_property("spell type", ({ }));
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This spell allows an Elemental Mage to dispel an energy mass, whether it be that owned by someone else or his own. This spell is extremely important for it is the only quick way to clear room for a new energy mass to be summoned for casting spells if the specified mass is too low on energy. The level of the caster, power of the spell, and size of the mass determine which masses can be dispelled using this magic.\n\nSyntax: 'cast *6 mass diffusion at mass'", this_player()); 
}

void spell_func(object caster, object at, int power, string args, int flag) {

    if(flag) {
	message("info", "Your spell has no effect, and you waste your magic power.", caster);
	remove();
	return;
    }
    if((string)at->query_name() != "energy mass") {
	message("info", "This spell will only affect energy masses.", caster);
	message("info", "The energy has no affect on you.", at);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if((caster->query_level() + 10) < at->query_level() && random(100) > 15*power) {
	message("info", "You fail in your attempt to diffuse the mass.", caster);
	remove();
	return;
    }
    message("info", "You successfully dispel the energy mass!", caster);
    at->remove();
    remove();
    return;
}
