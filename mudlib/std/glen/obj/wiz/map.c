#include <std.h>
#include <colors.h>

inherit "/std/food";

void create() {
    ::create();
    set_name("map");
    set_id(({"map", "moldy map"}));
    set_short("a strange map");
    set_long("This moldy old map depicts the south.  "+
      "It shows the US from kansas to florida.  ");
    set_strength(10);
    set_my_mess("You eat the moldy map.");
    set_your_mess("eats a map.");
    set_value(0);
}

