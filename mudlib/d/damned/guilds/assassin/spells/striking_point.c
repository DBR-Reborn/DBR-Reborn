inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

void create() {
    ::create();
    set_property("skill", "blade magic");
    set_property("casting time", 26);
    set_property("base mp cost", 74);
    set_property("dev cost", 105);
    set_property("fast dev cost", 338);
    set_property("spell level", 16);
    set_property("moon", "warzau");
    set_property("caster message", "You cast %^BOLD%^%^GREEN%^striking point%^RESET%^ at $T.");
    set_property("target message", "");
    set_property("observer message", "$C casts %^BOLD%^%^GREEN%^striking point%^RESET%^ at $T.");
    set_property("spell type",({}));
    set_property("duration", 300);
    set_property("must be present", 1);
    set_property("stack key", "striking point");
    set_property("stack num", 3);
    set_property("target type", "any");
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 100%\n\nThis magic when cast by an Assassin temporarily imbues any given weapon with magical energy that significantly sharpens all of its edges. This enhancement while active notably increases all impaling and cutting class criticals caused in combat by the empowered weapon. This spell may be stacked a maximum of three times on any weapon and uses its own seperate stacking table, meaning its stackings will not affect the stacking of any other spells cast on the weapon.\n\nSyntax: 'cast *6 striking point at rapier'", this_player());
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
    if(check_stack(at, ob)){
	message("info","%^BOLD%^%^CYAN%^Your weapon significantly sharpens.%^RESET%^", caster);
	ob->set_extra_wc(([ "cutting" : 15*power, "impaling" : 15*power ]));
	ob->set_auto_crits(([ "cutting A" : 6*power, "cutting B" : 6*power, "impaling A" : 6*power, "impaling B" : 6*power ]));
	ob->set_shadow_name("striking point");
	ob->start_shadow(at,props["duration"], "%^CYAN%^Your weapon loses its magical sharpness.\n%^BOLD%^%^YELLOW%^A striking point spell wears off.");
    }
    else {
	message("info", "You may not currently stack any more of this spell onto this weapon.", caster);
	ob->external_destruct(ob);
    }
    remove();
    return;
}
