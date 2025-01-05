inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name", "edge of inertia");
    set_property("skill", "blade magic");
    set_property("casting time", 27);
    set_property("base mp cost", 118);
    set_property("dev cost", 155);
    set_property("fast dev cost", 484);
    set_property("spell level", 26);
    set_property("moon", "warzau");
    set_property("caster message", "You cast %^BLUE%^edge of inertia%^RESET%^ at $T.");
    set_property("target message", "");
    set_property("observer message", "$C casts %^BLUE%^edge of inertia%^RESET%^ at $T.");
    set_property("spell type",({}));
    set_property("duration", 360);
    set_property("must be present", 1);
    set_property("stack key", "force blade");
    set_property("stack num", 3);
    set_property("target type", "any");
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 175%\n\nThis is a powerful version of the 'force blade' spell that an Assassin may cast upon a weapon giving it a very considerable amount of energy for a limited duration. This energy once cast will significantly raise all impact, stress, and crushing damage caused by the weapon as well as criticals from all three of those tables. This spell uses the same stack key as force blade, meaning only three total of either spell in a desired combination may be stacked at any given time. Other assassin blade magic spells however can still be used on the weapon.\n\nSyntax: 'cast *6 edge of inertia at sword'", this_player());
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
	message("info", "%^BOLD%^%^CYAN%^Your weapon pulsates madly with great power.%^RESET%^", caster);
	ob->set_extra_wc(([ "impact" : 18*power, "stress" : 18*power, "crushing" : 18*power ]));
	ob->set_auto_crits(([ "impact A" : 8*power, "impact B" : 8*power, "impact C" : 4*power, "stress A" : 8*power, "stress B" : 8*power, "stress C" : 4*power, "crushing A" : 8*power, "crushing B" : 8*power, "crushing C" : 4*power ]));
	ob->set_shadow_name("edge of inertia");
	ob->start_shadow(at,props["duration"], "%^BOLD%^%^YELLOW%^Your weapon ceases pulsating as an edge of inertia spell leaves it.%^RESET%^");
    }
    else {
	message("info", "You may not currently stack any more of this spell onto this weapon.", caster);
	ob->external_destruct(ob);
    }
    remove();
    return;
}
