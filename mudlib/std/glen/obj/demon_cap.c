#include <std.h>

inherit OBJECT;

int charges = 0;

int is_demon_captivator(){
    return 1;
}

void set_charges(int x){
    charges = x;
}

int query_charges(){
    return charges;
}

void decay(){
    charges--;
}

int cap_func(string str){
    object *inv;
    int i;
    if(charges < 1)
	return 0;
    if(!wizardp(TP) && TP->query_class() != "demon-master") {
      message("info","You do not possess the knowledge to use this item!", TP);
      return 1;
    }
    message("info", "You hold the symbol in the air and "+
      "yell, 'Bow to your master!'"
      , this_player());
    say(this_player()->query_name() + " holds a strange " +
      "demonic symbol in the air, and yells in a strange tongue.",
      this_player());
    inv = all_inventory(environment(this_player()));
    for(i = 0; i < sizeof(inv); i++){
	if(!living(inv[i]))continue;
	if(inv[i]->query_race() != "demon")continue;
	if(!inv[i]->query_is_demon())continue;
	inv[i]->set_owner(this_player()->query_name());
	if(inv[i]->query_owner() != this_player()->query_name())
	    inv[i]->force_me("say Yes new master.");
	inv[i]->cease_all_attacks();
	inv[i]->set_speed(0);
	inv[i]->set_aggr_status(0);
	if(objectp(inv[i]->query_casting()))
	    ((object)inv[i]->query_casting())->remove();
	inv[i]->set_casting(0);
	inv[i]->cease_all_attacks();
    }
    this_player()->cease_all_attacks();
    decay();  
    return 1;
}

void init() {
    add_action("cap_func", "conscript");
}

void create() {
    ::create();
    set_name("star");
    set_id( ({ "symbol", "demon symbol", "star", "demonic star" }) );
    set_short("A demonic star shaped symbol");
    set_long("This demonic symbol shows a pact of obedience "+
      "of demons from the outer planes to the one who hold it.  "+
      "You may use this symbol by 'conscript' command to "+
      "call for the allegiance of demons.");
    set_weight(5);
    set_value(0);
}

string query_short() {
    string title;
    switch(charges){
    case 0:
	title = "(crumbling)";
	break;
    case 1..5:
	title = "(faint)";
	break;
    case 6..10:
	title = "(faintly lit)";
	break;
    case 11..15:
	title = "(glowing)";
	break;
    case 16..25:
	title = "(strongly glowing)";
	break;
    case 26..40:
	title = "(strongly glowing)";
	break;
    case 41..10000:
	title = "(perfectly preserved)";
	break;
    }
    return ::query_short() + " " + title;
}


