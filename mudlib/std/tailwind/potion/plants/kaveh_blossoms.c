inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("kaveh blossoms");
  set("id", ({"blossoms", "kaveh blossoms"}) );
  set("short", "a handful of kaveh blossoms");
  set("long", "In your hand is a beautiful kaveh blossom.  This "
              "flower is very rare in this land because of the harsh "
              "climate and generally poor soil.");
  set_weight(3+random(3));
  set_toxin_level(70+random(3));
  set_strength(4);
}
