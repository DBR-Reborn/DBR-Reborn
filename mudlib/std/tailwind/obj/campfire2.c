// from nocte's kuril, borrowed by glen, stolen by TW
#include <std.h>

inherit OBJECT;

int length, roomlight, notnow;

void set_length(int time) {
    length=time;
    return;
}

int burn() {
    roomlight=environment(this_object())->query_property("light");
    environment(this_object())->set_property("light", roomlight+1);
    call_out("extinguish", length);
    return 1;
}

int piss(string str){
    if(strsrch(str, "fire"))
	return 0;
    if(this_player()->query_quenched() < 400){
	message("info", "Your bladder capacity is insufficient", this_player());
	return 1;
    }
    this_player()->add_quenched(-400);
    message("info", "You empty your bladder onto the unsuspecting fire",
      this_player());
    message("info", this_player()->query_cap_name() + 
      " relieves himself on the unsuspecting campfire and laughs.",
      all_inventory(environment(this_object())), this_player());
    remove();
}

int extinguish() {
    write("The fire goes out.");
    environment(this_object())->set_property("light", roomlight);
    this_object()->remove();
    return 1;
}

void create() {
    ::create();
    set_name("campfire");
    set_id( ({ "fire", "camp fire", "campfire" }) );
    set_long("This is a campfire. It keeps you warm when it's cold, hot when it's warm. You can 'send' a smoke signal or 'cook' food on it. It also provides a great deal of light.\n");
    set_weight(200000000);
    set_value(0);
    call_out("burn", 1);
}

void init() {
    ::init();
    add_action("do_message","send");
    add_action("cook_critter","cook");
    add_action("piss","piss");
}

int do_message(string message) {
    if(!present("blanket", this_player())) {
	message("info", "You need a blanket to send a smoke signal.",
	  this_player());
	return 1;
    }

    if(!message) {
	message("info", "You need to actually have a message to send.",
	  this_player());
	return 1;
    }

    if(notnow==1) {
	message("info", "You need to wait a bit more to get some more smoke to send a signal.", this_player());
	return 1;
    }

    message="You see a smoke signal rise in the air: " + message;
    message("shout", message, users());
    notnow=1;
    call_out("more_message", 120);
    return 1;
}

void more_message() {
    notnow=0;
    return;
}

int cook_critter(string str) {
    object ob;
    ob=present(str, this_player());

    if(!ob){
	write("You don't have that!");
	return 1;
    }

    if((ob->query_name() != "carcass")) {
	write("You can only cook foraged carcasses with a campfire.");
	return 1;
    }
    write("You cook the carcass. It now looks tasty.");
    ob->remove();
    ob = new("/std/food");
    ob->set_name("fillet");
    ob->set_id(({ "fillet"}) );
    ob->set_short("A tasty fillet");
    ob->set_long("This fillet of meat looks really good and tasty. You feel the urge to eat it.");
    ob->set_my_mess("You scarf down the fillet. It tastes great!");
    ob->set_your_mess("eats a fillet and grins.");
    ob->set_strength(150);
    ob->move(this_player());
    return 1;
}

