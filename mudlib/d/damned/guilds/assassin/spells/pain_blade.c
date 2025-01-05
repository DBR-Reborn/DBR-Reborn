inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "pain blade");
    set_property("skill", "blade magic");
    set_property("casting time", 55);
    set_property("base mp cost", 255);
    set_property("dev cost", 505);
    set_property("fast dev cost", 1665);
    set_property("spell level", 51);
    set_property("moon", "luna");
    set_property("caster message", "You cast %^MAGENTA%^pain blade%^RESET%^ at $T.");
    set_property("target message", "");
    set_property("observer message", "$C casts %^MAGENTA%^pain blade%^RESET%^ at $T.");
    set_property("must be present", 1);
    set_property("no borrow", 1);
    set_property("target type", "any");
    set_property("duration", 240);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 350%\n\nThis is the most powerful spell an Assassin can cast upon his or her weapon. It imbues the designated weapon with extremely potent magical energy which enables it on random hits to inflict 'pain status' on an enemy target which relieves the target of a random amount of hit points per iteration regardless of any defense. Due to the power of this spell however it may only be stacked once and it cannot be borrowed by an Arcane-Imbuer.\n\nSyntax: 'cast *6 pain blade at dagger'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object ob;
    int chance;

    chance = (power * 3);

    if(!at->is_weapon()) {
	message("info", "You must cast this spell at a weapon.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }

    if(at->query("pain blade")) {
	message("info", "You may only have one pain blade active on any weapon at a time.", caster);
	caster->add_mp(props["mp cost"]);
	remove();
	return;
    }

    if(flag) {
	message("info", "You accidently sacrifice your entire sum of magic points into your failed spell!", caster);
	chance = 0;
	caster->set_mp(0);
	remove();
	return;
    }

    at->set("pain blade", 1);
    seteuid(getuid());
    at->set_hit((: call_other, "/std/cythug/shadows/pain_blade_func", "pen_func", chance :));
    call_out("remove_spell", props["duration"], at, caster);
    return;
}

void remove_spell(object at, object caster) {
    if(!at) {
	return;
    }
    at->set_hit(0);
    if(caster) {
	message("info", "%^MAGENTA%^A pain blade spell wears off.%^RESET%^", caster);
	at->set("pain blade", 0);
	remove();
	return;
    }
}

