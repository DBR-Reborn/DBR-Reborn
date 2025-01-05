inherit "/std/Object";

void create() {
  ::create();
  set_id( ({ "dyes", "color dyes" }) );
  set_name("dyes");
  set_short("A set of color dyes.");
  set_long("These dyes are used for coloring alchemist potions. They look completely worthless.");
  set_weight(5);
  set_value(0);
  return;
}
