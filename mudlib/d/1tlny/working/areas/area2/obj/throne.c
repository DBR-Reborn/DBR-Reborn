// throne

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("a throne");
    set_id( ({ "throne" }) );
    set_short("The king's throne");
    set_long("The throne is made up of many old bones patched together "+
    "with vines and mat to make a strange chair that sits about 6 feet "+
    "tall.");
    set_weight(9999);
    set_value(0);
}
