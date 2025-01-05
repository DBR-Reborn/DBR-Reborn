#define VALID_LORES ({ "fire", "ice", "air", "water", "earth", "electricity", "aether", "time", "chaos", "darkness", "holy", "plasma", "radiation", "holy", "light", "nullification" })
inherit "/std/spells/spell";

void create() {
    ::create();
set_property("name", "summon greater mass");
    set_property("skill", "elemental magic");
set_property("casting time", 60);
set_property("base mp cost", 90);
set_property("dev cost", 125);
set_property("fast dev cost", 390);
set_property("spell level", 20);
    set_property("moon", "luna");
set_property("caster message", "You summon a large mass of energy into your surroundings!");
    set_property("target message", "");
set_property("observer message", "$C summons a large mass of energy.");
    set_property("spell type", ({ }));
    set_property("no target", 1);
set_property("duration", 1200);
    return;
}

void info() {
message("help", "This spell permits an Elemental Mage to call forth a considerably large mass of energy to aid him/her in casting offensive magic or adding defensive protection as a source of power. The mass summoned is incredibly hard to damage, and can take excessive hurt before being destroyed. However, the mass will not retaliate if it is attacked. To cast this spell, the player selects one specific lore for the syntax, and the mass is summoned with elemental intensity determined by the lore skill level. This size mass can contain a total of TWO lores, the second of which can be added seperately with the spell 'Mass Enhancement'. Only one mass can be present owned by the caster in his or her vicinity at a given time. All masses called forth with this spell contain fourty units of energy per power level. The energy remaining can be determined using the skill 'mass properties'.\n\nSyntax: 'cast *6 summon greater mass at plasma'.", this_player());
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
ob = new("/d/damned/guilds/elemental-mage/summons/greater_energy_mass.c");
ob->set_property("energy units", 40*power);
    ob->set_property("lore power", loreskill);
    ob->set_property("lore name", (string)args);
    ob->set_property("owner name", (string)caster->query_name());
ob->set_property("lore total", 2);
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
