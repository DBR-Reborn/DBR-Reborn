inherit "/std/Object";

string golem_name = "flesh_golem";

void create() {
    ::create();
    set_id( ({ "body", "golem body", "flesh golem body" }) );
    set_name("body");
    set_short("A flesh golem body");
    set_long("This is a golem body, created from some random pieces of flesh.");
    set_weight(5);
    set_value(100);
    return;
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


