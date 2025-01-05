#include <std.h>
#include <clock.h>

inherit "/std/skills/long_term.c";

int skill;

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(50);
    set_fast_dev_cost(145);
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("long term exp", 100000);
    return;
}

void info() {
    message("help", "Using this powerful skill, an elite Nethermancer can create and stabilize the most potent dimensional gateway available to the realm of the dead. This staggering master nexus once finished will allow all levels of soul orb sacrificing and undead creature raisings to be carried out, even the most advanced not permissable by any other nexus. To use this skill, a rare gigantic circular ring that can only be crafted by a merchant is required alongside an absolutely enormous time investment (a minimum of thirty real-time hours). The base percent value of this skill will decide the maximum charge the master nexus can contain, determined at a rate of 1 minute per percentage point.\n\nSyntax: 'use create master nexus at ring'", this_player());
}

void skill_func(object from, object at, string arg) {
    int time;

    if(!at->id("circular ring")) {
	message("info", "You may only use this skill with a circular ring.", from);
	remove();
	return;
    }
    if(at->id("circular ring") && !at->id("gigantic circular ring")) {
	message("info", "The circular ring you are using is too small for this skill.", from);
	remove();
	return;
    }

    skill = from->query_base_skill("create master nexus");
    time = 108000 + (skill * 5);
    if(wizardp(from)) time = 1;

    message("info", "%^RED%^You begin to create and stabilize a master nexus.%^RESET%^", from);
    set_work_message("%^BOLD%^%^RED%^You stabilize the nexus.%^RESET%^");
    start_work(at, from, time);
    return;
}

void finish_work(object from, object at) {
    object ob;

    if(!present("gigantic circular ring", from)) {
	message("info", "The circular ring is not present in your inventory. The long term therefore fails.", from);
	remove();
	return;
    }

    message("info", "%^YELLOW%^You have finished stabilizing the master nexus!%^RESET%^", from);
    message("info", "%^YELLOW%^"+(string)from->query_cap_name()+" finishes stabilizing a master nexus!%^RESET%^", environment(from), ({ from }));
    message("shout", "%^BOLD%^%^RED%^A %^WHITE%^blinding%^RED%^ white flash lights up the skies all across Daybreak Ridge, followed by a %^MAGENTA%^deafening%^RED%^ medley of countless wailing souls as a master nexus is completely stabilized!%^RESET%^", users());
    seteuid(geteuid(this_object()));
    ob = new("/d/damned/guilds/nethermancer/misc/master_nexus.c");
    ob->set_property("charge cap", (skill*9000));
    ob->move(environment(from));
    at->remove();
    remove();
    return;
}

