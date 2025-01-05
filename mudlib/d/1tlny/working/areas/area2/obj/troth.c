// troth

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("a troth");
    set_id( ({ "troth" }) );
    set_short("a dry water troth");
    set_long("This water troth was once used for animals and Half-orcs "+
    "alike.  It doesn't seem to bother you much that it's now empty, "+
    "seeing as how it's covered in grime.");
    set_weight(9999);
    set_value(0);
}
