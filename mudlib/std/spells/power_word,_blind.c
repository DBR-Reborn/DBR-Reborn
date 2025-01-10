inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","power word, blind");
    set_property("skill","magery");
    set_property("casting time",2);
    set_property("base mp cost",30);
    set_property("dev cost", 45);
    set_property("fast dev cost", 110);
    set_property("spell level", 8);
    set_property("moon","warzau");
    set_property("caster message","You say a power word at $T.");
    set_property("target message","$C says a power word at you!");
    set_property("observer message","$C says a power word at $T.");
    set_property("must be present", 1);
    set_property("can resist", 1);
    set_property("save mod", "constitution");
    set_property("damage multiplier", 6);
    set_property("combat spell", 1);
    set_property("duration", 20);
    set_property("target type", "living");
    set_property("prereq", "power word, stun");
    return;
}

void info() {
    message("help",
      "This spell attempts to blind the target.",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object ob;

    if(flag) {
	message("info", "%^RED%^%^BOLD%^OOPS, You blind yourself!!!", caster);
	at = caster;
    }
    seteuid(getuid());
    ob = new("/std/spells/shadows/blind_shadow");
    ob->set_shadow_name("power word, blind");
    ob->start_shadow(at);
    call_out("remove_blind", props["duration"], ob, at);
    if(!flag)
	message("info", "%^RED%^%^BOLD%^You are blinded!", at);
    return;
}

void remove_blind(object ob, object at) {
    if(at)
	message("info", "%^CYAN%^A blinding spell wears off.", at);
    if(ob)
	ob->external_destruct(ob);
    return;
}


