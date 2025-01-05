inherit "/std/spells/spell";
inherit "/std/spells/weapon_stack_logic";

object ob;

void create() {
    ::create();
    set_property("name", "assassination blade");
    set_property("skill", "blade magic");
    set_property("casting time", 60);
    set_property("base mp cost", 245);
    set_property("dev cost", 380);
    set_property("fast dev cost", 1188);
    set_property("spell level", 38);
    set_property("moon", "warzau");
    set_property("caster message", "You cast %^RED%^assassination blade%^RESET%^ at $T.");
    set_property("target message", "");
    set_property("observer message", "$C casts %^RED%^assassination blade%^RESET%^ at $T.");
    set_property("spell type",({}));
    set_property("duration", 360);
    set_property("must be present", 1);
    set_property("stack key", "assassination blade");
    set_property("stack num", 1);
    set_property("target type", "any");
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 250%\n\nThis spell is a truly potent weapon enhancement that enables a highly trained Assassin to temporarily imbue extremely powerful energy onto a weapon. This energy for its duration will activate itself during premeditated assassination attempts and significantly increase the damage those attacks inflict upon desired foes. Only one of these spells may be present on a weapon at any given time due to its heavy potential, and it cannot be permanently locked on a weapon by an Arcane-Imbuer.\n\nSyntax: 'cast *6 assassination blade at dagger'", this_player());
}
void spell_func(object caster, object at, int power, string args, int flag) {
    object weap;

    if(!at->is_weapon()) {
	message("info", "This spell may only be cast upon a weapon.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    if(!at->query("assassination stack")) {
	message("info","%^BOLD%^%^MAGENTA%^Your weapon shimmers with swift potent energy.%^RESET%^", caster);
	at->set("assassination mod", power);
	at->set("assassination stack", 1);
	ob = new("/std/cythug/shadows/assassination_shadow");
	ob->set_shadow_name("assassination blade");
	ob->start_shadow(at, props["duration"], "%^CYAN%^Your weapon ceases to shimmer as the swift energy escapes into the thin air.%^RESET%^");
	call_out("prop_remove", props["duration"], caster, at);
    }
    else {
	message("info", "You may not currently stack any more of this spell onto this weapon.", caster);
    }
    return;
}

void prop_remove(object caster, object at) {
    at->remove("assassination mod");
    at->remove("assassination stack");
    remove();
    return;
}
