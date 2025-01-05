inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "elemental onslaught");
    set_property("skill", "elemental magic");
    set_property("casting time", 22);
    set_property("dev cost", 573);
    set_property("fast dev cost", 1505);
    set_property("spell level", 43);
    set_property("moon", "warzau");
    set_property("caster message", "%^B_RED%^%^YELLOW%^You pummel $T with seven ferocious elemental blasts!%^RESET%^");
    set_property("target message", "%^B_RED%^%^YELLOW%^$C pummels you with seven ferocious elemental blasts!%^RESET%^");
    set_property("observer message", "%^B_RED%^%^YELLOW%^$C pummels $T with seven ferocious elemental blasts.%^RESET%^");
    set_property("damage multiplier", 16);
    set_property("spell type", ({ "damage", "damage", "damage", "damage", "damage", "damage", "damage" }));
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Energy mass units required for spell: 400\n\nThis extremely powerful offensive spell allows the simultaneous casting of seven major elemental blasts to strike a single target, causing extraordinary damage in the chosen element(s). Because all blasts are required to strike a single target, beware that fumbling this spell will direct every bolt at the caster. This spell requires energy units drawn from a mass to cast, not mp. The element(s) this spell will contain is determined by the element(s) present in the mass.\n\nSyntax: 'cast *6 elemental onslaught at revjak'", this_player());
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
	    if(inv[i]->query_property("energy units") >= 400) {
		inv[i]->set_property("energy units", ((inv[i]->query_property("energy units")) - 400));
		lorename1 = (string)inv[i]->query_property("lore name");
		loreskill1 = (int)inv[i]->query_property("lore power");
		lorename2 = (string)inv[i]->query_property("lore name two");
		loreskill2 = (int)inv[i]->query_property("lore power two");
		lorename3 = (string)inv[i]->query_property("lore name three");
		loreskill3 = (int)inv[i]->query_property("lore power three");
		lorename4 = (string)inv[i]->query_property("lore name four");
		loreskill4 = (int)inv[i]->query_property("lore power four");
		if(loreskill1 > 200) {
		    loreskill1 = 200;
		}
		if(loreskill2 > 200) {
		    loreskill2 = 200;
		}
		if(loreskill3 > 200) {
		    loreskill3 = 200;
		}
		if(loreskill4 > 200) {
		    loreskill4 = 200;
		}
		if(inv[i]->query_property("lore name")) {
		    dmg = ([ ""+lorename1+"" : loreskill1/2.5 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(5/2) ]));
		if(inv[i]->query_property("lore name two") != 0) {
		    dmg = ([ ""+lorename1+"" : loreskill1/2.5, ""+lorename2+"" : loreskill2/2.5 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(5/2), ""+lorename2+"" : loreskill2/(5/2) ]));
		if(inv[i]->query_property("lore name three") != 0) {
		    dmg = ([ ""+lorename1+"" : loreskill1/2.5, ""+lorename2+"" : loreskill2/2.5, ""+lorename3+"" : loreskill3/2.5 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(5/2), ""+lorename2+"" : loreskill2/(5/2), ""+lorename3+"" : loreskill3/(5/2) ]));
		if(inv[i]->query_property("lore name four") != 0) {
		    dmg = ([ ""+lorename1+"" : loreskill1/2.5, ""+lorename2+"" : loreskill2/2.5, ""+lorename3+"" : loreskill3/2.5, ""+lorename4+"" : loreskill4/2.5 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/(5/2), ""+lorename2+"" : loreskill2/(5/2), ""+lorename3+"" : loreskill3/(5/2), ""+lorename4+"" : loreskill4/(5/2) ]));
	    }
	}
    }
}
message("info", "%^RED%^You expend %^RESET%^400 %^RED%^energy units to cast the spell.%^RESET%^", caster);
::spell_func(caster, at, power, args, flag);
remove();
return;
}
if(inv[i]->query_property("energy units") < 400) {
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
