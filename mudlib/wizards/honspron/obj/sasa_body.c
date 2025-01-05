//   A SASA BODY


inherit "/std/Object";

int level;

void create() {
  ::create();
  set_name("body");
  set_id(({ "body", "sasa body" }));
  set_short("a sasa body");
  set_long("This body is used to create sasa.");
  set_weight(40);
  set_value(2);
  return;
}
