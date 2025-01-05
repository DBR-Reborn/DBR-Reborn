#include <std.h>
#include <colors.h>

inherit OBJECT;

int power = 1;

int query_is_chalk(){
    return 1;
}

int query_is_circle(){
    return 1;
}

void set_power(int x){
    power = x;
    set_property("no clean", 1);
}

int query_power(){
    return power;
}

void decay(){
    message("The circle is erased.", this_player());
    remove();
}

void create() {
    ::create();
    set_name("circle");
    set_id( ({ "circle", "chalk circle"}) );
    set_short( CBOLD+CWHITE+ "A chalk circle" +CRESET);
    set_long("A ritual circle made out of chalk.\n");
    set_weight(1000000);
    set_property("no clean",1);
    set_value(0);
}

