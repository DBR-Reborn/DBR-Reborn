#include <std.h>

inherit OBJECT;
inherit "/std/locker_logic";

void init() {
    add_action("charge", "charge");
}

void create() {
    ::create();
    set_name("master nexus");
    set_id(({ "nexus", "small nexus", "master nexus", "master nethermancer nexus", "nethermancer nexus" }));
    set_short("%^RED%^A master nexus%^BOLD%^%^YELLOW%^ (%^WHITE%^glowing%^YELLOW%^)%^RESET%^");
    set_long("This is a relatively large circular ring, fashioned completely of marble and decorated with numerous intricate designs. Its entire center section glows faintly and looks as if it is a pool of pulsing water. This energized liquid serves as a gateway to the netherworld beyond, where a practitioner of undead magic can channel various souls from the abyss into powerful soul orbs. It can also be used to transfer souls from those same orbs into power usable for body enhancement. This tool of the nethermancer requires no charging, as it is powered indefinitely by an unknown source.\n\nThis nexus may be used to create category %^GREEN%^one%^RESET%^ undead.\n%^This nexus has %^GREEN%^unlimited%^RESET%^ charge.");
    set_property("nexus class", 1);
    set_property("guild nexus", 1);
    set_weight(100000);
    set_value(150000);
    return;
}

int query_is_locker() { return 1; }
string query_storage_key() { return "glnexus"; }

int charge(string str) {
    if(id(str)) {
	message("info", "This nexus has unlimited charge, and does not need any corpses offered into its liquid.", this_player());
	return 1;
    }
    else {
    }
}
