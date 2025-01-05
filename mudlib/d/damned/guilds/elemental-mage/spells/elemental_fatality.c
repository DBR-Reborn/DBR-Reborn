inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "elemental fatality");
    set_property("skill", "elemental magic");
    set_property("casting time", 60);
    set_property("dev cost", 2500);
    set_property("fast dev cost", 7433);
    set_property("spell level", 59);
    set_property("moon", "warzau");
    set_property("caster message", "%^B_WHITE%^%^RED%^You unleash unsurpassed elemental wrath upon $T!%^RESET%^");
    set_property("target message", "%^B_WHITE%^%^RED%^$C unleashes unsurpassed elemental wrath upon you!%^RESET%^");
    set_property("observer message", "%^B_WHITE%^%^RED%^$C unleashes unsurpassed elemental wrath upon $T.%^RESET%^");
    set_property("damage multiplier", 23);
    set_property("spell type", ({ "damage", "damage", "damage", "damage", "damage", "damage", "damage", "damage", "damage", "damage" }));
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Energy mass units required for spell: 3500\n\nThis is the most powerful single target attack spell available to an Elemental Mage, and is so staggeringly powerful if cast with a high enough powered energy mass that it can surpass even warlock links. This spell fires TEN extreme elemental blasts at a given target, inflicting catastrophic and usually mortal damage. To cast this spell however, you must have a power bonused ultimate elemental mass, and patience for the very high casting time. Also if this spell is fumbled, all ten blasts will strike and usually kill the caster. This spell requires energy units drawn from a mass to cast, not mp. The element(s) this spell will contain is determined by the element(s) present in the mass.\n\nSyntax: 'cast *6 elemental fatality at dell'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object *inv;
    mapping dmg;
    string lorename1, lorename2, lorename3, lorename4;
    int loreskill1, loreskill2, loreskill3, loreskill4;
    int i;

    inv = all_inventory(environment(caster));

    inv = filter_array(inv, "filter_fun");
    for(i = 0;i < (sizeof(inv));i++) {
	if(inv[i]->query_property("owner name") == (string)caster->query_name()) {
	    if(inv[i]->query_property("energy units") >= 3500) {
		inv[i]->set_property("energy units", ((inv[i]->query_property("energy units")) - 3500));
		lorename1 = (string)inv[i]->query_property("lore name");
		loreskill1 = (int)inv[i]->query_property("lore power");
		lorename2 = (string)inv[i]->query_property("lore name two");
		loreskill2 = (int)inv[i]->query_property("lore power two");
		lorename3 = (string)inv[i]->query_property("lore name three");
		loreskill3 = (int)inv[i]->query_property("lore power three");
		lorename4 = (string)inv[i]->query_property("lore name four");
		loreskill4 = (int)inv[i]->query_property("lore power four");
		if(loreskill1 > 300) {
		    loreskill1 = 200;
		    loreskill1 = 300;
		}
		if(loreskill2 > 300) {
		    loreskill2 = 300;
		}
		if(loreskill3 > 300) {
		    loreskill3 = 300;
		}
		if(loreskill4 > 300) {
		    loreskill4 = 300;
		}
		if(inv[i]->query_property("lore name")) {
		    dmg = ([ ""+lorename1+"" : loreskill1/2 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/2 ]));
		    if(inv[i]->query_property("lore name two") != 0) {
			dmg = ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2 ]);
			set_property("damage types", ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2 ]));
			if(inv[i]->query_property("lore name three") != 0) {
			    dmg = ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2, ""+lorename3+"" : loreskill3/2 ]);
			    set_property("damage types", ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2, ""+lorename3+"" : loreskill3/2 ]));
			    if(inv[i]->query_property("lore name four") != 0) {
				dmg = ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2, ""+lorename3+"" : loreskill3/2, ""+lorename4+"" : loreskill4/2 ]);
				set_property("damage types", ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2, ""+lorename3+"" : loreskill3/2, ""+lorename4+"" : loreskill4/2 ]));
			    }
			}
		    }
		}
		message("info", "%^RED%^You expend %^RESET%^3500 %^RED%^energy units to cast the spell.%^RESET%^", caster);
		::spell_func(caster, at, power, args, flag);
		remove();
		return;
	    }
	    if(inv[i]->query_property("energy units") < 3500) {
		message("info", "There is not enough power left in your energy mass to cast this spell.", caster);
		remove();
		return;
	    }
	}
    }
    message("info", "There is no energy mass present owned by you that you can draw power from.", caster);
    remove();
    return;
}

int filter_fun(object ob) {
    if(ob->query_name() == "energy mass") return 1;
    else return 0;
}
