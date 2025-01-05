inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(21);
    set_fast_dev_cost(65);
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 175%\n\nThis is a significantly more potent version of the 'shadow walk' skill. It allows a trained Assassin to walk with very precise stealth, making them several times more difficult to detect by opposing perceptions while active. The skill however albeit powerful is still not a total guarantee to evade all detection should the opposition have extremely high perceptions.\n\nSyntax: 'use invisible walk'", this_player());
}

void skill_func(object from, object at, string arg) {
    object ob;

    if(ob = (object)from->query("stealth shad")) {
	if((string)ob->query_my_skill() == "shadow walk") {
	    ob->external_destruct(ob);
	    message("my_action", "You emerge from hiding and cease walking invisibly.", from);
	    remove();
	    return;
	}
	ob->external_destruct(ob);
	from->set("stealth shad", 0);
    }

    message("my_action", "You begin to walk invisibly with adeptly precise stealth.", from);
    seteuid(getuid());
   ob = new("/std/spells/shadows/stealth_shadow");
    ob->set_my_skill("shadow walk");
    ob->set_mod(3);
    ob->set_hide_skill("shadow walk");
    from->set("stealth shad", ob);
    ob->start_shadow(from);
    remove();
    return;
}
