inherit "/std/Object";

int level;

void create() {
  ::create();
  set_name("undead dragon scale");
  set_id(({ "scale", "undead dragon scale", "scales" }));
  set_short("an undead dragon scale");
  set_long("These scales are used to create an undead dragon.");
  set_weight(40);
  set_value(2);
  return;
}
