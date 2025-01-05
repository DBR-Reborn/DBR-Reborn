#define BANISHED_SKILLS ({ "pick locks" })
#define UNDEAD_RACES ({ "skeleton", "zombie", "lich", "vampire", \
          "ghoul", "ghost", "undead", "wraith" })
#include <clock.h>

inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(12);
    set_fast_dev_cost(38);
    set_property("target type", "living");
    set_property("must be present", 1);
}

void info() {
    message("help", "This skill gives a Nethermancer the ability to exert powerful control over his or her undead creations, forcing them to perform various specified actions. There is no limit to the number of times that this skill may be used on an undead, but the value of the skill combined with the level of the pet that it is being used on determines whether of not it is successful. If a suggestion does not succeed, there is a twenty round delay before it can be retried. If the control is successful however, the skill can be used again without any type of waiting period. This skill is only effective on pets created by the Nethermancer using it, and any attempt to use it on any other pet is guaranteed to fail regardless of circumstances.\n\nSyntax: 'use undead suggestion at shadowflame templar with cast *6 decay at bladestorm'", this_player());
}

void skill_func(object from, object at, string arg) {
    object ob;
    int i;
    string arg1, arg2, *tmp;
    int success = 0;
    int skill = from->query_skill("undead suggestion");

    if((time() - (int)from->query_last_use("undead suggestion")) < 40) {
	message("info", "You must wait twenty rounds before you can attempt to use this skill again.", from);
	remove();
	return;
    }
    if(!at->query_property("nethermancer pet")) {
	message("info", "This target cannot be suggested by this skill.", from);
	from->set_last_use("undead suggestion");
	remove();
	return;
    }
    if(at->is_pet() && at->query_skill("pick locks") > 0)
	at->delete_skill("pick locks");
    if(member_array(arg, BANISHED_SKILLS) > 0) {
	message("info", "Your undead refuses to be used in this way.", from);
	remove();
	return;
    }
    if(skill > ((at->query_level()*2)+random(100))) success = 1;

    if(!success){
	from->set_last_use("undead suggestion");
	message("info", "Your attempt to suggest "+at->query_cap_name()+" is unsuccessful.", from);
	remove();
	return;
    }
from->add_exp2(5 * props["skill level"]+(this_player()->query_level()*100));
    message("info", "%^BOLD%^%^BLUE%^You force the pet to: %^RED%^"+arg+"%^RESET%^", from);
    at->force_me(arg);
    remove();
    return;
}

