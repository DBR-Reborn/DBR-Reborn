inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("galbanum vines");
  set("id", ({"galbanum", "galbanum vines", "vines"}) );
  set("short", "a couple of galbanum vines");
  set("long", "Galbanum vines are the small, soft vines from the sukurth "
              "plant, sometimes called the \"life vine\" because of its "
              "healing properties.");
  set_weight(3+random(5));
  set_toxin_level(97+random(4));
  set_strength(5);
  crit_type = "blindness";
  crit_level = "E";
}
