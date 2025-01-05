#include <std.h>

inherit OBJECT;

void init() {
    ::init();
    add_action("enter", "enter");
}

int enter(string str) {
    if(id(str)) {
	if(this_player()->query_class() == "nethermancer" || this_player()->query_property("nethermancer pet")) {
	    message("my_action", "%^BOLD%^%^MAGENTA%^You step into the portal and are magically transported to your nether plane!%^RESET%^", this_player());
	    this_player()->force_me("look");
	    this_player()->move_player(query_property("gate location"));
	    return 1;
	}
	message("my_action", "You attempt to enter the portal but are bounced backwards by its power!", this_player());
	return 1;
    }
}

void create() {
    ::create();
    set_property("no get", 1);
    set_name("gate");
    set("id", ({ "gate", "nether gate", "gateway","nether gateway", "portal", "nether portal" }));
    set_weight(10000000);
    set_value(0);
    set_short("%^BOLD%^%^CYAN%^A nether gate%^RESET%^");
    set_long("This shimmering gateway serves as a portal leading to a distant plane within the Netherworld itself. A Nethermancer can 'enter' it or direct pets to do so as well to reach his or her nether plane where those pets can be safely stored without fear.");
    call_out("gate_dest", 60);
}

void gate_dest() {
    message("info", "%^BOLD%^%^RED%^The nether gate loses its stabilization and disperses into the wind.%^RESET%^", environment(this_object()));
    this_object()->remove();
}
