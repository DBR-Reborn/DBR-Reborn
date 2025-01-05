#include <std.h>

inherit "/std/Object";

object cas;

string item = "cold";

int drink_func(string str);


void set_volatile(){
    call_out("try_drink", 5);
}

void try_drink(){
    call_out("try_drink", 15);
    if(living(environment(this_object()))
      && !wizardp(environment(this_object()))){
	drink_func("bottle");
    }

}

string query_item(){
    return item;
}

void set_item(string str){
    item = str;
}

void create() {
    ::create();
    set_name("bottle");
    set_short("a mysterious bottle");
    set_id( ({"bottle"}) );
    set_long("A small bottle.  " + 
      "You may 'drink' this bottle.");
    set_weight(3);
    set_value(0);
}

void init() {
    ::init();
    add_action("drink_func", "drink");
}

int drink_func(string str) {
    object ob;
    object at;

    at = environment(this_object());

    if(!living(at))
	return 0;

    cas = at;

    if((!str) || (str != "bottle")) {
	message("info",
	  "drink what?",at);
	return 0;
    }

    message("info", "" + "" + 
      (string)at->query_cap_name() +
      " drinks a bottle.",
      all_inventory(environment(at)), ({ at }) );
    message("info", "" + "" + 
      "You drink the bottle.",
      at);

    ob = new("/std/glen/diseases/" + item);
    ob->start_shadow(at, 0, "you feel better");
    remove();
    return 1;
}

