inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "planar wrath");
    set_property("skill", "elemental magic");
    set_property("casting time", 15);
    set_property("casting time", 5);
    set_property("base mp cost", 250);
    set_property("dev cost", 509);
    set_property("fast dev cost", 1414);
    set_property("spell level", 45);
    set_property("moon", "warzau");
    set_property("caster message", "%^B_WHITE%^%^RED%^You blast a roaring mass of explosive elemental power at $T!%^RESET%^");
    set_property("target message", "%^B_WHITE%^%^RED%^$C blasts a roaring mass of explosive elemental power at you!%^RESET%^");
    set_property("observer message", "%^B_WHITE%^%^RED%^$C blasts a roaring mass of explosive elemental power at $T.%^RESET%^");
    set_property("damage multiplier", 30);
    set_property("spell type", ({ "damage" }));
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This is a powerful single target spell wielded by Elemental Overlords, the most powerful Elemental Mage pet. This spell can be casted extremely quickly and causes the same damage as ultimate elemental blast.", this_player());
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
	if(inv[i] == caster) {
	    if(inv[i]->query_property("energy units") >= 380) {
		inv[i]->set_property("energy units", ((inv[i]->query_property("energy units")) - 380));
		lorename1 = (string)inv[i]->query_property("lore name");
		loreskill1 = (int)inv[i]->query_property("lore power");
		lorename2 = (string)inv[i]->query_property("lore name two");
		loreskill2 = (int)inv[i]->query_property("lore power two");
		lorename3 = (string)inv[i]->query_property("lore name three");
		loreskill3 = (int)inv[i]->query_property("lore power three");
		lorename4 = (string)inv[i]->query_property("lore name four");
		loreskill4 = (int)inv[i]->query_property("lore power four");
		if(loreskill1 > 400) {
		    loreskill1 = 400;
		}
		if(loreskill2 > 400) {
		    loreskill2 = 400;
		}
		if(loreskill3 > 400) {
		    loreskill3 = 400;
		}
		if(loreskill4 > 400) {
		    loreskill4 = 400;
		}
		if(inv[i]->query_property("lore name")) {
		    dmg = ([ ""+lorename1+"" : loreskill1/1.5 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(3/2) ]));
		if(inv[i]->query_property("lore name two") != 0) {
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(3/2), ""+lorename2+"" : loreskill2/(3/2) ]));
		if(inv[i]->query_property("lore name three") != 0) {
		    dmg = ([ ""+lorename1+"" : loreskill1/1.5, ""+lorename2+"" : loreskill2/1.5, ""+lorename3+"" : loreskill3/1.5 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(3/2), ""+lorename2+"" : loreskill2/(3/2), ""+lorename3+"" : loreskill3/(3/2) ]));
		if(inv[i]->query_property("lore name four") != 0) {
		    dmg = ([ ""+lorename1+"" : loreskill1/1.5, ""+lorename2+"" : loreskill2/1.5, ""+lorename3+"" : loreskill3/1.5, ""+lorename4+"" : loreskill4/1.5 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(3/2), ""+lorename2+"" : loreskill2/(3/2), ""+lorename3+"" : loreskill3/(3/2), ""+lorename4+"" : loreskill4/(3/2) ]));
	    }
	}
    }
}
message("info", "%^RED%^You expend %^RESET%^380 %^RED%^energy units to cast the spell.%^RESET%^", caster);
::spell_func(caster, at, power, args, flag);
remove();
return;
}
if(inv[i]->query_property("energy units") < 380) {
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
