inherit "std/armour";

void create() {
   string var;
   ::create();
   set_name("hat");
   set("id", ({ "hat", "bright hat" }) );
   switch(random(5)){
      case 0: var = "A green hat"; break;
      case 1: var = "A blue hat"; break;
      case 2: var = "A red hat"; break;
      case 3: var = "A orange hat"; break;
      case 4: var = "A yellow hat"; break;
   }
     this_object()->set("short", var);
   set("long", @HAT
This hat is made to cover a small head, it is definately made for
a female.  It has a cute feather sticking out of the top, which is
a new fad for teenage halflings.
HAT
   );
   set_weight(50);
   set_value(6);
   set_type("coth head");
   set_limbs( ({ "head" }) );
   set_ac(4);
   set_material("misc/cloth");
}
