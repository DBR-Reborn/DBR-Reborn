inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("tzari leaves");
  set("id", ({"leaves", "tzari leaves"}) );
  set("short", "a handful of tzari leaves");
  set("long", "In the palm of your hand is a few dozen small leaves "
              "from a tzari bush.  In the winter months, the tzari "
              "bush produces small, sweet-smelling, light pink flowers.");
  set_weight(3+random(2));
  set_toxin_level(40+random(4));
  set_strength(2);
  crit_type = "blindness";
  crit_level = "B";

}
