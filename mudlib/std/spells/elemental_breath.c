inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "elemental breath");
    set_property("skill", "elemental magic");
    set_property("casting time", 8);
    set_property("base mp cost", 150);
    set_property("dev cost", 400);
    set_property("fast dev cost", 1167);
    set_property("spell level", 40);
    set_property("moon", "warzau");
    set_property("caster message", "%^CYAN%^You emit raging elemental breath at $T!%^RESET%^"); 
    set_property("target message", "");
    set_property("observer message", "%^CYAN%^$C spews forth a vicious gust of flashing breath!%^RESET%^");
    set_property("damage multiplier", 35+(this_player()->query_level()/3));
    set_property("spell type", ({ "area damage" }));
    set_property("must be present", 1);
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "This is a spell exclusive to the Elemental Dragons summoned by powerful Elemental Mages. This attack strikes all targets in a room with the force of an extreme elemental burst in the element(s) the dragon is empowered with.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object *inv;
    object obmass;
    mapping dmg;
    string lorename1, lorename2, lorename3, lorename4;
    int loreskill1, loreskill2, loreskill3, loreskill4;
    int i;

    inv = all_inventory(environment(caster));

    inv = filter_array(inv, "filter_fun");
    for(i = 0;i < (sizeof(inv));i++) {
	if(inv[i] == caster) {
	    if(inv[i]->query_property("energy units") >= 150) {
		inv[i]->set_property("energy units", ((inv[i]->query_property("energy units")) - 150));
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
		message("info", "%^RED%^You expend %^RESET%^150 %^RED%^energy units to cast the spell.%^RESET%^", caster);
		obmass = inv[i];
		obmass->move("/d/damned/arena/trashroom");
		::spell_func(caster, at, power, args, flag);
		obmass->move(environment(caster));
		obmass->force_me("use stalk at  "+ caster->query_cap_name());
		remove();
		return;
	    }
	    if(inv[i]->query_property("energy units") < 150) {
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
    return 1;
}
