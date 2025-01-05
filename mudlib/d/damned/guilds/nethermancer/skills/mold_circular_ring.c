#include <clock.h>

inherit "/std/skills/long_term.c";

int skill;
int price;
string obpath;
string obname;

void create() {
    ::create();
    set_stat("constitution");
    set_dev_cost(19);
    set_fast_dev_cost(41);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
    message("help", "This skill permits a Merchant to create a circular ring, required by a Nethermancer to create their vital nexuses. To mold the ring, a slab of marble is required alongside an amount of mithril determines by the type of circular ring being molded from it. The percent level of this skill affects only the time required to finish the longterm and will not affect the final outcome. The types of rings that can be formed and their mithril costs are as follows:\n\nLarge Ring (required for a lesser nexus): 100 mithril\nHuge Ring (required for a greater nexus): 1000 mithril\nGigantic Ring (required for a master nexus): 10000 mithril\n\nSyntax: 'use mold circular ring at slab with gigantic ring'", this_player());
}

void skill_func(object from, object at, string args) {
    int time;

    if(!at->id("marble slab")) {
	message("info", "You may only use this skill on a slab of marble.", from);
	remove();
	return;
    }

    switch(args) {
    case "large ring":
	obname = "large circular ring";
	obpath = "/d/damned/guilds/nethermancer/misc/large_ring";
	price = 100;
	break;
    case "huge ring":
	obname = "huge circular ring";
	obpath = "/d/damned/guilds/nethermancer/misc/huge_ring";
	price = 1000;
	break;
    case "gigantic ring":
	obname = "gigantic circular ring";
	obpath = "/d/damned/guilds/nethermancer/misc/gigantic_ring";
	price = 10000;
	break;
    default:
	message("info", "You may only create large, huge, or gigantic rings with this skill.", from);
	remove();
	return;
    }

    if(from->query_money("mithril") < price){
	message("info", "You do not have enough mithril to perform this skill.", from);
	remove();
	return;
    }

    skill = props["skill level"];
    // Set when skill is fixed
    if(time < 3600) time = 3600;
    time = 14400 - (skill * 20);
    if(wizardp(from)) time=1;
    message("info", "You begin to mold the slab of marble into a "+obname+".", from);
    set_work_message("%^YELLOW%^You mold the circular ring.%^RESET%^");
    start_work(at, from, time);
    return;
}

void finish_work(object from, object at) {
    string *wc_keys, *runes;
    mixed tmp;
    object ob;  

    if(from->query_money("mithril") < price) {
	message("info", "You no longer have enough mithril to complete molding the circular ring.", from);
	remove();
	return;
    }
    message("info", "%^ORANGE%^You have finished all of your molding.%^RESET%^", from);
    message("info", "You expend "+price+" mithril to enhance and extend the slab of marble to create a "+obname+"!", from);
    message("info", "%^ORANGE%^"+from->query_cap_name() + " finishes molding a "+obname+"!%^RESET%^", environment(from), ({ from }));
    seteuid(geteuid(this_object()));
    ob = new(obpath);
    ob->move(environment(from));
    from->add_money("mithril", -price);
    at->remove();
    remove();
    return;
}
