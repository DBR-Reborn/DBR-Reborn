inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "bind greater mass");
    set_property("skill", "elemental magic");
    set_property("casting time", 30);
    set_property("base mp cost", 145);
    set_property("dev cost", 138);
    set_property("fast dev cost", 351);
    set_property("spell level", 22);
    set_property("moon", "luna");
    set_property("caster message", "You utter a magical incantation.");
    set_property("target message", "");
    set_property("observer message", "$C utters a magical incantation.");
    set_property("spell type", ({ "protection" }));
    set_property("must be present", 1);
    set_property("self cast", 1);
    set_property("ele protection", 50);
    set_property("duration", 240);
    return;
}

void info() {
    message("help", "This is a strong defensive spell that allows an Elemental Mage to bind a large energy mass to his/her body, providing significantly high protection against the element(s) present in that mass for the duration of the spell. This spell is non-stackable, and is only effective if cast upon a large energy mass (summoned with the spell 'summon greater mass') that is owned by the caster. The mass can have any amount of energy remaining with no adverse effects, and power affects only duration. This is a self-cast spell, and will not work on anyone except the caster.\n\nSyntax: 'cast *6 bind greater mass at ulath'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object *inv;
    string lorename;
    string lorename2;
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
	    if((int)inv[i]->query_level() != 40) {
		message("info", "Your energy mass is not a large energy mass. You cannot bind it using this particular spell.", caster);
		caster->add_mp(props["mp cost"]);
		remove();
		return;
	    }
	    lorename = (string)inv[i]->query_property("lore name");
	    lorename2 = (string)inv[i]->query_property("lore name two");
	    props["protection types"] = ([ ""+lorename+"" : props["ele protection"], ""+lorename2+"" : props["ele protection"] ]);
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
