#include <std.h>

inherit OBJECT;

int writes;

int query_is_chalk(){
    return 1;
}

void set_charges(int x){
    writes = x;
}

int query_charges(){
    return writes;
}

void decay(){
    writes--;
    if(writes < 1){
	message("The chalk is used up and crumbles", this_player());
	remove();
    }
}

void create() {
    ::create();
    set_name("chalk");
    set_id( ({ "chalk", "chalk stick", "stick" }) );
    set_short("A chalk stick");
    set_long("A stick of chalk meant for writing or drawing.\n");
    set_weight(5);
    set_value(0);
}

string query_short() {
    switch(writes){
    case -1..8:
	return "A crumbling chalk stick";
    case 9..15:
	return "A dwindling chalk stick";
    case 16..20:
	return "A small chalk stick";
    case 21..25:
	return "A medium chalk stick";
    case 26..32:
	return "A large chalk stick";
    case 33..10000:
	return "A perfect chalk stick";
    }
    return "A chalk stick";
}

