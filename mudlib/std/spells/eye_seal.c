inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "eye seal");
    set_property("skill", "vision magic");
    set_property("casting time", 3);
    set_property("base mp cost", 35);
    set_property("dev cost", 42);
    set_property("fast dev cost", 133);
    set_property("spell level", 4);
    set_property("moon", "warzau");
    set_property("caster message", "You magically seal $T's eyes closed.");
    set_property("target message", "$C magically seals your eyes closed!");
    set_property("observer message", "$C magically seals $T's eyes closed.");
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("can resist", 1);
    set_property("duration", "until quit");
    set_property("target type", "living");
    return;
}

void info() {
    message("help", "Prerequisity Base Skill Requirement: None\n\nThis spell magically seals the eyes of its target completely shut, incredibly hindering their vision. This spell has no affect on the target's skills, but unlike other blinding magics the effect can only be removed by relogging.\n\nSyntax: 'cast *6 eye seal at kronos'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;

    if(flag) {
	message("info", "You accidently seal your own eyes shut. Oops!", caster);
	at = caster;
    }
    if(at->query_is_blind()) {
	message("info", "This target is already blinded.", caster);
	remove();
	return;
    }

    seteuid(getuid());
    ob = new("/std/cythug/shadows/lesser_blind_shadow");
    ob->set_shadow_name("eye seal");
    ob->start_shadow(at);
    call_out("remove_blind", props["duration"], ob, at);
    if(!flag) {
	message("info", "%^BOLD%^%^WHITE%^You are completely blinded!%^RESET%^", at);
	return;
    }
}

void remove_blind(object ob, object at) {
    if(at) {
	message("info", "%^BOLD%^%^WHITE%^You have regained your vision.%^RESET%^", at);
    }
    if(ob) {
	ob->external_destruct(ob);
    }
    return;
}
