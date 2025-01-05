#include <std.h>

inherit "/std/obj/torch";

void create() {
    ::create();
    set_name("small candle");
    set_id( ({ "candle", "small candle" }) );
    set_short("A small candle");
    set_long("A small candle made from fat and hair.\n");
    set_weight(5);
    set_property("no save",0);
    set_value(0);
}

