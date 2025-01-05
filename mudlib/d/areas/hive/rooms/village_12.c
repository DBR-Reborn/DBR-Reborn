//      Wizard:  Myrddin
//      village_12.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
   }  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Village Square");
    set("long",
	"You are at the village square, if it can be called that.  A "
              "spring is here for those that are thirsty.  It is probably the "
              "main reason the village was built at this location.  There "
              "area around the spring is well kept and is probably used "
              "for special functions.\n" );
    set("night long",
             "Shadows cast on the buildings by the fire to the north dance "
             "in the night.  Still, it is probably better then the solid "
             "darkness of the less well lit areas of the village.  As you "
             "stand in the village square, you note a spring in the center of "
             "it, as well as the path leading off in four directions.\n");
    set_smell("default", "The smell of smoke overpowers all other "
                   "smells inside the village.");
    set_listen("default", "You hear some noise coming from the north "
                    "end of the village.");
    set_items(([
     ({ "path" }) :
         "It is well worn from constant traffic within the village.",
     ({ "spring" }) :
         "The water is slowly trickling out of a large rock.  A simple but "
         "effective wooden basin has been built to hold the water for "
         "drinking.  They probably store the water in barrels when the "
         "springs basin gets too full.",
     ({ "village" }) :
         "It is definitely small.  Not many people could live in it "
         "comfortably.",
    ({ "building", "buildings" }) :
         "They are, not surprisingly, made from wood.  They have a "
         "basic construction, but are probably functional.",
    ({ "shadows" }) :
         "They are dancing on nearby buildings.  But no, they are not as "
         "good as the dancing girls you saw the last time you were in "
         "Akkad.",
    ({ "glow", "fire" }) :
         "The glow from the fire dominates the northern end of the "
         "village.  From here you can see flames rising at least 8 feet "
         "into the air.",
]));
    set_exits((["north":HIV_ROOMS+"village_13.c",
                     "south":HIV_ROOMS+"village_11.c",
                     "east":HIV_ROOMS+"village_17.c",
                     "west":HIV_ROOMS+"village_15.c"])); 
}

//  The code after this point is taken from the fountain/vat files and
//  modified.  It you copy everything after this exactly, it will let 
//  players fill waterskins and max out their drinking level with
// a single drink.  Note that it is a spring right now as well, not
// a fountain.  It has no other emotes or abilities.

void init() {
  :: init();
              add_action("drink_spring","drink");
	add_action("fill_vessel", "fill");
}

int drink_spring(string str) {
	string drink;
	int count;
	if(!str) {
		notify_fail("What do you want to drink?\n\n");
		return 0;
	}
	if( !(str == "spring") ) { 
		notify_fail("What do you want to drink?\n\n");
		return 0; 
	}
	if(TP->query_quenched() > 420) {
		message("info", "You'll blow up if you drink another drop!", 
			TP);
		return 1;
	}
	message("info", "You take a long drink of water from the clear "
	"spring.  You feel very refreshed.", TP);
	TP->add_quenched(-1000);
	count = 0;
	while( (TP->query_quenched() < 450) && (count < 90 ) ) {
		TP->add_quenched(5);
		count += 1;
	}
	switch(random(4)) {
		case 0: drink = " shoves "+(string)TP->query_possessive()+
			" face into the "
			"spring and takes a long drink of water.";
			break;
		case 1: drink = " takes a drink of water from the "
			"spring.";
			break;
		case 2: drink = " takes up a bucket and finishes it "
			"off with a wipe of the chin.";
 			break;
		case 3: drink = " laps up some water at the spring.";
			break;
	}
	say(TPQCN+drink);
	return 1;
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


