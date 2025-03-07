#include <colors.h>
inherit "/std/Object";

/*
  Vial that holds weapon poison created by players when they use
  the Poison Lore skill.  This object is created by a plant press
  and should not be created by any other object or bad things may
  happen.

  Duridian 4/1/96

  Modified by Tailwind for the Alchemist Guild

  Tailwind 5/22/99

  Re modded by Glen for alchemist guild

  dropped protection from 60 per * to 15 per *

*/

// protection per power level
#define PROT 35

int is_aura_flare_potion(){
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
	set_short("an aura flare potion");
    else
	set_short("an aura flare potion (activated)");
}

void create() {
    ::create();
    set_name("potion");
    set_id( ({"aura potion", "aura flare potion", "flare potion", "potion"})
    );
    set_long("A small flask containing an aura flare potion.");
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

    if((!str) || ((str != "aura flare potion") && (str != "flare potion") &&
	(str != "aura potion") && (str != "potion"))) {
	notify_fail("Drink what?\n");
        return 0;
    }

    if(this_player()->query_current_attacker()) {
	write("You cannot do that while in combat!");
	return 1;
    }

    if(this_player()->query_ele_pres()) {
	write("You already have an aura flare.");
	return 1;
    }


    if(query_potion_power() < 1 || query_potion_duration() < 1){
	write("You drink "+query_short()+" and nothing happens");

	message("info", (string)this_player()->query_cap_name() +
	  " drinks "+query_short()+", but nothing happens.!",
	  all_inventory(environment(this_player())), ({ this_player() }) );
    }else {

        ob = new("/std/spells/shadows/ele_pres_shad");
        ob->set_power(query_potion_power() / 5 + 1);
        ob->set_damage(({ "fire", "plasma", "radiation" }));
	ob->set_shadow_name("aura flare");
	ob->start_shadow(this_player(), query_potion_duration(), 
	  "%^BOLD%^" + "%^GREEN%^" + "Aura Flare Wears Off");

	write("You drink "+query_short()+" and are surrounded by an aural flare");

	ob = new("/std/spells/shadows/ac_shadow");

        ob->set_shadow_name("Aura Flare Potion");
	ob->set_shad_ac(PROT * query_potion_power(), "fire");
	ob->set_shad_ac(PROT * query_potion_power(), "plasma");
	ob->set_shad_ac(PROT * query_potion_power(), "radiation");
	ob->start_shadow(this_player(), query_potion_duration(), 0);

	message("info", (string)this_player()->query_cap_name() +
	  " drinks "+query_short()+", and is surrounded by an aural flare.!",
	  all_inventory(environment(this_player())), ({ this_player() }) );
    }


    remove();
    return 1;
}

