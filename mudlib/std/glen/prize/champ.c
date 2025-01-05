
#include <std.h>

inherit "/std/Object";

object cas;

void create() {
    ::create();
    set_name("glass");
    set_short("a glass of champagne");
    set_id( ({"glass"}) );
    set_long("A glass of champagne to celebrate the new year.  " + 
      "You may 'drink' it.");
    set_weight(3);
    set_value(0);
}

void init() {
    ::init();
    add_action("drink_func", "drink");
}

int drink_func(string str) {
    object ob;

    cas = this_player();

    if((!str) || (str != "glass" && str != "champagne")) {
	notify_fail("drink what?\n");
	return 1;
    }

    message("info",
      (string)this_player()->query_cap_name() +
      " drinks a glass of champagne.",
      all_inventory(environment(this_player())), ({ this_player() }) );
    message("info", "" + "" + 
      "You drink the champagne, you feel happy.",
      this_player());

    seteuid(geteuid());

    this_player()->add_intox(random(20) + 10);
    remove();
}


