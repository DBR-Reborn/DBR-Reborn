#include <std.h>
#include <clock.h>

inherit "/std/skills/long_term.c";

int skill;

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(30);
    set_fast_dev_cost(88);
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("long term exp", 5000);
    return;
}

void info() {
    message("help", "This skill permits a Nethermancer to create the energies needed to create a powerful greater nexus and permanently stabilize them. Upon completion, the greater nexus will serve the purpose of being the main tool for the said Nethermancer to make use of all undead raisings and soul orb sacrifices of categories one through three. This skill requires a huge circular ring from a magic shop to use, and can take as much as ten hours to fully complete once initiated. The base percent of this skill dictates the maximum charge the greater nexus can contain at any given time, determined at a rate of 1 minute for each percent.\n\nSyntax: 'use create greater nexus at ring'", this_player());
}

void skill_func(object from, object at, string arg) {
    int time;

    if(!at->id("circular ring")) {
	message("info", "You may only use this skill with a circular ring.", from);
	remove();
	return;
    }
    if(at->id("circular ring") && at->id("gigantic circular ring")) {
	message("info", "The circular ring you are using is too large for this skill.", from);
	remove();
	return;
    }
    if(at->id("circular ring") && at->id("large circular ring")) {
	message("info", "The circular ring you are using is too small for this skill.", from);
	remove();
	return;
    }

    skill = from->query_base_skill("create greater nexus");
    time = 36000 + (skill * 20);
    if(wizardp(from)) time = 1;

    message("info", "%^BLUE%^You begin to create and stabilize a greater nexus.%^RESET%^", from);
    set_work_message("%^BOLD%^%^RED%^You stabilize the nexus.%^RESET%^");
    start_work(at, from, time);
    return;
}

void finish_work(object from, object at) {
    object ob;

    if(!present("huge circular ring", from)) {
	message("info", "The circular ring is not present in your inventory. The long term therefore fails.", from);
	remove();
	return;
    }

    message("info", "%^YELLOW%^You have finished stabilizing the greater nexus!%^RESET%^", from);
    message("info", "%^YELLOW%^"+(string)from->query_cap_name()+" finishes stabilizing a greater nexus!%^RESET%^", environment(from), ({ from }));
    seteuid(geteuid(this_object()));
    ob = new("/d/damned/guilds/nethermancer/misc/greater_nexus.c");
    ob->set_property("charge cap", (skill*9000));
ob->move(environment(from));
    at->remove();
    remove();
    return;
}

