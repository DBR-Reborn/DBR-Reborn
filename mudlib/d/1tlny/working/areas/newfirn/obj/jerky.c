//  Wizard:  Gellor
//  Jerky
//  jerky.c
#include <std.h>
inherit "/std/food";
void create() {
  ::create();
    set_name("jerky");
    set_id( ({ "jerky", "meat" }) );
    set_short("a greasy piece of jerky");
      set_long("A fairly large piece of greasy jerky.");
    set_weight(25);
    set_strength(50);
    set_float_value(10.0);
    return;
}
