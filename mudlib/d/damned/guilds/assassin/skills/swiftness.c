inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(16);
    set_fast_dev_cost(55);
    set_property("no target", 1);
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 125%\n\nThis skill enables an Assassin to channel his or her combat abilities into a state which provides roughly double the number of attacks per round when active. This act however due to the focus required may only be executed once every half hour of real time regardless of the skill level. The skill level does though determine directly how long the duration will be once the skill is activated.\n\nSyntax: 'use swiftness'", this_player());
}

void skill_func(object from, object at, string arg) {
    object ob;

    if((time() - (int)from->query_last_use("swiftness")) < 1800) {
	message("info", "You have not yet regained the focus required to use this skill again.", from);
	remove();
	return;
    }
    from->set_last_use("swiftness");
    seteuid(geteuid(this_object()));
    ob = new("/std/cythug/shadows/swiftness_shadow");
    ob->set_shadow_name("swiftness");
    ob->start_shadow(from, props["skill level"]); 
    message("info", "%^CYAN%^You focus your inner will and significantly increase your combat speed!%^RESET%^", from);
    message("info", (string)from->query_cap_name()+" focuses inner energy and begins moving with great speed.", environment(from), ({ from }));
    remove();
    return;
}
