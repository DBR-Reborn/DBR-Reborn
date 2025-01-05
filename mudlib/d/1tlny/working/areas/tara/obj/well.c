#include <std.h>
#include <move.h>
#include <well.h>
inherit "/std/Object";

static int TELL;

int check_living(object *inv);


void create() {
	::create();
        set_name("fountain");
        set_id(({ "fountain" }) );
        set_short("%^CYAN%^A small fountain%^MAGENTA%^%^BOLD%^");
	set_long(

"The halflings fountain, it is the only water supply anywhere "
"near the city.  They not only use it for water, but as "
"a gathering place to socialize and meet other halflings.");
	set_property("duration", 600);
        TELL = 1;
        call_out("story_telling", DELAY);
}

void init() {
  	::init();
  	add_action("fill_vessel", "fill");
        add_action("drink_water", "drink");
        add_action("drink_fountain", "drink");
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
               case 0: story = "\nA pretty young halfling "
                               "enters.  She looks you over, gives "
                               "you a wink, then leaves after filling "
                               "her bucket.\n";
			break;
               case 1: story = "\nA few laborers walk in, they "
                               "are weary from working all day, so "
                               "they came to get a drink.  After "
                               "drinking there fill, they walk off, "
                               "one letting out a loud fart.\n";
			break;
               case 2: story = "\nA middle aged halfling comes in, "
                               "he is well dressed an obviously an "
                               "important person in town.  He takes "
                               "a small sip from the fountain, acting "
                               "as if he's too good for it, then leaves "
                               "north towards an odd building.\n";
			break;
               case 3: story = "\nA group of children come in, "
                               "running.  They screech to a stop "
                               "just before the fountain, drink, then "
                               "start splashing each other playfully\n";
                               "slowly, his bones seem to be "
                               "creaking with age.  He stiffly "
                               "bends over to get a drink, "
                               "disgruntled that no one did "
                               "it for him, he moves on.\n";
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
		write("That "+article(str)+" is full already.");
		return 1;
	}
	ob->fill("water", 5, 0);
	write("You fill the "+article(str)+".");
	return 1;
}

int drink_fountain(string str) {
	string drink;
	int count;
	if(!str) {
		notify_fail("What do you want to drink?\n\n");
		return 0;
	}
        if( !(str == "fountain") ) {
		notify_fail("What do you want to drink?\n\n");
		return 0; 
	}
	if(TP->query_quenched() > 420) {
		message("info", "You'll blow up if you drink another drop!", 
			TP);
		return 1;
	}
        message("info", "You drink from the halflings fountain. "
               "The water is cool and refreshing.", TP);
	TP->add_quenched(-1000);
	count = 0;
	while( (TP->query_quenched() < 450) && (count < 90 ) ) {
		TP->add_quenched(5);
		count += 1;
	}
        switch(random(3)) {
                case 0: drink = " shoves "+(string)TP->query_possessive()+
			" face into the "
                        "fountain and takes a long drink of water.";
			break;
		case 1: drink = " takes a drink of water from the "
                        "fountain.";
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
                write(CAP(str)+ " is not here at the fountain.");
		return 1;
	}
	write("You splash "+CAP(str)+" in the face!");
	say(TPQCN+" splashes water at "+CAP(str)+"!");
	return 1;
}

int get(){
  return 0;
}
