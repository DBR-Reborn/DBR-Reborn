inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name", "force blade");
    set_property("skill", "blade magic");
    set_property("casting time", 21);
    set_property("base mp cost", 62);
    set_property("dev cost", 82);
    set_property("fast dev cost", 258);
    set_property("spell level", 12);
    set_property("moon", "warzau");
    set_property("caster message", "You cast %^BOLD%^%^YELLOW%^force blade%^RESET%^ at $T.");
    set_property("target message", "");
    set_property("observer message", "$C casts %^BOLD%^%^YELLOW%^force blade%^RESET%^ at $T.");
    set_property("spell type",({}));
    set_property("duration", 240);
    set_property("must be present", 1);
    set_property("stack key", "force blade");
    set_property("stack num", 3);
    set_property("target type", "any");
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: None\n\nThis spell when cast upon any weapon grants it temporary power moderately enhancing its damage and impact class criticals for the duration. This spell can be stacked a total of three times on a designated weapon, but cannot be combined with other Assassin spells also aiding the impact table.\n\nSyntax: 'cast *6 force blade at hammer'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;
    object weap;

    if(!at->is_weapon()) {
	message("info", "This spell may only be cast upon a weapon.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    ob = new("/std/spells/shadows/weapon_shadow");
	if(check_stack(at, ob)) {
	message("info", "%^BOLD%^%^CYAN%^Your weapon throbs with power.%^RESET%^", caster);
		if(power < 4 ){
		ob->set_extra_wc(([ "impact" : 6*power ]));
		ob->set_auto_crits((["impact B" : 4*power ] )); 
		}
		else{
		ob->set_extra_wc(([ "impact" : 8*power ]));
		ob->set_auto_crits((["impact B" : 6*power ] )); 
		ob->start_shadow(at,props["duration"], "%^BOLD%^%^YELLOW%^A force blade spell wears off.%^RESET%^");
		}
	}
	else{	
	message("info", "You may not currently stack any more of this spell onto this weapon.", caster);
	caster->add_mp(props["mp cost"]);
	ob->external_destruct(ob);
	}
    remove();
    return;
}

