
#include <std.h>

inherit "/std/Object";

object cas;

void create() {
    ::create();
    set_name("present");
    set_short("%^GREEN%^" + "giftwrapped " 
      + "%^RED%^" +"present" + "%^RESET%^");
    set_id( ({"present"}) );
    set_long("A giftwrapped box." + 
      "You may 'open' the the box to see whats in it.");
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

    if((!str) || (str != "present")) {
	notify_fail("open what?\n");
	return 1;
    }

    message("info", "" + "" + 
      (string)this_player()->query_cap_name() +
      " opens a " + "%^GREEN%^" + "present.",
      all_inventory(environment(this_player())), ({ this_player() }) );
    message("info", "" + "" + 
      "You open the " + "%^GREEN%^" + "present.",
      this_player());

    ob = new("/std/glen/pet/elf");
    ob->move(environment(this_player()));
    ob->set_owner(this_player()->query_true_name());
    message("info", "%^GREEN%^" +
      "a little elf pops out with jingle bells on.",
      this_player());
    remove();
}

