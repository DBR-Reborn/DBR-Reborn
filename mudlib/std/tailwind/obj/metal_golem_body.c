inherit "/std/Object";

string golem_name = "metal_golem";

void create() {
    ::create();
    set_id( ({ "body", "metal golem body", "metal body", "golem body" }) );
    set_name("body");
    set_short("A metal golem body");
    set_long("This is a metal golem body. Alchemists can use it with their 'life' spells.");
    set_weight(5);
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
    return capitalize(article(query_property("material_name") + " golem body"));
}

// Gotta set this stuff - otherwise the life spells don't know what to clone.

string query_golem_name() { return golem_name; }

int is_golem() { return 1; }
void set_create_skill(int x) {
    set_property("create skill", x);
}

int query_create_skill(int x) {
    return query_property("create skill");
}


