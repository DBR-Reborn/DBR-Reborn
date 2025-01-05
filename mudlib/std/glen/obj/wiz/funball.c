#include <std.h>
#include <daemons.h>
#include <balance.h>
#include <colors.h>

inherit "/std/Object";

void sick_on(string who){
    object at;

    who = replace_string(who, "at ", "");
    who = lower_case(who);
    at = find_player(who);

    if(!at){
	write("cant find " + who);
	return;
    }

    this_object()->move(environment(at));

    message("info", CBOLD + CGREEN +
      this_player()->query_cap_name() + " throws a funball into the distance.",
      all_inventory(environment(this_player())));
    message("info", CBOLD + CGREEN +
      at->query_cap_name() + " is hit in the back of the head with a funball.",
      all_inventory(environment(at)));
}


void init() {
    ::init();
    add_action("sick_on", "throw");
}

create() {
    ::create();
    set_id( ({"funball", "ball"}) );
    set_short(CBOLD + CGREEN + "Funball!");
    set_long("A funball! throw it at someone! ex: 'throw at li'");
    set_weight(3);
    set_value(0);
    set_property("no save", 1);
}

