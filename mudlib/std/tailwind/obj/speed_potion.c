/*
  Vial that holds weapon poison created by players when they use
  the Poison Lore skill.  This object is created by a plant press
  and should not be created by any other object or bad things may
  happen.

  Duridian 4/1/96

  Modified by Tailwind for the Alchemist Guild

  Tailwind 5/22/99

  Re modded by Glen for alchemist guild
*/

#include <std.h>

inherit "/std/Object";


int is_speed_potion(){
    return 1;
}

void set_potion_power(int x){
    set_property("potion power", x);
    call_out("setup_potion", 2);
}

int query_potion_power(){
    return (int)query_property("potion power");
}

void set_potion_duration(int x){
    set_property("potion duration", x);
}

int query_potion_duration() {
    return (int)query_property("potion duration");
}

void setup_potion(){
    if(query_potion_power() < 1)
	set_short("a speed potion");
    else
	set_short("a speed potion (activated)");
}

void create() {
    ::create();
    set_name("potion");
    set_id( ({"speed", "speed potion", "potion"}) );
    set_long("A small bottle containing some sort of elixir of speed.");
    set_weight(3);
    set_value(0);
    call_out("setup_potion", 2);
}

void init() {
    ::init();
    add_action("drink_func", "drink");
}

int drink_func(string str) {
    object ob;

    if((!str) || ((str != "speed") && (str != "speed potion") 
	&& (str != "potion"))) {
	notify_fail("Drink what?\n");
	return 0;
    }

    if(this_player()->query_current_attacker()) {
	write("You cannot do that while in combat!");
	return 1;
    }

    if(this_player()->query_haste()) {
	write("You are already moving quickly.");
	return 1;
    }

    if(this_player()->query_speed()) {
write("You are already moving quickly.");
	return 1;
    }


    if(query_potion_power() < 1 || query_potion_duration() < 1){
	write("You drink "+query_short()+" and nothing happens.");

	message("info", (string)this_player()->query_cap_name() +
	  " drinks "+query_short()+", but the potion is not activated so nothing happens.",
	  all_inventory(environment(this_player())), ({ this_player() }) );
    }else {
	ob = new("/std/spells/shadows/speed_shadow");

	ob->set_shadow_name("Speed Potion");
	ob->start_shadow(this_player(), query_potion_duration(), 
	  "%^BOLD%^" + "%^GREEN%^" + "You feel yourself slowing down.");
	write("You drink "+query_short()+" and become faster.");


	message("info", (string)this_player()->query_cap_name() +
	  " drinks "+query_short()+", and starts to move quickly!",
	  all_inventory(environment(this_player())), ({ this_player() }) );
    }


    remove();
    return 1;
}

