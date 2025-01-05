#include <std.h>

inherit "/std/Object";

object cas;

int primed = 0;

void create() {
    ::create();
    set_name("grenade");
    set_short("a grenade");
    set_id( ({"grenade"}) );
    set_long("A small grenade." + 
      "You may 'prime' it, you have 10 seconds to run.");
    set_weight(3);
    set_value(0);
}

void init() {
    ::init();
    add_action("drink_func", "prime");
}

void explode() {
    object env;
    object ob;
    int i, limit = random(4)+3;

    env = environment(this_object());

    while(living(env))
	env = environment(env);


    message("info", "%^BOLD%^" + "%^RED%^" + 
      "A grenade explodes!",
      all_inventory(env));

    for(i = 0; i < limit; i++){
	ob = new("/std/glen/pet/sheep");
	ob->move(env);
	ob->set_speed(random(5)+2);
    }
    remove();
}

int drink_func(string str) {
    object ob;

    cas = this_player();

    if(primed)
	return 0;

    if((!str) || (str != "grenade")) {
	notify_fail("prime what?\n");
	return 1;
    }

    message("info", "%^BOLD%^" + "%^RED%^" + 
      (string)this_player()->query_cap_name() +
      " just pulled the pin on a grenade, RUN.",
      all_inventory(environment(this_player())), ({ this_player() }) );
    message("info", "%^BOLD%^" + "%^RED%^" + 
      "You pull the pin priming the grenade, 10 seconds.",
      this_player());

    primed = 1;
    call_out("explode", 10);
    return 1;
}

