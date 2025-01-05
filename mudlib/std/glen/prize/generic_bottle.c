#include <std.h>

inherit "/std/Object";

object cas;

string item = "/d/damned/guilds/join_rooms/tcan";


string query_item(){
    return item;
}

void set_item(string str){
    item = str;
}

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
	message("info",
	  "Open what?",this_player());
	return 0;
    }

    message("info", "" + "" + 
      (string)this_player()->query_cap_name() +
      " smashes a mystery bottle.",
      all_inventory(environment(this_player())), ({ this_player() }) );
    message("info", "" + "" + 
      "You smash the mystery bottle.",
      this_player());

    ob = new(item);
    ob->move(environment(this_player()));
    ob->set_owner(this_player());
    message("info", "Out pops a " + ob->query_short() +" !",
      this_player());
    remove();
    return 1;
}
