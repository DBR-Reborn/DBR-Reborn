inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "minor elemental blast");
    set_property("skill", "elemental magic");
    set_property("casting time", 2);
    set_property("dev cost", 5);
    set_property("fast dev cost", 16);
    set_property("spell level", 1);
    set_property("moon", "warzau");
    set_property("caster message", "You fire a small blast of elemental energy at $T!");
    set_property("target message", "$C fires a small blast of elemental energy at you!");
    set_property("observer message", "$C fires a small blast of elemental energy at $T.");
    set_property("damage multiplier", 2);
    set_property("spell type", ({ "damage" }));
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Energy mass units required for spell: 3\n\nThis spell fires a low level blast of elemental energy at the designated target. This spell requires energy units drawn from a mass to cast, not mp. The element(s) this spell will contain is determined by the element(s) present in the mass.\n\nSyntax: 'cast *6 minor elemental blast at kronos'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object *inv;
    mapping dmg, dmg2, dmg3, dmg4;
    string lorename1, lorename2, lorename3, lorename4;
    int loreskill1, loreskill2, loreskill3, loreskill4;
    int i;

    inv = all_inventory(environment(caster));

    inv = filter_array(inv, "filter_fun");
    for(i = 0;i < (sizeof(inv));i++) {
	if(inv[i]->query_property("owner name") == (string)caster->query_name()) {
	    if(inv[i]->query_property("energy units") >= 3) {
		inv[i]->set_property("energy units", ((inv[i]->query_property("energy units")) - 3));
		lorename1 = (string)inv[i]->query_property("lore name");
		loreskill1 = (int)inv[i]->query_property("lore power");
		lorename2 = (string)inv[i]->query_property("lore name two");
		loreskill2 = (int)inv[i]->query_property("lore power two");
		lorename3 = (string)inv[i]->query_property("lore name three");
		loreskill3 = (int)inv[i]->query_property("lore power three");
		lorename4 = (string)inv[i]->query_property("lore name four");
		loreskill4 = (int)inv[i]->query_property("lore power four");
		if(loreskill1 > 60) {
		    loreskill1 = 60;
		}
		if(loreskill2 > 60) {
		    loreskill2 = 60;
		}
		if(loreskill3 > 60) {
		    loreskill3 = 60;
		}
		if(loreskill4 > 60) {
		    loreskill4 = 60;
		}
		if(inv[i]->query_property("lore name")) {
		    dmg = ([ ""+lorename1+"" : loreskill1/4 ]);
set_property("damage types", ([ ""+lorename1+"" : loreskill1/4 ]));
		    if(inv[i]->query_property("lore name two") != 0) {
			dmg2 = ([ ""+lorename1+"" : loreskill1/4, ""+lorename2+"" : loreskill2/4 ]);
set_property("damage types", ([ ""+lorename1+"" : loreskill1/4, ""+lorename2+"" : loreskill2/4 ]));
			if(inv[i]->query_property("lore name three") != 0) {
			    dmg3 = ([ ""+lorename1+"" : loreskill1/4, ""+lorename2+"" : loreskill2/4, ""+lorename3+"" : loreskill3/4 ]);
set_property("damage types", ([ ""+lorename1+"" : loreskill1/4, ""+lorename2+"" : loreskill2/4, ""+lorename3+"" : loreskill3/4 ]));
			    if(inv[i]->query_property("lore name four") != 0) {
				dmg4 = ([ ""+lorename1+"" : loreskill1/4, ""+lorename2+"" : loreskill2/4, ""+lorename3+"" : loreskill3/4, ""+lorename4+"" : loreskill4/4 ]);
set_property("damage types", ([ ""+lorename1+"" : loreskill1/4, ""+lorename2+"" : loreskill2/4, ""+lorename3+"" : loreskill3/4, ""+lorename4+"" : loreskill4/4 ]));
			    }
			}
		    }
		}
		message("info", "%^RED%^You expend %^RESET%^3 %^RED%^energy units to cast the spell.%^RESET%^", caster);
		::spell_func(caster, at, power, args, flag);
		remove();
		return;
	    }
	    if(inv[i]->query_property("energy units") < 3) {
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
