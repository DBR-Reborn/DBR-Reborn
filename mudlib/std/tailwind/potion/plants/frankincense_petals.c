inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("frankincense petals");
  set("id", ({"frankincense petals", "petals"}) );
  set("short", "a handful of frankincense petals");
  set("long", "These large petals are from the frankincense tree, a rare tree "
              "famous for its great aroma and pleasant taste. ");
  set_weight(3+random(5));
  set_toxin_level(92+random(4));
  set_strength(5);
  crit_type = "paralysis";
  crit_level = "E";

}
