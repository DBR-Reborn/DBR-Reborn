inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(35);
    set_fast_dev_cost(111);
    set_property("no target", 1);
    return;
}

void info() {
    message("info", "Prerequisite Base Skill Requirement: 300%\n\nThis ability enables an Assassin to channel a great deal of energy directly from his/her soul and use it to negate all inflicted pain as a more powerful version of the skill 'phase'. Its duration is approximately two and a half times that of the latter with 1 round per 4% of the skill trained, but the training cost is extremely high to complement this plus. Unlike with the latter however at the end of the duration the Assassin using the ability takes ALL damage incurred to him or her while the skill was active. Instant kill crits can still bring death even with this skill invoked, so total invincibility is not possible. No other Assassin invulnerability skills may be stacked when this skill is being used.\n\nSyntax: 'use soul channel'", this_player());
}

void skill_func(object from, object at, string args) {
    object ob;
    int duration;

    duration = to_int(to_float((int)from->query_skill("phase")) / to_float(4));

    if(ob = (object)from->query("invuln shad")) {
	message("my_action", "You are already using an invulnerability skill and cannot invoke another at this time.", from);
	remove();
	return;
    }

    message("my_action", "%^B_MAGENTA%^%^WHITE%^You channel incredible power from your soul and suddenly become immune to pain!%^RESET%^", from);
    seteuid(getuid());
    ob = new("/std/cythug/shadows/channel_shadow");
    from->set("invuln shad", ob);
    ob->start_shadow(from, duration, "%^B_MAGENTA%^%^WHITE%^Your body returns to normal and you incur all the pain you would have experienced had you not channeled the power.%^RESET%^");
    remove();
    return;
}
