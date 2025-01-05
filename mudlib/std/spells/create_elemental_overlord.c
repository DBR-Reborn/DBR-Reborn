inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "create elemental overlord");
    set_property("skill", "elemental magic");
    set_property("casting time", 100);
    set_property("base mp cost", 500);
    set_property("dev cost", 630);
    set_property("fast dev cost", 1912);
    set_property("spell level", 56);
    set_property("moon", "luna");
    set_property("caster message", "You recite a sacred ritual before $T.");
    set_property("target message", "");
    set_property("observer message", "$C recites a sacred ritual at $T.");
    set_property("spell type", ({ }));
    set_property("must be present", 1);
    set_property("duration", 600);
    return;
}

void info() {
    message("help", "This spell allows the creation of the most powerful Elemental Mage pet, the imposing and omnipotent Elemental Overlord. Transformation of this staggering pet is possible through the casting of this spell upon an ultimate energy mass, and once created is absolutely dynamite in physical combat. It also aids its incredible combat with extremely fast cast and powerful single target spells that can mow down opposition almost as fast as some strong area spells. All elements of the mass are transferred to the overlord upon transformation and greatly aid its casting, combat, and protection in each of them. Power affects duration, hp, mp, and combat values of the pet, and the caster unlike with energy masses is not limited to controlling only one at a time.\n\nSyntax: 'cast *6 create elemental overlord at energy mass'", this_player());
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
    if((int)at->query_level() != 80) {
	message("info", "Your energy mass is not an ultimate energy mass. You cannot transform it using this particular spell.", caster);
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
    ob = new("/d/damned/guilds/elemental-mage/summons/elemental_overlord.c");
    ob->set_property("lore name", lorename);
    ob->set_property("lore name two", lorename2);
    ob->set_property("lore name three", lorename3);
    ob->set_property("lore name four", lorename4);
    ob->set_property("lore power", loreskill1);
    ob->set_property("lore power two", loreskill2);
    ob->set_property("lore power three", loreskill3);
    ob->set_property("lore power four", loreskill4);
    ob->set_property("energy units", 2000000000);
    ob->set_up(power);
    ob->set_property("melee damage", ([ ""+lorename+"" : 100, ""+lorename2+"" : 100, ""+lorename3+"" : 100, ""+lorename4+"" : 100 ]));
    ob->move(environment(caster));
    ob->set_owner((string)caster->query_name());
    message("info", "%^BLUE%^The mass transforms into an Elemental Overlord!%^RESET%^", environment(caster));
    at->remove();
    remove();
    return;
}
