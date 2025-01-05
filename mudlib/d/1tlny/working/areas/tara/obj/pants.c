inherit "/std/armour";

void create() {
   string var;
   ::create();
   set_name("pants");
   set("id", ({ "pants", "bright pants" }) );
   switch(random(5)){
      case 0: var = "A bright green pair of pants"; break;
      case 1: var = "A bright blue pair of pants"; break;
      case 2: var = "A bright red pair of pants"; break;
      case 3: var = "A bright orange pair of pants"; break;
      case 4: var = "A bright yellow pair of pants"; break;
    }
      this_object()->set("short", var);
   set("long", @PANTS
This pair of pants if made out of leather.  It has been dyed to a bright
color, to suit the fashion needs of the halflings.
PANTS
   );
   set_weight(100);
   set_value(5); 
   set_type("leather legs"); 
   set_limbs( ({ "right leg", "left leg" }) );
   set_ac(6);
   set_material("misc/leather");
}
