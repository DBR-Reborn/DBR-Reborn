inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "create elemental fighter");
    set_property("skill", "elemental magic");
    set_property("casting time", 30);
    set_property("base mp cost", 60);
    set_property("dev cost", 52);
    set_property("fast dev cost", 161);
    set_property("spell level", 7);
    set_property("moon", "luna");
    set_property("caster message", "You recite a sacred ritual before $T.");
    set_property("target message", "");
    set_property("observer message", "$C recites a sacred ritual at $T.");
    set_property("spell type", ({ }));
    set_property("must be present", 1);
    set_property("duration", 1200);
    return;
}

void info() {
    message("help", "This spell permits an Elemental Mage to transform an existing small energy mass into an Elemental Fighter, a pet designed for hand to hand combat to aid the caster in combat against his or her designated targets. Once summoned, the fighter will assume the element present within the mass it was summoned from and also gain slight protection against offensives of that elemental nature. The power of this spell will affect both the duration, hp, and combat skills of the pet, and unlike energy masses the caster is not limited to only possessing one. NOTE: Elemental Fighters cannot be toggled aggressive.\n\nSyntax: 'cast *6 create elemental fighter at energy mass'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object ob;
    string lorename;
    string lorename2;
    string lorename3;
    string lorename4;
    string loreskill1;
    string loreskill2;
    string loreskill3;
    string loreskill4;
    int i;

    if(at->query_name() != "energy mass") {
	message("info", "Your spell has no effect.", caster);
	remove();
	return;
    }
    if(flag) {
	if(at->query_name() == "energy mass") {
	    message("info", "You inadvertently destroy the energy mass!", caster);
	    at->remove();
	    remove();
	    return;
	}
	message("info", "Your spell has no effect.", caster);
	remove();
	return;
    }
    if((int)at->query_level() != 10) {
	message("info", "Your energy mass is not a small energy mass. You cannot transform it using this particular spell.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    lorename = (string)at->query_property("lore name");
    lorename2 = (string)at->query_property("lore name two");
    lorename3 = (string)at->query_property("lore name three");
    lorename4 = (string)at->query_property("lore name four");
    loreskill1 = (string)at->query_property("lore power");
    loreskill2 = (string)at->query_property("lore power two");
    loreskill3 = (string)at->query_property("lore power three");
    loreskill4 = (string)at->query_property("lore power four");

    seteuid(getuid());
    ob = new("/d/damned/guilds/elemental-mage/summons/elemental_fighter.c");
    ob->set_property("lore name", lorename);
    ob->set_property("lore power", loreskill1);
    ob->set_up(power);
    ob->set_property("melee damage", ([ ""+lorename+"" : 25 ])); 
    ob->move(environment(caster));
    ob->set_owner((string)caster->query_name());
    message("info", "%^BLUE%^The mass transforms into an Elemental Fighter!%^RESET%^", environment(caster));
    at->remove();
    remove();
    return;
}
