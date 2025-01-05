#include <std.h>

inherit "/std/Object";

object cas;

void create() {
    ::create();
    set_name("bottle");
    set_short("a prize bottle");
    set_id( ({"bottle"}) );
    set_long("A small jar containing a mystery prize." + 
      "You may 'open' the bottle to get your prize.");
    set_weight(3);
    set_value(0);
}

void init() {
    ::init();
    add_action("drink_func", "open");
}

int drink_func(string str) {
    object ob;

    cas = this_player();

    if((!str) || (str != "bottle")) {
	notify_fail("open what?\n");
	return 1;
    }

    message("info", "%^BOLD%^" + "%^GREEN%^" + 
      (string)this_player()->query_cap_name() +
      " smashes a mystery bottle.",
      all_inventory(environment(this_player())), ({ this_player() }) );
    message("info", "%^BOLD%^" + "%^GREEN%^" + 
      "You smash the mystery bottle.",
      this_player());

    ob = new("/std/glen/pet/sheep");
    ob->move(environment(this_player()));
    ob->set_owner(this_player()->query_true_name());
    message("info", "a sheep pops out and obeys your orders", this_player());
    remove();
}

