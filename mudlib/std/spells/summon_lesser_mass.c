#define VALID_LORES ({ "fire", "ice", "air", "water", "earth", "electricity", "aether", "time", "chaos", "darkness", "holy", "plasma", "radiation", "holy", "light", "nullification" })
inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "summon lesser mass");
    set_property("skill", "elemental magic");
    set_property("casting time", 30);
    set_property("base mp cost", 10);
    set_property("dev cost", 6);
    set_property("fast dev cost", 20);
    set_property("spell level", 1);
    set_property("moon", "luna");
    set_property("caster message", "You summon a small mass of energy into your surroundings!");
    set_property("target message", "");
    set_property("observer message", "$C summons a small mass of energy.");
    set_property("spell type", ({ }));
    set_property("no target", 1);
    set_property("duration", 900);
    return;
}

void info() {
    message("help", "This spell allows an Elemental Mage to call forth a small mass of energy which will serve as his/her power supply for casting various types of magic. It is considerably durable against attack, but will not retaliate if assaulted. To cast the spell, a specific lore is selected in the syntax, and all spells cast with the mass will contain that element at an intensity determined by the skill level of the lore. Once summoned, it can be bound to the casters body by certain spells or used in conjunction with casting offensive magic. Only one mass can be present in the casters vicinity at any given time, and it always follows its summoner. Each lesser energy mass called forth contains five energy units per power level. The amount of energy remaining can be detected with the skill 'query mass energy'.\n\nSyntax: 'cast *6 summon lesser mass at fire'.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;
    object *inv;
    int loreskill;
    int massnumber;

    loreskill = caster->query_skill(args+" lore");
    inv = all_inventory(environment(caster));

    if(flag) {
	message("info", "You fail to summon the energy mass, and inadvertently expend the magic power.", caster);
	remove();
	return;
    }
    if((int)caster->query_skill((string)args+" lore") == 0) {
	message("info", "%^BLUE%^The mass instantly vanishes!%^RESET%^", environment(caster));
	message("info", "You do not have the skill '"+(string)args+" lore', which is required to summon a mass containing that element.", caster);
	remove();
	return;
    }
    if(present("energy mass", environment(caster))) {
	inv = filter_array(inv, "filter_fun");
	for(massnumber = 0;massnumber < (sizeof(inv));massnumber++) {
	    if(inv[massnumber]->query_property("owner name") == (string)caster->query_name()) {
		message("info", "%^BLUE%^The mass instantly vanishes!%^RESET%^", environment(caster));
		message("info", "There is already an energy mass in your vicinity controlled by you. You may only keep one stabilized at a time.", caster);
		remove();
		return;
	    }
	}
    }
    ob = new("/d/damned/guilds/elemental-mage/summons/lesser_energy_mass.c");
    ob->set_property("energy units", 5*power);
    ob->set_property("lore power", loreskill);
    ob->set_property("lore name", (string)args);
    ob->set_property("owner name", (string)caster->query_name());
ob->set_property("lore total", 1);
    ob->set_skill("swimming", 200);
    ob->set_skill("stalk", 1000);
    ob->move(environment(caster));
    message("info", "The energy mass immediately begins to follow you.", caster);
    ob->force_me("use stalk at "+(string)caster->query_cap_name());
    caster->set_property("mass present", 1);
    return;
}

int filter_fun(object ob) {
    if(ob->query_name() == "energy mass") return 1;
    else return 0;
}
