inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "energy sphere");
    set_property("skill", "elemental magic");
    set_property("casting time", 4);
    set_property("dev cost", 61);
    set_property("fast dev cost", 170);
    set_property("base mp cost", 50);
    set_property("spell level", 17);
    set_property("moon", "warzau");
    set_property("caster message", "You blast a swirling sphere of elemental power at $T!");
    set_property("target message", "$C blasts a swirling sphere of elemental power at you!");
    set_property("observer message", "$C blasts a swirling sphere of elemental power at $T.");
    set_property("damage multiplier", 16);
    set_property("spell type", ({ "damage" }));
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "This is a spell exclusively for the Elemental Demons and Elemental Dragons that are summoned by Elemental Mages. This spell causes elemental damage based on the lores the pet is created of at the same power of major elemental blast.", this_player());
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
	    if(inv[i]->query_property("energy units") >= 30) {
		inv[i]->set_property("energy units", ((inv[i]->query_property("energy units")) - 30));
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
message("info", "%^RED%^You expend %^RESET%^30 %^RED%^energy units to cast the spell.%^RESET%^", caster);
::spell_func(caster, at, power, args, flag);
remove();
return;
}
if(inv[i]->query_property("energy units") < 30) {
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
