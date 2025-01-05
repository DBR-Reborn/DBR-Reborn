#include <clock.h>
//#include <colors.h>

inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(30);
    set_fast_dev_cost(81);
    set_property("no target", 1);
}

void info() {
    message("help", "Prerequisite Base Skill Requirement: 350%\n\nThis is an excessively powerful skill and one of the strongest combat abilities available to any guild in Daybreak Ridge. Using this skill, an assassin can call forth his or her most dormant and fearsome desires and rages and channel them into the living world, providing a tripling of all BASE combat skills for its duration, those of which can be seen at any time by the player command 'skills base'. The skill level of the skill directly plays a factor in how often the skill can be used and how long it will last when activated. In both cases, the values are tougher on the player than with the lower level skill 'assassin's desire' due to the greater power provided by this skill, which also cannot be combined with the former if that skill is already active. This skill is self use only, meaning that no target need be supplied when the skill is used.\n\nSyntax: 'use eternal rage'", this_player()); 
}

void skill_func(object from, object at, string arg) {
    object ob;
    int skill;
    int baseskill;

    skill = (int)from->query_skill("assassin's desire");
    baseskill = (int)from->query_base_skill("assassin's desire");

    if((time() - (int)from->query_last_use("assassin's desire")) < skill*4 + skill && !wizardp(from)) {
	message("info", "You have not yet gathered enough physical energy to utilize this ability again.", from);
	remove();
	return;
    }

    from->set_last_use("assassin's desire");
    seteuid(geteuid(this_object()));
    message("info", "%^B_BLUE%^%^RED%^Calling forth inhuman power from within, you violently explode into a earth shattering fury, voraciously hungry for new blood!%^RESET%^", from);
    ob = new("/std/spells/shadows/skill_shadow");
    ob->add_new_skill_bonus("attack", baseskill*2);
    ob->add_new_skill_bonus("offhand training", baseskill*2);
  ob->add_new_skill_bonus("mortal attack", baseskill+50);
    ob->add_new_skill_bonus("assassinations", baseskill*1);
   ob->add_new_skill_bonus("dark will", baseskill*1);
    ob->add_new_skill_bonus("knife", baseskill*2);
    ob->add_new_skill_bonus("blade", baseskill*2);
    ob->add_new_skill_bonus("flail", baseskill*2);
    ob->add_new_skill_bonus("blunt", baseskill*2);
    ob->add_new_skill_bonus("axe", baseskill*2);
    ob->set_shadow_name("assassin's desire");
    ob->start_shadow(from, (5 + skill*2), "%^CYAN%^Your raging desires of combat abruptly fade away.%^RESET%^");
    return;
}
