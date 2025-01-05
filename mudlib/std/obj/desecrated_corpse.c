//   an desecrated corpse for summoning undead

inherit "/std/Object";

int level;

void create() {
  ::create();
  set_name("corpse");
  set_id(({ "corpse", "desecrated corpse" }));
  set_short("a desecrated corpse");
  set_long("This corpse has been desecrated for use in summoning a demonic prince.");
  set_weight(40);
  set_value(2);
  return;
}

void set_level(int x) {
  if(x <= 0) return;
  level = x;
  set_short(sprintf("a level %d desecrated corpse", x));
  set_id(({ "corpse", "desecrated corpse",
      sprintf("level %d desecrated corpse", x),
      sprintf("level %d corpse", x) }));
  set_property("level", x);
  return;
}

int query_level() { return query_property("level"); }

