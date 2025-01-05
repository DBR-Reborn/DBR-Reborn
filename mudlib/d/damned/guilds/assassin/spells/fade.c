inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "fade");
    set_property("skill", "assassin's magic");
    set_property("casting time", 16);
    set_property("base mp cost", 72);
    set_property("dev cost", 111);
    set_property("fast dev cost", 348);
    set_property("spell level", 19);
    set_property("moon","luna");
    set_property("caster message", "You focus your energy attempting to fade the naked eye visibility of $T.");
    set_property("target message", "$C focuses energy attempting to fade you from the visibility of the naked eye.");
    set_property("observer message", "$C focuses energy attempting to fade the naked eye visibility of $T.");
    set_property("spell type",({ }));
    set_property("duration", 90);
    set_property("target type", "living");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 100%\n\nThis spell enables an Assassin to invoke one of their most useful abilities, the ability to make a target completely invisible to the naked eye regardless of all various perception levels. However this invisibility magic is not powerful enough to enable it to be active at all times, for if someone with this spell enters any kind of combat provoked or unprovoked its effects will be rendered useless and the spell must be cast again. Also take note that the effects can also be negated although not destroyed by certain special magics which enable one to see the invisible.\n\nSyntax: 'cast *6 fade at isarrk'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;

    seteuid(getuid());
    if(flag) {
	message("info", "You misdirect some of your magic and while your attempt to make "+(string)at->query_cap_name()+" invisible was successful, "+(string)at->query_cap_name()+" was also entirely blinded!", caster);
	message("info", "Your body is made invisible, but at the same time you have also been completely blinded!", at);
	ob = new("/std/spells/shadows/blind_shadow");
	ob->start_shadow(at);
	call_out("expire_blind", props["duration"], at, ob);
    }
    if(at->query_invis()) {
	message("info", (string)at->query_cap_name()+" is already invisible.", caster);
	message("info", "%^CYAN%^"+(string)caster->query_cap_name() +
	  "'s spell fails.", environment(caster), ({ caster }) );
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }
    message("info", "%^CYAN%^Your body phases completely out of sight!%^RESET%^", at);
    message("info", "%^CYAN%^"+(string)at->query_cap_name()+" phases completely out of sight.%^RESET%^", environment(caster), ({ caster, at }));
    ob = new("/std/spells/shadows/invis_shadow");
    ob->set_shadow_name("fade");
    ob->start_shadow(at, props["duration"], "%^CYAN%^Your body phases back to normal and you are no longer invisible.%^RESET%^");
    remove();
    return;
}
