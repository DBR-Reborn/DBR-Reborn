inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("carshina twigs");
  set("id", ({"carshina twigs", "twigs"}) );
  set("short", "a handful of carshina twigs");
  set("long", "These large brownish twigs are from the branches of the "
              "tall, common geckin tree.  It is said that these twigs can "
              "be used to create both curative and poisonous substances.");
  set_weight(3+random(5));
  set_toxin_level(55+random(4));
  set_strength(3);
}
