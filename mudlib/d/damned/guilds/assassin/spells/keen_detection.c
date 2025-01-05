inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "keen detection");
    set_property("skill", "vision magic");
    set_property("casting time", 15);
    set_property("dev cost", 74);
    set_property("fast dev cost", 236);
    set_property("spell level", 10);
    set_property("moon", "luna");
    set_property("caster message", "You add another dimension to $T's vision, allowing detection of the invisible.");
    set_property("target message", "$C adds another dimension to your vision!");
    set_property("observer message", "$C adds another dimension to $T's vision.");
    set_property("spell type", ({ }));
    set_property("duration", 240);
    set_property("target type", "living");
    set_property("must be present", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 75%\n\nThis spell allows an Assassin to add another dimension of vision to the sight of either him or herself or another designated individual. This dimension allows the person whomever it may be to see the invisible in both their movement and if they are standing still. The spell power affects only the duration.\n\nSyntax: 'cast *6 keen detection at juszuf'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;

    if(flag) {
	message("info", "Instead of adding a dimension of vision, you instead remove one and make "+(string)at->query_cap_name()+" blind!", caster);
	message("info", (string)caster->query_cap_name()+" accidently removes a dimension of your vision and makes you completely blind!", at);
	ob = new("/std/spells/shadows/blind_shadow");
	ob->set_shadow_name("see invisible");
	ob->start_shadow(at);
	call_out("expire_blind", props["duration"], at, ob);
	return;
    }

    if(at->query("see invis")) {
	message("info", (string)at->query_cap_name()+" already has the power to see the invisible.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }

    message("info", "%^BOLD%^%^WHITE%^You have been granted the power to see the invisible!%^RESET%^", at);
    at->set("see invis", 1);
    call_out("expire_me", props["duration"], caster);
    at->set("spellups", props["name"] + "," + at->query("spellups"));
    return;
}

void expire_blind(object me, object shad) {
    if(!me || !shad) {
	remove();
	return;
    }
    shad->external_destruct(shad);
    message("info", "%^BOLD%^%^WHITE%^Your vision has returned to normal.%^RESET%^");
    remove();
    return;
}

void expire_me(object me) {
    if(!me) {
	remove();
	return;
    }
    message("info", "%^BOLD%^%^WHITE%^Your vision returns to normal, you can no longer see the invisible.%^RESET%^", me);
    me->set("see invis", 0);
    me->set("spellups", replace_string(me->query("spellups"), props["name"]+",", ""));
    me->set("spellups", replace_string(me->query("spellups"), props["name"], ""));
    remove();
    return;
}
