inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "undead restoration");
    set_property("skill", "nether magic");
    set_property("casting time", 90);
    set_property("base mp cost", 444);
    set_property("dev cost", 478);
    set_property("fast dev cost", 1502);
    set_property("spell level", 46);
    set_property("moon", "luna");
    set_property("caster message", "You magically encapsulate $T with powerful nether energy.");  
    set_property("target message", "$C magically encapsulates you with powerful nether energy.");
    set_property("observer message", "$C magically encapsulates $T with powerful nether energy.");
    set_property("spell type",({ }));
    set_property("target type", "living");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This is a particularly useful magic which permits a Nethermancer to surround one of his or her undead creations with a powerful field of energy, providing them a renewed body and restoring any limbs that it may have lost during various battles. The spell also serves the purpose of automatically reequiping their bodies with whatever weapons and armour they were wearing or wielding prior to having lost those limbs, and at high power can give other bonuses as well. For this magic to succeed when cast, a nexus must be present in the room and one minute of nexus charge is required for each level of the undead pet that is being targetted. The type of nexus this charge comes from does not matter, and once the spell goes through only the energy used for the restoration will be expended from it. If the spell fails, the amount of extra charge that is required for it to work will be reported to the caster.\n\nSyntax: 'cast *6 undead restoration at eternal darkness'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    int proceed = 0;
    int goodnexus = 0;
    int timekeeper = 1000000;
    object *inv;
    int i;

    inv = all_inventory(environment(caster));

    inv = filter_array(inv, "filter_fun");
    if((sizeof(inv)) > 0) goodnexus = 1;

    if(!at->query_property("nethermancer pet")) {
	message("info", "This spell may only be cast upon Nethermancer created undeads.", caster);
	remove();
	return;
    }
    if(flag) {
	message("info", "Instead of granting a new body to "+(string)at->query_cap_name()+", you instead destroy its current one!", caster);
	if(at->query_property("nethermancer pet")) at->die();
	remove();
	return;
    }
    for(i = 0;i < (sizeof(inv));i++) {
	if(at->query_level()*60 < inv[i]->query_property("charge remaining")) {
	    inv[i]->set_property("charge remaining", inv[i]->query_property("charge remaining") - (at->query_level()*60));
	    proceed = 1;
	}
	if(at->query_level()*60 > inv[i]->query_property("charge remaining")) {
	    if(timekeeper > (at->query_level()*60) - (inv[i]->query_property("charge remaining"))) {
		timekeeper = at->query_level()*60 - inv[i]->query_property("charge remaining");
	    }
	}
    }
    if(proceed > 0) {
	i = 10000;
    }
    if(goodnexus < 1) {
	message("info", "There is no nexus in this room that can be used to cast this spell.", caster);
	remove();
	return;
    }
    if(proceed < 1) {
	message("info", "No nexus present in this room has enough charge to successfully execute this spell.", caster);
	message("info", "The most charged nexus in this room requires "+timekeeper/60+" extra minutes of charge to do so.", caster);
	remove();
	return;
    }
    message("info", "%^BOLD%^%^WHITE%^"+(string)at->query_cap_name()+" is granted a completely new body and all of its lost limbs have been restored!%^RESET%^", environment(caster)); 
    at->new_body();
    at->force_me("equip");
    if(power > 3) at->set_hp(at->query_max_hp());
    if(power > 4) at->set_mp(at->query_max_mp());
    if(power > 5) at->add_poisoning(-(at->query_poisoning()));
    if(power > 5) at->set_property("bleeding", 0);
    remove();
    return;
}

int filter_fun(object ob) {
    if(ob->query_property("nexus class") > 0 && ob->query_property("guild nexus") < 1) return 1;
    else return 0;
}
