inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "bind extreme mass");
    set_property("skill", "elemental magic");
    set_property("casting time", 50);
    set_property("base mp cost", 212);
    set_property("dev cost", 225);
    set_property("fast dev cost", 688);
    set_property("spell level", 35);
    set_property("moon", "luna");
    set_property("caster message", "You utter a magical incantation.");
    set_property("target message", "");
    set_property("observer message", "$C utters a magical incantation.");
    set_property("spell type", ({ "protection" }));
    set_property("must be present", 1);
    set_property("self cast", 1);
    set_property("ele protection", 75);
    set_property("duration", 240);
    return;
}

void info() {
    message("help", "This is an extremely powerful spell which gives a highly trained Elemental Mage the ability to bind a huge energy mass to his or her body, which for the duration will provide near impregnable protection against the element(s) present within the mass. This spell cannot be stacked, and will only be effective if cast with a huge energy mass (summoned with the spell 'summon extreme mass') that is caster owned. Power affects only duration, and the mass can have any amount of energy left with no different effects on the power of the spell. This is a self-cast spell, and will not work on anyone except the caster.\n\nSyntax: 'cast *6 bind extreme mass at yusill'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object *inv;
    string lorename;
    string lorename2;
    string lorename3;
    int i;

    inv = all_inventory(environment(caster));
    inv = filter_array(inv, "filter_fun");

    for(i = 0;i < (sizeof(inv));i++) {
	if(inv[i]->query_property("owner name") == (string)caster->query_name()) {
	    if(flag) {
		message("info", "You inadvertently destroy the energy mass!", caster);
		inv[i]->remove();
		remove();
		return;
	    }
	    if((int)caster->query("mass bind") >= 1) {
		message("info", "You cannot have more than one mass binded to your body at a given time.", caster);
		caster->add_mp(props["mp cost"]);
		remove();
		return;
	    }
	    if((int)inv[i]->query_level() != 60) {
		message("info", "Your energy mass is not a huge energy mass. You cannot bind it using this particular spell.", caster);
		caster->add_mp(props["mp cost"]);
		remove();
		return;
	    }
	    lorename = (string)inv[i]->query_property("lore name");
	    lorename2 = (string)inv[i]->query_property("lore name two");
	    lorename3 = (string)inv[i]->query_property("lore name three");
	    props["protection types"] = ([ ""+lorename+"" : props["ele protection"], ""+lorename2+"" : props["ele protection"], ""+lorename3+"" : props["ele protection"] ]);
	message("info", "%^BLUE%^The mass becomes one with "+ (string)caster->query_cap_name() +"!%^RESET%^", environment(caster));
	inv[i]->remove();
	caster->set("mass bind", 1);
	call_out("remove_spell", props["duration"], power, at, flag);
	::spell_func(caster, at, power, args, flag);
	remove();
	return;
    }
}
message("info", "There is no energy mass present owned by you that you can bind.", caster);
caster->add_mp(props["mp cost"]);
remove();
return;
}

void remove_spell(int power, object caster, int flag) {
    message("info", "%^BLUE%^The mass can no longer stay binded to your body. It quickly dissipates.%^RESET%^", caster);
    caster->set("mass bind", 0);
    remove();
    return;
}

int filter_fun(object ob) {
    if(ob->query_name() == "energy mass") return 1;
    else return 0;
}
