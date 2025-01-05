inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("myrh seeds");
  set("id", ({"seeds", "myrh seeds"}) );
  set("short", "a handful of myrh seeds");
  set("long", "These tiny, white seeds are from a small tan flower "
              "called a myrh.  Such seeds are usually hard to come by."
);
  set_weight(3+random(4));
  set_toxin_level(45+random(3));
  set_strength(4);
  crit_type = "blindness";
  crit_level = "C";
}
