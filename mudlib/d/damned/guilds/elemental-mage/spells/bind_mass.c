inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "bind mass");
    set_property("skill", "elemental magic");
    set_property("casting time", 20);
    set_property("base mp cost", 50);
    set_property("dev cost", 67);
    set_property("fast dev cost", 179);
    set_property("spell level", 12);
    set_property("moon", "luna");
    set_property("caster message", "You utter a magical incantation.");
    set_property("target message", "");
    set_property("observer message", "$C utters a magical incantation.");
    set_property("spell type", ({ "protection" }));
    set_property("must be present", 1);
    set_property("self cast", 1);
    set_property("ele protection", 35);
    set_property("duration", 300);
    return;
}

void info() {
    message("help", "This is a more powerful version of the bind lesser mass spell. It allows an Elemental Mage to bind a medium sized energy mass to his/her body to grant considerable protection against the element present within the mass for the spells duration. This spell will only be effective on an medium energy mass owned by the caster (summoned with the spell 'summon mass') and it is not stackable. Power affects duration only, and the mass used in conjuction with casting can have any amount of its energy remaining with no adverse effects. This is a self-cast spell, and will not work on anyone except the caster.\n\nSyntax: 'cast *6 bind mass at grock'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object *inv;
    string lorename;
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
	    if((int)inv[i]->query_level() != 25) {
		message("info", "Your energy mass is not a medium energy mass. You cannot bind it using this particular spell.", caster);
		caster->add_mp(props["mp cost"]);
		remove();
		return;
	    }
	    lorename = (string)inv[i]->query_property("lore name");
	    props["protection types"] = ([ ""+lorename+"" : props["ele protection"] ]);
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
