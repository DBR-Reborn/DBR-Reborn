inherit "/std/Object";

string golem_name = "mud_golem";

void create() {
  ::create();
  set_id( ({ "body", "golem body", "mud golem body" }) );
  set_name("body");
  set_short("A mud golem body");
  set_long("This is a golem body, created from some thick and ugly mud.");
  set_weight(5);
  set_value(100);
  return;
}

// Gotta set this stuff - otherwise the life spells don't know what to clone.

string query_golem_name() { return golem_name; }

int is_golem() { return 1; }
