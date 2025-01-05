inherit "/std/armour";

void create() {
  ::create();
   set_name("dress");
   set("id", ({ "dress", "teen dress" }) );
   set("short", "A small green dress");
   set("long", @DRESS
This is a dress which is used by a teenage halfling.  It is smaller
then most the dresses worn by halfling women, and a little tighter
around the waste.  It is a bright green color, making it appear ugly
to all but halflings.
DRESS
   );
   set_weight(75);
   set_value(10);
   set_type("cloth torso");
   set_limbs( ({ "torso", "right leg", "left leg" }) );
   set_ac(8);
   set_material("misc/cloth");
}
