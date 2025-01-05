inherit "/std/armour";

void create() {
   string var;
   ::create();
   set_name("shirt");
   set("id", ({ "shirt", "bright shirt" }) );
   switch(random(5)){
      case 0: var = "A bright green shirt"; break;
      case 1: var = "A bright blue shirt"; break;
      case 2: var = "A bright red shirt"; break;
      case 3: var = "A bright orange shirt"; break;
      case 4: var = "A bright yellow shirt"; break;
    }
      this_object()->set("short", var);
   set("long", @SHIRT
This cloth shirt has been dyed a bright color to fit into the
halfling culture and fashion.
SHIRT
   );
   set_weight(100);
   set_value(10);
   set_type("cloth torso"); 
   set_limbs( ({ "torso" }) );
   set_ac(9);
   set_material("misc/cloth");
}
