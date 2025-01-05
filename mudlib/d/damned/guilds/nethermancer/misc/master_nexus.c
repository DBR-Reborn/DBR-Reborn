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
    set_name("master nexus");
    set_id(({ "nexus", "huge nexus", "master nexus", "master nethermancer nexus", "nethermancer nexus" }));
    set_short("%^RED%^A master nexus%^RESET%^");
    set_long("This is a gigantic circular ring, entirely composed of a rare pitch dark marble and covered completely with designs of the most elite artistry imaginable. The center section of the huge device flashes endlessly with blinding light and from what you can make out is a pool of violently active liquid. The liquid provides a gateway to the deepest reaches of the netherworld abyss, the location from where the high masters of undead magic siphon extremely potent souls and channel them into incredibly potent soul orbs. This awesome contraption may also be used to shift the souls from those soul orbs and transform them into the most pure of body enhancing power. The command '%^YELLOW%^charge nexus%^RESET%^' must be used periodically offering freshly killed corpses to this mind boggling interdimensional tool in order to keep it active.\n\nThis nexus may be used to create category %^RED%^four%^RESET%^ and %^RED%^five%^RESET%^ undead.\nThis nexus has %^RED%^0 minutes%^RESET%^ of charge.");
    set_property("nexus class", 3);
    set_weight(1500);
    set_value(250000);
    call_out("nexus_desc", 2);
    return;
}

int query_is_locker() { return 1; }
string query_storage_key() { return "mnexus"; }

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
	set_short("%^RED%^A master nexus%^BOLD%^%^YELLOW%^ (%^WHITE%^glowing%^YELLOW%^)%^RESET%^");
	level = present("corpse", this_player())->query_level() / 2;
	message("info", "%^MAGENTA%^You offer a freshly killed corpse into the energized liquid of the nexus, charging it with great power!%^RESET%^", this_player());
	message("info", "%^MAGENTA%^"+(string)this_player()->query_cap_name()+" offers a freshly killed corpse into the energized liquid of the nexus, charging it with great power!", environment(this_player()), ({ this_player() }));
	present("corpse", this_player())->remove();
	set_property("charge remaining", (query_property("charge remaining") + (level*6000)));
	if(query_property("charge remaining") >= query_property("charge cap")) {
	    set_property("charge remaining", (query_property("charge cap")));
	    message("info", "The nexus has reached its maximum charge.", this_player());
	}
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
	this_player()->force_me("get2 nexus");
    }
}
*/
void nexus_desc() {
    object *inv;

    minutes = (query_property("charge remaining") / 60);

    inv = all_inventory(environment(this_object()));
    inv = filter_array(inv, "filter_fun");
    set_short("%^RED%^A master nexus%^BOLD%^%^YELLOW%^ (%^WHITE%^glowing%^YELLOW%^)%^RESET%^");
    set_long("This is a gigantic circular ring, entirely composed of a rare pitch dark marble and covered completely with designs of the most elite artistry imaginable. The center section of the huge device flashes endlessly with blinding light and from what you can make out is a pool of violently active liquid. The liquid provides a gateway to the deepest reaches of the netherworld abyss, the location from where the high masters of undead magic siphon extremely potent souls and channel them into incredibly potent soul orbs. This awesome contraption may also be used to shift the souls from those soul orbs and transform them into the most pure of body enhancing power. The command '%^YELLOW%^charge nexus%^RESET%^' must be used periodically offering freshly killed corpses to this mind boggling interdimensional tool in order to keep it active.\n\nThis nexus may be used to create category %^RED%^four%^RESET%^ and %^RED%^five%^RESET%^ undead.\nThis nexus has %^RED%^"+(int)minutes+" minutes%^RESET%^ of charge.");
    if(query_property("charge remaining") == 2) {
	message("info", "%^BOLD%^%^WHITE%^The energy traversing the nexus liquid fizzles as its charge expires.%^RESET%^", environment(this_object()));
    }
    set_property("charge remaining", (query_property("charge remaining") - 2));
    if(query_property("charge remaining") < 0) {
	set_short("%^RED%^A master nexus%^RESET%^");
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
