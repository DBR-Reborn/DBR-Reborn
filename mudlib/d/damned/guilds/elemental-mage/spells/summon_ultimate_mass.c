#define VALID_LORES ({ "fire", "ice", "air", "water", "earth", "electricity", "aether", "time", "chaos", "darkness", "holy", "plasma", "radiation", "holy", "light", "nullification" })
inherit "/std/spells/spell";

void create() {
    ::create();
set_property("name", "summon ultimate mass");
    set_property("skill", "elemental magic");
set_property("casting time", 150);
set_property("base mp cost", 350);
set_property("dev cost", 555);
set_property("fast dev cost", 1510);
set_property("spell level", 50);
    set_property("moon", "luna");
set_property("caster message", "You summon a %^BOLD%^%^RED%^H U G E%^RESET%^ mass of energy into your surroundings!");
    set_property("target message", "");
set_property("observer message", "$C summons a %^BOLD%^%^RED%^H U G E%^RESET%^ mass of energy.");
    set_property("spell type", ({ }));
    set_property("no target", 1);
set_property("duration", 1800);
    return;
}

void info() {
message("help", "This spell allows an Elemental Mage to summon the most powerful mass of energy possible that can be controlled by a mortal to be used as a means of casting the most powerful elemental magic. The mass has inhuman durability, and despite the fact it cannot attack back can take a disgusting amount of punishment even from the highest offensive forces in the realm. To cast this spell, the caster selects one specific lore and uses it in the syntax, summoning the mass with power in that lore based on the skill level of it. This gargantuan mass can simultaneously command FOUR elements, the other three of which can be manually added by the spell 'Mass Enhancement'. Only one mass can be present owned by the caster in his or her vicinity at a given time. All energy masses called forth with this spell come with a staggering five hundred units of energy per power level! The energy remaining can be determined using the skill 'mass properties'.\n\nSyntax: 'cast *6 summon ultimate mass at time'.", this_player());
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
ob = new("/wizards/cythug/elemental-mage/summons/ultimate_energy_mass.c");
ob->set_property("energy units", 500*power);
    ob->set_property("lore power", loreskill);
    ob->set_property("lore name", (string)args);
    ob->set_property("owner name", (string)caster->query_name());
ob->set_property("lore total", 4);
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
