inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(25);
    set_fast_dev_cost(77);
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 150%\n\nThis skill allows an Assassin to time phase his or her body so that it cannot recieve any harm, but at the same time can still deliver damage to opposing enemies. The training cost of this ability though is considerable and its duration is notably short, only lasting 1 round for every 10% skill level, but no damage is taken upon this ability wearing off. True invincibility is unfortunately not possible with this skill due to the fact that any instant kill criticals will negate the time phasing and still instantly slay the user. When this skill is in use no other Assassin invulnerability talents may be stacked.\n\nSyntax: 'use phase'", this_player());
}

void skill_func(object from, object at, string args) {
    object ob;
    int duration;

    duration = to_int(to_float((int)from->query_skill("phase")) / to_float(10));

    if(ob = (object)from->query("invuln shad")) {
	message("my_action", "You are already using an invulnerability skill and cannot invoke another at this time.", from);
	remove();
	return;
    }
    if((time() - (int)from->query_last_use("phase")) < 2000 - (int)from->query_skill("phase")*3) {
	message("my_action", "You must rest longer before gathering the energy to use this skill again.", from);
	remove();
	return;
    }

    message("my_action", "%^BOLD%^%^YELLOW%^You shift your body into a time phase and gain temporary invulnerability!%^RESET%^", from);
    seteuid(getuid());
    ob = new("/std/cythug/shadows/phase_shadow");
    from->set("invuln shad", ob);
    from->set_last_use("phase");
    ob->start_shadow(from, duration, "%^BOLD%^%^YELLOW%^Your body returns to its normal phasing and you are no longer invulnerable.%^RESET%^");
    remove();
    return;
}
