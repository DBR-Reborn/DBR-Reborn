inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("saffron blossoms");
  set("id", ({"saffron blossoms", "blossoms"}) );
  set("short", "several saffron blossoms");
  set("long", "Saffron blossoms are small, pink flowers that are normally "
              "found in desert areas, but have been known to grow in less "
              "dry places.");
  set_weight(3+random(5));
  set_toxin_level(29+random(4));
  set_strength(4+random(3));
  crit_type = "blindness";
  crit_level = "A";

}
