#include <std.h>
#include "../newshards.h"

inherit "/std/room";

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    add_exit(ROOMS+"street4", "east");
    set_short("The Demon's Demise Tavern");
    set("long",
      "Obviously the focal point of the town, the Demon's Demise tavern is where most of the inhabitants apparently spend their evenings. Tables and chairs are everywhere, and small groups of people talk quietly. A bar in the corner dispenses drinks. A menu is on the wall behind it.");
    set_items(
      (["tables":"Worn heavily, but still in good shape.",
	"menu":(: call_other, this_object(), "read", "menu" :),
	"bar" : "It has a lot of scratches, but the craftsmanship is fairly good.",
	"chairs" : "Sturdy, but not all too comfortable. You decline to sit down.",
	"groups" : "They're talking about you, you know it!" ]) );
}

void reset() {
    ::reset();
    if(!present("preston")) 
	new(MON+"preston")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

    if(!str) return 0;
    if(lower_case(str) != "menu") return notify_fail("There is no '"+str+"' here.\n");
    ob = present("golg");
    if(!ob) {
	write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    write("The following great foods are served here at the Dragon's Demise Tavern.");
    write("--------------------------------------------------------------------");
    write(sprintf("%30s %d silver", "A tankard of mead", (int)ob->get_price("mead")));
    write(sprintf("%30s %d silver", "A mug of ale", (int)ob->get_price("ale")));
    write(sprintf("%30s %d silver", "A shot of single malt whiskey", (int)ob->get_price("whiskey")));
    write(sprintf("%30s %d silver", "A loaf of bread", (int)ob->get_price("bread")));
    write(sprintf("%30s %d silver", "A leg of mutton", (int)ob->get_price("mutton")));
    write(sprintf("%30s %d silver", "A dragon steak", (int)ob->get_price("steak")));
    write("-----------------------------------------------------------");
    write("<buy item> gets you the food or drink.");
    return 1;
}

