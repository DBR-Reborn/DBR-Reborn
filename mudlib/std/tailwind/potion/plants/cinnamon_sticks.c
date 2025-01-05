inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("cinnamon sticks");
  set("id", ({"cinnamon", "sticks"}) );
  set("short", "a few cinnamon sticks");
  set("long", "These sticks are from the common cinnamon tree, a plant usually "
              "easy to find anywhere.  The sticks are long and somewhat "
              "wide, resembling a tube.");
  set_weight(3+random(7));
  set_toxin_level(75+random(5));
  set_strength(4);
  crit_type = "blindness";
  crit_level = "D";

}
