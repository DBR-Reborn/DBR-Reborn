// stolen from nalon then modified, by glen
#include <std.h>
#include <move.h>
inherit "/std/Object";

static int TELL;

int check_living(object *inv);


void create() {
    ::create();
    set_name("well");
    set_id(({ "well" }) );
    set_short("An old well");
    set_long("An ancient stone well "+
      "suprisingly it still works.");

}

void init() {
    ::init();
    add_action("fill_vessel", "fill");
    add_action("drink_water", "drink");
    add_action("drink_well", "drink");
}
int fill_vessel(string str) {
    object ob;
    ob = present(str, this_player());
    if(!ob) {
	write("You don't have "+article(str)+".");
	return 1;
    }
    if(!ob->id("water skin")) {
	write("You can't fill "+article(str)+" with water!");
	return 1;
    }
    if(ob->full()) {
	write("That waterskin is full already.");
	return 1;
    }
    ob->fill("water", 5, 0);
    write("You fill the waterskin.");
    return 1;
}

int drink_well(string str) {
    string drink;
    int count;
    if(!str) {
	notify_fail("What do you want to drink?\n\n");
	return 0;
    }
    if( !(str == "well") ) {
	notify_fail("What do you want to drink?\n\n");
	return 0; 
    }
    if(TP->query_quenched() > 420) {
	message("info", "You'll blow up if you drink another drop!", 
	  TP);
	return 1;
    }
    message("info", "You take a long drink of water from the well. "
      "You feel very refreshed.", TP);
    TP->add_quenched(-1000);
    count = 0;
    while( (TP->query_quenched() < 450) && (count < 90 ) ) {
	TP->add_quenched(5);
	count += 1;
    }
    switch(random(3)) {
    case 0: drink = " shoves "+(string)TP->query_possessive()+
	" face into the "
	"well and takes a long drink of water.";
	break;
    case 1: drink = " takes a drink of water from the "
	"well.";
	break;
    case 2: drink = " drinks so fast that water flies out "
	"of "+(string)TP->query_possessive()+" nose!";
	break;
    }
    say(TPQCN+drink);
    return 1;
}

int get(){
    return 0;
}

