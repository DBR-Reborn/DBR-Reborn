/*
  Vial that holds weapon poison created by players when they use
  the Poison Lore skill.  This object is created by a plant press
  and should not be created by any other object or bad things may
  happen.

  Duridian 4/1/96

  Modified by Tailwind for the Alchemist Guild

  Tailwind 5/22/99

*/

#include <std.h>

inherit "/std/Object";

object cas;

void damage_all(string room, int times);

int is_poison_fumes_potion(){
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
	set_short("a poison perfume potion");
    else
	set_short("a poison perfume potion (activated)");
}


void create() {
    ::create();
    set_name("perfume");
    set_id( ({"potion", "poison perfume", "poisonous perfume", "deadly perfume",
	"perfume"}) );
    set_long("A small jar containing poison perfume. " + 
      "You may 'smash' it to release a poisonous cloud.  ");
    set_weight(3);
    set_value(0);
    call_out("setup_potion", 2);
}

void init() {
    ::init();
    add_action("drink_func", "smash");
}

int filter_living(object who) { return living(who); }

int drink_func(string str) {
    object ob;

    cas = this_player();

    if((!str) || ((str != "deadly perfume") && (str != "poisonous perfume")
	&& (str != "poison perfume") && (str != "perfume") && (str != "potion"))) {
	notify_fail("smash what?\n");
	return 1;
    }

    if((time() - (int)this_player()->query_property("last smash potion")) < 8){
	write("It takes time to smash another potion.");
	return 1;

    }
    //this should make it impossible to smash these in church and other safe rooms - TM 072701

    if(environment(this_player())->query_property("no attack")) {
        write("Greater powers prevent you from smashing that!");
        return 1;
    }


    this_player()->set_property("last smash potion", (int)time());


    if(query_potion_power() < 1 || query_potion_duration() < 1){
	write("You smash "+query_short()+" and nothing happens");

	message("info", (string)this_player()->query_cap_name() +
	  " smashes "+query_short()+", but nothing special happens!",
	  all_inventory(environment(this_player())), ({ this_player() }) );
    }else {
	write("%^BOLD%^" + "%^GREEN%^" + 
	  "You smash "+query_short()+" and poison gas starts to fill the room");


	message("info", "%^BOLD%^" + "%^GREEN%^" + 
	  (string)this_player()->query_cap_name() +
	  " smashes "+query_short()+", a potion",
	  all_inventory(environment(this_player())), ({ this_player() }) );
	message("info", "%^BOLD%^" + "%^RED%^" + 
	  "A poisonous gas starts to fill the room" + 
	  ", you being to cough and feel faith.  Better leave here.",
	  all_inventory(environment(this_player())), ({ this_player() }) );
	call_out("damage_all", 5, base_name(environment(cas)),
	  query_potion_duration() / 5);
    }
    set_short("");
    set_id(({"poison cloud"}));
    move(base_name(environment(cas)));

    return 1;
}

void damage_all(string room, int times) {
    object *inv, env;
    int i;

    env = find_object_or_load(room);
    times--;
    inv = filter_array(all_inventory(env), "filter_living", this_object());
    i = sizeof(inv);
    while(i--) {
	if(inv[i] == cas) continue;
	message("info", 
	  "%^MAGENTA%^" + 
	  "You take damage from poisonous fumes!", inv[i]);
	inv[i]->add_hp(-1 * query_potion_power() * (int)inv[i]->query_hp() /100 );
	inv[i]->add_poisoning(query_potion_power());
	if(cas)
	    inv[i]->kill_ob(cas, 1);
    }
    if(times <= 0) {
	message("info", 
	  "%^BOLD%^" + "%^GREEN%^" +
	  "The poison fumes fade away.",
	  env);
	remove();
	return;
    }
    call_out("damage_all", 5, room, times);
    return;
}

