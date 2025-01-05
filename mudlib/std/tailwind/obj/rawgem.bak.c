//    An ingot!  You mine them and stuff!
// Look! Now's it a gem! Yay! -TW 12/18/00

inherit "/std/Object";

void create() {
    ::create();
    set_name("gem");
    set_id(({"gem", "piece"}));
    set_long("This raw gem can be used for all sorts of different things.");
    set_weight(100);
    return;
}

int id(string str) {
    if(::id(str)) return 1;
    if(::id(replace_string(str, query_property("material_name")+" ", "")))
	return 1;
    return 0;
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

string query_short() {
    return capitalize(article("raw piece of " +
	query_property("material_name")));
}

int is_gem() { return 1;}
