#include <clock.h>
//#include <colors.h>

inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(20);
    set_fast_dev_cost(55);
    set_property("no target", 1);
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 175%\n\nThis skill allows an Assassin to focus a significant deal of his/her rage together, enabling the BASE values of all combat skills, viewable with the command 'skills base', to be doubled for the duration. The level of this skill determines both duration and how often it may be utilized in combat. This skill cannot be combined with any other Assassin skills that give similar boosts to fighting skills, and it is also self use only thus no target need be supplied when activated.\n\nSyntax: 'use assassin's desire'", this_player());
}

void skill_func(object from, object at, string arg) {
    object ob;
    int skill;
    int baseskill;

    skill = (int)from->query_skill("assassin's desire");
    baseskill = (int)from->query_base_skill("assassin's desire");

    if((time() - (int)from->query_last_use("assassin's desire")) < skill*3 + skill && !wizardp(from)) {
	message("info", "You have not yet gathered enough physical energy to utilize this ability again.", from);
	remove();
	return;
    }

    from->set_last_use("assassin's desire");
    seteuid(geteuid(this_object()));
    message("info", "%^BOLD%^%^RED%^You call forth your inner desires and force yourself into a vicious rage!%^RESET%^", from);
    ob = new("/std/spells/shadows/skill_shadow");
    ob->add_new_skill_bonus("attack", baseskill);
    ob->add_new_skill_bonus("knife", baseskill);
    ob->add_new_skill_bonus("blade", baseskill);
    ob->add_new_skill_bonus("flail", baseskill);
    ob->add_new_skill_bonus("blunt", baseskill);
    ob->add_new_skill_bonus("axe", baseskill);
    ob->add_new_skill_bonus("blade", baseskill);
    ob->set_shadow_name("assassin's desire");
    ob->start_shadow(from, (5 + skill*3), "%^CYAN%^Your raging desires of combat abruptly fade away.%^RESET%^");
    return;
}
