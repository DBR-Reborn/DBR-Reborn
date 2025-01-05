inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "create elemental demon");
    set_property("skill", "elemental magic");
    set_property("casting time", 60);
    set_property("base mp cost", 200);
    set_property("dev cost", 250);
    set_property("fast dev cost", 777);
    set_property("spell level", 30);
    set_property("moon", "luna");
    set_property("caster message", "You recite a sacred ritual before $T.");
    set_property("target message", "");
    set_property("observer message", "$C recites a sacred ritual at $T.");
    set_property("spell type", ({ }));
    set_property("must be present", 1);
    set_property("duration", 900);
    return;
}

void info() {
    message("help", "This is a strong spell that when casted at a large energy mass owned by the caster transforms it into a powerful Elemental Demon, a pet that not only is excellent in combat but also casts single target attack spells. After transformation, the demon will possess power in its spell casting, protection, and combat derived from the element(s) of the former energy mass. Power of this magic affects the duration, hp, mp, and attack skills of the pet, and the caster may control more than one at a given time unlike the case with masses.\n\nSyntax: 'cast *6 create elemental demon at energy mass'", this_player());
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
    if((int)at->query_level() != 40) {
	message("info", "Your energy mass is not a large energy mass. You cannot transform it using this particular spell.", caster);
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
    ob = new("/wizards/cythug/elemental-mage/summons/elemental_demon.c");
    ob->set_property("lore name", lorename);
    ob->set_property("lore name two", lorename2);
    ob->set_property("lore power", loreskill1);
    ob->set_property("lore power two", loreskill2);
    ob->set_property("energy units", 2000000000);
    ob->set_up(power);
    ob->set_property("melee damage", ([ ""+lorename+"" : 50, ""+lorename2+"" : 50 ]));
    ob->move(environment(caster));
    ob->set_owner((string)caster->query_name());
    message("info", "%^BLUE%^The mass transforms into an Elemental Demon!%^RESET%^", environment(caster));
    at->remove();
    remove();
    return;
}
