inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(13);
    set_fast_dev_cost(44);
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: None\n\nThis skill is one of the Assassin's most useful abilities as it allows stealthily movement at all times when activated. However unlike with some other more advanced stealth skills certain players and mobs can detect the invisible movement and see you perfectly if their perception skill is sufficient enough.\n\nSyntax: 'use shadow walk'", this_player());
}

void skill_func(object from, object at, string arg) {
    object ob;

    if(ob = (object)from->query("stealth shad")) {
	if((string)ob->query_my_skill() == "shadow walk") {
	    ob->external_destruct(ob);
	    message("my_action", "You come out of hiding and are no longer walking stealthily.", from);
	    remove();
	    return;
	}
	ob->external_destruct(ob);
	from->set("stealth shad", 0);
    }

    message("my_action", "You enter hiding and begin to walk about stealthily.", from);
    seteuid(getuid());
   ob = new("/std/spells/shadows/stealth_shadow");
    from->set("stealth shad", ob);
    ob->start_shadow(from);
    remove();
    return;
}
