inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(45);
    set_fast_dev_cost(142);
    set_property("no target", 1);
    return;
}

void info() {
    message("info", "Prerequisite Base Skill Requirement: 400%\n\nThis is the highest level ability available to the Assassin Guild, and a staggeringly powerful one if used intelligently. When activated, this skill will resign an Assassin to die when its duration ends regardless of his or her condition beforehand, which is longer than that of 'phase' but shorter than that of 'soul channel'. However, during that duration the Assassin is completely invincible to any offensive attack, including instant kill criticals which would slay through any other invulnerability technique. Higher skill levels increase the duration of this ability, and it cannot be stacked with other Assassin invulnerability talents once invoked.\n\nSyntax: 'use dark will'", this_player());
}

void skill_func(object from, object at, string args) {
    object ob;

    if(ob = (object)from->query("invuln shad")) {
	message("my_action", "You are already using an invulnerability skill and cannot invoke another at this time.", from);
	remove();
	return;
    }
    if(from->query_current_attacker()) {
	message("my_action", "You cannot focus the energy required to use this skill will engaged in combat.", from);
	remove();
	return;
    }

    message("my_action", "You begin to call forth dark will to render your body invulnerable.", from);
    seteuid(getuid());
    ob = new("/std/cythug/shadows/will_shadow");
    from->set("invuln shad", ob);
    ob->start_shadow(from, 0, "%^BOLD%^%^RED%^You drop lifeless to the floor!%^RESET%^");
    from->die();
    remove();
    return;
}
