inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name", "minor elemental weapon");
    set_property("skill", "elemental magic");
    set_property("casting time", 11);
    set_property("dev cost", 29);
    set_property("fast dev cost", 93);
    set_property("spell level", 4);
    set_property("moon", "warzau");
    set_property("caster message", "You cast %^BOLD%^%^CYAN%^minor elemental weapon%^RESET%^ at $T.");
    set_property("target message", "");
    set_property("observer message", "$C casts %^BOLD%^%^CYAN%^minor elemental weapon%^RESET%^ at $T.");
    set_property("spell type", ({ }));
    set_property("duration", 360);
    set_property("stack key", "elemental weapon");
    set_property("stack num", 3);
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Energy mass units required for spell: 6\n\nThis spell imbues a designated weapon with a small amount of elemental energy, enabling it to increase both overall damage and critical damage in the element(s) present within that energy. This spell requires energy units drawn from a mass to cast, not mp. The element(s) this spell will contain is determined by the element(s) present in the mass.\n\nSyntax: 'cast *6 minor elemental weapon at staff'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object *inv;
    object ob;
    int i;
    string lorename1, lorename2, lorename3, lorename4;

    inv = all_inventory(environment(caster));

    if(!at->is_weapon()) {
	message("info", "You may only cast this magic upon a weapon.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(flag) {
	message("info", "Your spell has no effect, plus it cost twice the mp to cast due to its misdirection!", caster);
	caster->add_mp(-props["mp cost"]);
	remove();
	return;
    }
    inv = filter_array(inv, "filter_fun");
    for(i = 0;i < (sizeof(inv));i++) {
	if(inv[i]->query_property("owner name") == (string)caster->query_name()) {
	    if(inv[i]->query_property("energy units") >= 6) {
		inv[i]->set_property("energy units", ((inv[i]->query_property("energy units")) - 6));
		lorename1 = (string)inv[i]->query_property("lore name");
		lorename2 = (string)inv[i]->query_property("lore name two");
		lorename3 = (string)inv[i]->query_property("lore name three");
		lorename4 = (string)inv[i]->query_property("lore name four");
		ob = new("/std/spells/shadows/weapon_shadow");
		if(at->query_property("stack count") < 3) {
		    if(((string)lorename2 == 0) && ((string)lorename3 == 0) && ((string)lorename4 == 0)) {
			ob->set_extra_wc(([ ""+lorename1+"" : 6*power ]));
			message("info", "You imbue the weapon with %^BOLD%^%^YELLOW%^"+(string)lorename1+"%^RESET%^!", caster);
		    }
		    if(((string)lorename2 != 0) && ((string)lorename3 == 0) && ((string)lorename4 == 0)) {
			ob->set_extra_wc(([ ""+lorename1+"" : 6*power, ""+lorename2+"" : 6*power ]));
			message("info", "You imbue the weapon with %^BOLD%^%^YELLOW%^"+(string)lorename1+"%^RESET%^!", caster);
			message("info", "You imbue the weapon with %^BOLD%^%^YELLOW%^"+(string)lorename2+"%^RESET%^!", caster);
		    }
		    if(((string)lorename2 != 0) && ((string)lorename3 != 0) && ((string)lorename4 == 0)) {
			ob->set_extra_wc(([ ""+lorename1+"" : 6*power, ""+lorename2+"" : 6*power, ""+lorename3+"" : 6*power ]));
			message("info", "You imbue the weapon with %^BOLD%^%^YELLOW%^"+(string)lorename1+"%^RESET%^!", caster);
			message("info", "You imbue the weapon with %^BOLD%^%^YELLOW%^"+(string)lorename2+"%^RESET%^!", caster);
			message("info", "You imbue the weapon with %^BOLD%^%^YELLOW%^"+(string)lorename3+"%^RESET%^!", caster);
		    }
		    if(((string)lorename2 != 0) && ((string)lorename3 != 0) && ((string)lorename4 != 0)) {
			ob->set_extra_wc(([ ""+lorename1+"" : 6*power, ""+lorename2+"" : 6*power, ""+lorename3+"" : 6*power, ""+lorename4+"" : 6*power ]));
			message("info", "You imbue the weapon with %^BOLD%^%^YELLOW%^"+(string)lorename1+"%^RESET%^!", caster);
			message("info", "You imbue the weapon with %^BOLD%^%^YELLOW%^"+(string)lorename2+"%^RESET%^!", caster);
			message("info", "You imbue the weapon with %^BOLD%^%^YELLOW%^"+(string)lorename3+"%^RESET%^!", caster);
			message("info", "You imbue the weapon with %^BOLD%^%^YELLOW%^"+(string)lorename4+"%^RESET%^!", caster);
		    }
		    ob->set_shadow_name("elemental weapon");
		    ob->start_shadow(at, props["duration"], "%^CYAN%^The elemental power leaves your weapon.%^RESET%^");
		    at->set_property("stack count", (at->query_property("stack count") + 1));
		    message("info", "%^RED%^You expend %^RESET%^6 %^RED%^energy units to cast the spell.%^RESET%^", caster);
		    ::spell_func(caster, at, power, args, flag);
		    remove();
		    return;
		}

		if(inv[i]->query_property("energy units") < 6) {
		    message("info", "There is not enough power left in your energy mass to cast this spell.", caster);
		    remove();
		    return;
		}
	    }
	}
	if(at->query_property("stack count") > 2) {
	    message("info", "You cannot place more than three of this spell on a weapon.", caster);
	    ob->external_destruct(ob);
	    call_out("remove_spell", props["duration"], power, at, flag);
	    inv[i]->set_property("energy units", ((inv[i]->query_property("energy units")) + 6));
	    remove();
	    return;
	}
    }
    message("info", "There is no energy mass present owned by you that you can draw power from.", caster);
    remove();
    return;
}

void remove_spell(int power, object at, int flag) {
    at->set_property("stack count", (at->query_property("stack count") - 1));
    remove();
    return;
}

int filter_fun(object ob) {
    if(ob->query_name() == "energy mass") return 1;
    else return 0;
}
