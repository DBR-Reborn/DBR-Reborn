inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "create elemental warrior");
    set_property("skill", "elemental magic");
    set_property("casting time", 40);
    set_property("base mp cost", 105);
    set_property("dev cost", 112);
    set_property("fast dev cost", 355);
    set_property("spell level", 15);
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
    message("help", "This spell allows an Elemental Mage to call forth an Elemental Warrior, a more advanced hand to hand warrior than the likes of the lower level Elemental Fighter, by transforming a medium sized energy mass he/she owns. Upon its creation, the warrior will assume the power of the element present within the mass it was given life from and use it as melee damage, as well as for defense against similar elemental offense. Power affects duration, hp, and combat skills of the pet, and the caster is permitted to possess more than one unlike with energy masses. NOTE: Elemental Warriors cannot be toggled aggressive.\n\nSyntax: 'cast *6 create elemental warrior at energy mass'", this_player()); 
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
    if((int)at->query_level() != 25) {
	message("info", "Your energy mass is not a medium sized energy mass. You cannot transform it using this particular spell.", caster);
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
    ob = new("/d/damned/guilds/elemental-mage/summons/elemental_warrior.c");
    ob->set_property("lore name", lorename);
    ob->set_property("lore power", loreskill1);
    ob->set_up(power);
    ob->set_property("melee damage", ([ ""+lorename+"" : 40 ]));
    ob->move(environment(caster));
    ob->set_owner((string)caster->query_name());
    message("info", "%^BLUE%^The mass transforms into an Elemental Warrior!%^RESET%^", environment(caster));
    at->remove();
    remove();
    return;
}
