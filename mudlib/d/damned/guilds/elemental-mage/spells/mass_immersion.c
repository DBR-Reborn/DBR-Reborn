inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "mass immersion");
    set_property("skill", "elemental magic");
    set_property("casting time", 20);
    set_property("base mp cost", 80);
    set_property("dev cost", 74);
    set_property("fast dev cost", 238);
    set_property("spell level", 15);
    set_property("moon", "luna");
    set_property("caster message", "You utter a magical incantation.");
    set_property("target message", "");
    set_property("observer message", "$C utters a magical incantation.");
    set_property("spell type", ({ "protection" }));
    set_property("must be present", 1);
    set_property("self cast", 1);
    set_property("ele protection", 7);
    set_property("duration", 300);
    return;
}

void info() {
    message("help", "This is a greater version of the lesser mass immersion spell that allows an Elemental Mage to immerse a medium sized energy mass with his/her body, providing low but notable protection against every element and not the one present within the mass which is the case if it is binded. This spell will only work with an energy mass owned by the caster, and is non stackable including stacking with direct mass binding. Power affects only duration, and the energy left inside the mass has no bearing on the defensive assets of the spell. This spell is self-cast, meaning that it will not initiate casting if the target is anything but the caster,\n\nSyntax: 'cast *6 mass immersion at lemon'", this_player());
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
		message("info", "You cannot have more than one mass joined with your body at a given time.", caster);
		caster->add_mp(props["mp cost"]);
		remove();
		return;
	    }
	    if((int)inv[i]->query_level() != 25) {
		message("info", "Your energy mass is not a medium energy mass. You cannot immerse it using this particular spell.", caster);
		caster->add_mp(props["mp cost"]);
		remove();
		return;
	    }
	    lorename = (string)inv[i]->query_property("lore name");
	    props["protection types"] = ([ "royal" : props["ele protection"], "time" : props["ele protection"], "reflection" : props["ele protection"], "infernal" : props["ele protection"], "strike" : props["ele protection"], "stress" : props["ele protection"], "aether" : props["ele protection"], "darkness" : props["ele protection"], "holy" : props["ele protection"], "disruption" : props["ele protection"], "cold" : props["ele protection"], "vacuum" : props["ele protection"], "radiation" : props["ele protection"], "sonic" : props["ele protection"], "plasma" : props["ele protection"], "acid" : props["ele protection"], "electricity" : props["ele protection"], "impact" : props["ele protection"], "fire" : props["ele protection"], "impaling" : props["ele protection"], "cutting" : props["ele protection"], "crushing" : props["ele protection"] ]);
	message("info", "%^BLUE%^The mass immerses itself with "+ (string)caster->query_cap_name() +"!%^RESET%^", environment(caster));
	inv[i]->remove();
	caster->set("mass bind", 1);
	call_out("remove_spell", props["duration"], power, at, flag);
	::spell_func(caster, at, power, args, flag);
	remove();
	return;
    }
}
message("info", "There is no energy mass present owned by you that you can immerse.", caster);
caster->add_mp(props["mp cost"]);
remove();
return;
}

void remove_spell(int power, object caster, int flag) {
    message("info", "%^BLUE%^The mass can no longer stay immersed with your body. It quickly dissipates.%^RESET%^", caster);
    caster->set("mass bind", 0);
    remove();
    return;
}

int filter_fun(object ob) {
    if(ob->query_name() == "energy mass") return 1;
    else return 0;
}
