inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(31);
    set_fast_dev_cost(94);
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 300%\n\nThis is the most powerful stealth ability available to any guild. It permits an Assassin to walk with complete stealth, meaning they are entirely undetectable by any level of perception while the skill is active. This skill however unlike other stealth skills has a duration for which the skill will completely fade when reached and a timed interval as to when the skill may be used again. Both values are affected by the level of the skill.\n\nSyntax: 'use master walk'", this_player());
}

void skill_func(object from, object at, string arg) {
    object ob;

    if(ob = (object)from->query("stealth shad")) {
	if((string)ob->query_my_skill() == "shadow walk") {
	    ob->external_destruct(ob);
	    message("my_action", "You cease your actions of perfect stealth.", from);
	    ob->external_destruct(ob);
	    from->set("stealth shad", 0);
	    remove();
	    return;
	}
    }
    if((time() - (int)from->query_last_use("master walk")) < 1500 - (int)from->query_skill("master walk")*3) {
	message("my_action", "You must rest longer before using this ability again.", from);
	remove();
	return;
    }

    message("my_action", "You begin walking in perfectly undetectable motion.", from);
    seteuid(getuid());
    from->set_last_use("master walk");
    ob = new("/std/cythug/shadows/master_stealth_shadow");
    ob->set_my_skill("shadow walk");
    ob->set_mod(1000);
    ob->set_hide_skill("shadow walk");
    from->set("stealth shad", ob);
    ob->start_shadow(from, (int)at->query_skill("master walk")*2, "%^CYAN%^You can no longer walk with complete stealth and emerge from the shadows.%^RESET%^");
    remove();
    return;
}
