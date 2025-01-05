inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("name", "soul blade");
    set_property("skill", "black magic");
    set_property("casting time", 14);
    set_property("base mp cost", 118);
    set_property("dev cost", 115);
    set_property("fast dev cost", 345);
    set_property("spell level", 26);
    set_property("moon", "warzau");
    set_property("caster message", "You cast %^COLOR155%^soul blade%^RESET%^ at $T.");
    set_property("target message", "");
    set_property("observer message", "$C casts %^COLOR155%^soul blade%^RESET%^ at $T.");
    set_property("spell type",({}));
    set_property("duration", 360);
    set_property("must be present", 1);
    set_property("stack key", "soul blade");
    set_property("stack num", 3);
    set_property("target type", "any");
    return;
}

void info() {
    message("help", "This spell adds cold, unholy and impaling to your weapon.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;

int lvl;

    if(!at->is_weapon()) {
	message("info", "This spell may only be cast upon a weapon.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
lvl = (caster->query_level()/2); 
    ob = new("/std/spells/shadows/weapon_shadow");
    if(check_stack(at, ob)) {
	message("info", "%^BOLD%^%^CYAN%^Your weapon vibrates as you feel cursed souls flow into it.%^RESET%^", caster);
	ob->set_extra_wc(([ "cold" : 18*power+lvl, "unholy" : 18*power+lvl, "impaling" : 18*power+lvl ]));
	ob->set_auto_crits(([ "cold C" : 8*power+lvl, "unholy B" : 8*power+lvl, "impaling A" : 8*power+lvl ]));
	ob->set_shadow_name("soul blade");
	ob->start_shadow(at,props["duration"], "%^COLOR155%^The cursed souls leave your weapon.%^RESET%^");
    }
    else {
	message("info", "You may not currently stack any more of this spell onto this weapon.", caster);
	ob->external_destruct(ob);
    }
    remove();
    return;
}
