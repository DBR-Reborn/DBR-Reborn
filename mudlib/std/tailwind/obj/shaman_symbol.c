//  Wizard:  Khojem
//  Fir'nvillee Rock
//  rock.c
//  Altered by Tailwind for Shaman Guild.
//  set_type must be used for this object to work properly.

 
#include <std.h>

inherit OBJECT;

string type;
int set_type(string symboltype);
 
void set_up(){
    type = this_object()->query_type();
    switch(type) {
    case "fire":
	set_short("A piece of crystalized flame");
        set_id( ({"symbol", "shaman symbol", "flame", "crystal", "crystal flame"}) );
	break;
    case "sky":
	set_short("A piece of solid cloud");
        set_id( ({"symbol", "shaman symbol", "cloud", "solid cloud"}) );
	break;
    case "water":
	set_short("A hollow cube of ice with steam in the center");
        set_id( ({"symbol", "shaman symbol", "ice", "cube"}) );
	break;
    case "earth":
	set_short("A beautiful earthen crystal");
        set_id( ({"symbol", "shaman symbol", "earth", "crystal"}) );
	break;
    case "magic":
	set_short("A solid shard of magic energy");
        set_id( ({"symbol", "shaman symbol", "shard", "energy"}) );
	break;
    case "time":
	set_short("A leaf from an ungrown tree");
        set_id( ({"symbol", "shaman symbol", "leaf", "ungrown leaf"}) );
	break;
    case "life":
	set_short("A baby's tooth");
        set_id( ({"symbol", "shaman symbol", "tooth", "baby tooth"}) );
	break;
    case "death":
	set_short("A bottle with a dying man's moan");
        set_id( ({"symbol", "shaman symbol", "moan", "bottle"}) );
        break;
    default:
        set_short("Bugged Shaman Symbol");
        set_id( ({"symbol", "shaman symbol"}) );
    }

    set_long("This symbol is used for focusing spells of "+type+".");
}

void create() {
    ::create();
    set_name("symbol");
    set_short("Shaman Symbol");
    set_long("This symbol is used for focusing spells.");
    set_weight(5);
    set_value(1);
    call_out("set_up",0);
    return;
}

int is_elemental_symbol() { return 1; }

int set_type(string symboltype) {
this_object()->set_property("type", symboltype);
set_up();
return 1;
}

string query_type() {return this_object()->query_property("type");}
