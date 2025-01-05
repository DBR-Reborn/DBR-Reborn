//   an embalmed corpse for summoning undead

inherit "/std/Object";

int level;

void create() {
  ::create();
  set_name("body");
  set_id(({ "body", "everlasting body" }));
  set_short("an everlasting body");
  set_long("This body is used to create an everlasting.");
  set_weight(40);
  set_value(2);
  return;
}
