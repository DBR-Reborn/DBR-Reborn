#include <std.h>
#include <clock.h>

inherit "/std/skills/long_term.c";

int skill;

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(15);
    set_fast_dev_cost(43);
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("long term exp", 240);
    return;
}

void info() {
    message("help", "This skill enables a Nethermancer to create and stabilize the energies required for a lesser nexus. Once finished, the nexus will serve as the primary tool for the Nethermancer to utilize all category one soul orb sacrifices and undead creations. This skill requires a large circular ring from a magic shop to utilize, and requires an extremely high amount of time to complete (no less than two hours). The base value of this skill determines the maximum amount of charge the final nexus can contain at a given time, decided at a rate of 1 minute per percent.\n\nSyntax: 'use create lesser nexus at ring'", this_player());
}

void skill_func(object from, object at, string arg) {
    int time;

    if(!at->id("circular ring")) {
	message("info", "You may only use this skill with a circular ring.", from);
	remove();
	return;
    }
    if(at->id("circular ring") && !at->id("large circular ring")) {
	message("info", "The circular ring you are using is too large for this skill.", from);
	remove();
	return;
    }

    skill = from->query_base_skill("create lesser nexus");
    time = 7200 + (skill * 20);
    if(wizardp(from)) time = 1;

    message("info", "%^GREEN%^You begin to create and stabilize a lesser nexus.%^RESET%^", from);
    set_work_message("%^BOLD%^%^RED%^You stabilize the nexus.%^RESET%^");
    start_work(at, from, time);
    return;
}

void finish_work(object from, object at) {
    object ob;

    if(!present("large circular ring", from)) {
	message("info", "The circular ring is not present in your inventory. The long term therefore fails.", from);
	remove();
	return;
    }

    message("info", "%^YELLOW%^You have finished stabilizing the lesser nexus!%^RESET%^", from);
    message("info", "%^YELLOW%^"+(string)from->query_cap_name()+" finishes stabilizing a lesser nexus!%^RESET%^", environment(from), ({ from }));
    seteuid(geteuid(this_object()));
    ob = new("/d/damned/guilds/nethermancer/misc/lesser_nexus.c");
    ob->set_property("charge cap", (skill*9000));
    ob->move(environment(from));
    at->remove();
    remove();
    return;
}

