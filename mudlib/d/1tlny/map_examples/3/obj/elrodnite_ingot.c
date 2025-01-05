//elrodnite_ingot.c coder:Byon
#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("ingot");
    set_id(({ "ingot" }));
    set_material("metal/elrodnite");
    set_short("an elrodnite ingot");
    set_long("This ingot can be melted into a blank, or sold for "
    "money.");
    set_weight(70);
    set_value(125);
    return;
}
