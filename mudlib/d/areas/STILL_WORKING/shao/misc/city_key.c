//  Wizard:  Khojem
//  sand Key
//  sand_key.c

#include <std.h>

inherit OBJECT;

void create() {
    ::create();
set_name("city key");
set_id( ({ "key", "city key" }) );
set_short("city key");
set_long("A small iron key with shao-tan markings.\n");
    set_weight(1);
    set_value(0);
}
