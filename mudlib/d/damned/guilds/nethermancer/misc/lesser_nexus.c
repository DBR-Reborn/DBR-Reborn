#include <std.h>

inherit OBJECT;
inherit "/std/locker_logic";

int level;
int minutes;

void init() {
    add_action("charge", "charge");
}

void create() {
    ::create();
    set_name("lesser nexus");
    set_id(({ "nexus", "small nexus", "lesser nexus", "lesser nethermancer nexus", "nethermancer nexus" }));
    set_short("%^GREEN%^A lesser nexus%^RESET%^");
    set_long("This is a relatively large circular ring, fashioned completely of marble and decorated with numerous intricate designs. Its entire center section glows faintly and looks as if it is a pool of pulsing water. This energized liquid serves as a gateway to the netherworld beyond, where a practitioner of undead magic can channel various souls from the abyss into powerful soul orbs. It can also be used to transfer souls from those same orbs into power usable for body enhancement. Use the command '%^YELLOW%^charge nexus%^RESET%^' to offer it fresh corpses to keep it active.\n\nThis nexus may be used to create category %^GREEN%^one%^RESET%^ undead.\n%^This nexus has %^GREEN%^0 minutes%^RESET%^ of charge.");
    set_property("nexus class", 1);
    set_weight(1500);
    set_value(150000);
    call_out("nexus_desc", 2);
    return;
}

int query_is_locker() { return 1; }
string query_storage_key() { return "lnexus"; }

int charge(string str) {
    if(id(str)) {
	if(!present("corpse", this_player())) {
	    message("info", "You do not have any corpses in your inventory to charge this nexus with.", this_player());
	    return 1;
	}
	if(present("corpse", this_player())->query_property("perm preserved") > 0) {
	    message("info", "You may only use fresh non preserved corpses to charge this nexus.", this_player());
	    return 1;
	}
	if(this_player()->query_class() != "nethermancer") {
	    message("info", "Only Nethermancers have the ability charge this nexus.", this_player());
	    return 1;
	}
	set_short("%^GREEN%^A lesser nexus%^BOLD%^%^YELLOW%^ (%^WHITE%^glowing%^YELLOW%^)%^RESET%^");
	level = present("corpse", this_player())->query_level() / 2;
	message("info", "%^MAGENTA%^You offer a freshly killed corpse into the energized liquid of the nexus, charging it with great power!%^RESET%^", this_player());
	message("info", "%^MAGENTA%^"+(string)this_player()->query_cap_name()+" offers a freshly killed corpse into the energized liquid of the nexus, charging it with great power!%^RESET%^", environment(this_player()), ({ this_player() }));
	present("corpse", this_player())->remove();
	set_property("charge remaining", (query_property("charge remaining") + (level*6000)));
	//if(query_property("charge remaining") >= query_property("charge cap")) {
	 //   set_property("charge remaining", (query_property("charge cap")));
	//    message("info", "The nexus has reached its maximum charge.", this_player());
	//}
	return 1;
    }
}

/*
int get(string str) {
    if(id(str)) {
	if(this_player()->query("nexus long term") > 0) {
	    message("info", "%^BOLD%^%^RED%^You cease performing your long-term spell as the nexus required to continue it is removed from the floor environment.%^RESET%^", this_player());
	    this_player()->move(environment(this_player()));
	}
	return 1;
    }
}
*/

void nexus_desc() {
    object *inv;

    minutes = (query_property("charge remaining") / 60);

    inv = all_inventory(environment(this_object()));
    inv = filter_array(inv, "filter_fun");
    set_short("%^GREEN%^A lesser nexus%^BOLD%^%^YELLOW%^ (%^WHITE%^glowing%^YELLOW%^)%^RESET%^");
    set_long("This is a relatively large circular ring, fashioned completely of marble and decorated with numerous intricate designs. Its entire center section glows faintly and looks as if it is a pool of pulsing water. This energized liquid serves as a gateway to the netherworld beyond, where a practitioner of undead magic can channel various souls from the abyss into powerful soul orbs. It can also be used to transfer souls from those same orbs into power usable for body enhancement. Use the command '%^YELLOW%^charge nexus%^RESET%^' to offer it fresh corpses to keep it active.\n\nThis nexus may be used to create category %^GREEN%^one%^RESET%^ undead.\n%^This nexus has %^GREEN%^"+(int)minutes+" minutes%^RESET%^ of charge.");
    if(query_property("charge remaining") == 2) {
	message("info", "%^BOLD%^%^WHITE%^The energy traversing the nexus liquid fizzles as its charge expires.%^RESET%^", environment(this_object()));
    }
    set_property("charge remaining", (query_property("charge remaining") - 2));
    if(query_property("charge remaining") < 0) {
	set_short("%^GREEN%^A lesser nexus%^RESET%^");
	set_property("charge remaining", 0);
	for(int i = 0;i < sizeof(inv);i++) {
	    if(inv[i]->query("nexus long term") > 0) {
		message("info", "%^RED%^The lack of charge from the nexus prohibits you from continuing this spell.%^RESET%^", inv[i]);
		inv[i]->move(environment(inv[i]));
	    }
	}
    }
    call_out("nexus_desc", 2);
}

int filter_fun(object ob) {
    if(ob->query_class() == "nethermancer") return 1;
    else return 0;
}
