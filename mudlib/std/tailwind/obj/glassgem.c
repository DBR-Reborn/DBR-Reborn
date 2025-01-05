//    An ingot!  You mine them and stuff!
// Look! Now's it a gem! Yay! -TW 12/18/00
// Modded to be super sucky but useful for Shaman newbies.

inherit "/std/Object";

void create() {
    ::create();
    set_name("glassgem");
    set_id(({"gem", "piece", "glass", "glassgem"}));
    set_short("A glass gem");
    set_long("This glass gem is capable of being made into a Shaman jewel. Barely. Beyond that, it's not all too useful.");
    set_material("glass");
    set_weight(100);
    return;
}

int query_value() {
    if(this_object()->prop("value")) return
	(int)this_object()->prop("value");
    else return ::query_value();
}

float query_float_value() {
    if(this_object()->prop("value")) return
	to_float((int)this_object()->prop("value"));
    else return ::query_float_value();
}

int is_gem() { return 0;}
