
#include <std.h>

inherit "/std/Object";

string invade_mob = "/std/glen/pet/sheep";

int primary_number = 6;
int secondary_number = 5;
int steps = 7;
int speed = 55;

void set_invade_mob(string str){
    invade_mob = str;
}

void create() {
    ::create();
    set_name("container");
    set_short("invasion container");
    set_id( ({"container"}) );
    set_long("An invasion container, 'invade' to use.");
    set_weight(3);
    set_value(0);
}

void init() {
    ::init();
    add_action("drink_func", "invade");
}

int drink_func(string str) {
    object ob;
    object ob2;
    int i, j, k, l;

    for(i = 0;i < primary_number; i++){
	ob = new(invade_mob);
	ob->move(environment(this_player()));
	ob->set_speed(speed);
	for(k = 0; k < steps; k++)
	    ob->run_away();
	for(j = 0; j < secondary_number; j++){
	    ob2 = new(invade_mob);
	    ob2->move(environment(ob));
	    ob2->set_speed(speed);
	    for(k = 0; k < steps; k++)
		ob2->run_away();
	}
    }

    remove();
}


