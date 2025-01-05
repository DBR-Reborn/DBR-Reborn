inherit "/std/Object";

void create() {
  ::create();
  set_id( ({ "mud" }) );
  set_name("mud");
  set_short("A pile of mud");
  set_long("Mud for making golems.");
  set_weight(5);
  set_value(100);
  return;

}
