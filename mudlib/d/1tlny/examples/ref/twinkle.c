//twinkle.c coder:Byon
#include <std.h>
inherit WEAPON;
void create() {
    ::create();
    set_name("twinkle");
    set_id( ({"scimitar","twinkle"}) );
    set_short("A scimitar named Twinkle");
    set_long("The scimitar belonging to Drizzt Do'Urden, named Twinkle.  It
glows with an eerie blue light.");
    set_parry_bonus(50);
    set_weight(120);
    set_value(500);
    set_material("metal/catoetine");
    set_verb("slice");
    set_type("blade");
    set_wc(40, "cutting");
    set_wc(45, "impaling");
    set_ac(10);
    set_property("no decay", 1);
    set_property("no add quality", 1);
    set_quality(6);
}
