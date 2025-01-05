#include <std.h>

inherit "/std/food";

 
void create() {
  ::create();
    set_name("apples");
    set_id( ({ "bag" }) );
    set_short("a bag of apples");
    set_long("A large bag of juicy apples, they appear fresh.");
    set_weight(30);
    set_strength(40);
    set_float_value(9.0);
    set_my_mess("The apples are fresh and tasty.\n");
    set_your_mess("eats a full bag of apples without sharing!\n");
    return;
}
