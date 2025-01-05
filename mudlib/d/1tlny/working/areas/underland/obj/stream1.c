// Stream for cave1
// Modified from Khojem's vat.c code

#include <move.h>
#include <stream.h>
inherit "/std/Object";

static int TELL;

int check_living(object *inv);

void create() {
	::create();
        set_name("stream");
        set_id(({ "stream" }) );
        set_short("%^CYAN%^%^BOLD%^a stream%^MAGENTA%^%^BOLD%^");
	set_long(
"The stream flows from the west and heads east through the rocks. "
"Broken bones and torn flesh sway calmly in the current.");
	set_property("duration", 600);
        TELL = 1;
        call_out("story_telling", DELAY);
}

void init() {
  	::init();
  	add_action("fill_vessel", "fill");
        add_action("drink_water", "drink");
        add_action("drink_stream", "drink");
	add_action("splash_water", "splash");
	if(!TELL) {
		TELL = 1;
		call_out("story_telling", DELAY );
	}
}

void story_telling() {
	object *inv;
	int i;
	string story;
	switch(random(4)) {
                case 0: story = "\nA small guppy peaks up from "
                                "under a bone, takes a peice of "
                                "flesh and swims away.\n";
			break;
                case 1: story = "\nSounds of splashing can be heard to the "
                                "north as a the rumbling stops for a moment.\n";
			break;
                case 2: story = "\nA large chuck of flesh flows in from "
                                "the north and disappears unders a rock.\n";
			break;
                case 3: story = "\nA death cry echos in the cave "
                                "and the stream becomes tinted red for "
                                "a moment.\n";
			break;
	}
	message("info", story, ENV(TO));
	TELL = 0;
	inv = all_inventory(TO);
	while(i--) {
		if(inv[i]->is_player()) {
			TELL = 1;
			call_out("story_telling", DELAY);
			return;
		}
	}
	return;
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

int drink_stream(string str) {
	string drink;
	int count;
	if(!str) {
		notify_fail("What do you want to drink?\n\n");
		return 0;
	}
        if( !(str == "stream") ) {
		notify_fail("What do you want to drink?\n\n");
		return 0; 
	}
	if(TP->query_quenched() > 420) {
		message("info", "You'll blow up if you drink another drop!", 
			TP);
		return 1;
	}
	message("info", "You take a long drink of water from the clear "
                "stream.  You feel very refreshed.", TP);
	TP->add_quenched(-1000);
	count = 0;
	while( (TP->query_quenched() < 450) && (count < 90 ) ) {
		TP->add_quenched(5);
		count += 1;
	}
        switch(random(3)) {
                case 0: drink = " shoves "+(string)TP->query_possessive()+
			" face into the "
                        "stream and takes a long drink of water.";
			break;
		case 1: drink = " takes a drink of water from the "
                        "stream.";
			break;
		case 2: drink = " drinks so fast that water flies out "
			"of "+(string)TP->query_possessive()+" nose!";
			break;
	}
	say(TPQCN+drink);
	return 1;
}

int splash_water(string str) {
	if(!str) {
		notify_fail("Who do you want to splash with water?\n\n");
		return 0;
	}
	if(!present(str)) {
                write(CAP(str)+ " is not here at the stream.");
		return 1;
	}
	write("You splash "+CAP(str)+" in the face!");
	say(TPQCN+" splashes water at "+CAP(str)+"!");
	return 1;
}

int get(){
  return 0;
}
