inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "create elemental dragon");
    set_property("skill", "elemental magic");
    set_property("casting time", 75);
    set_property("base mp cost", 320);
    set_property("dev cost", 380);
    set_property("fast dev cost", 1195);
    set_property("spell level", 44);
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
    message("help", "This considerably powerful spell gives an Elemental Mage the power to transform his/her owned energy mass into a fierce Elemental Dragon, a pet among the more powerful in the realm. Dragons fight well physically, but their true strength is with the magic which consists of both single target and multi target attacks. Once created from the mass, the newly summoned dragon will have great power in combat, spell casting, and protection in all the elements present within the transformed mass. The power level this spell is cast at determines duration, hp, mp, and combat skills of the dragon notably, and the caster is permitted to own more than one dragon at a time unlike with energy masses.\n\nSyntax: 'cast *6 create elemental dragon at energy mass'", this_player());
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
    if((int)at->query_level() != 60) {
	message("info", "Your energy mass is not a huge energy mass. You cannot transform it using this particular spell.", caster);
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
    ob = new("/wizards/cythug/elemental-mage/summons/elemental_dragon.c");
    ob->set_property("lore name", lorename);
    ob->set_property("lore name two", lorename2);
    ob->set_property("lore name three", lorename3);
    ob->set_property("lore power", loreskill1);
    ob->set_property("lore power two", loreskill2);
    ob->set_property("lore power three", loreskill3);
    ob->set_property("energy units", 2000000000);
    ob->set_up(power);
    ob->set_property("melee damage", ([ ""+lorename+"" : 75, ""+lorename2+"" : 75, ""+lorename3+"" : 75 ]));
    ob->move(environment(caster));
    ob->set_owner((string)caster->query_name());
    message("info", "%^BLUE%^The mass transforms into an Elemental Dragon!%^RESET%^", environment(caster));
    at->remove();
    remove();
    return;
}
