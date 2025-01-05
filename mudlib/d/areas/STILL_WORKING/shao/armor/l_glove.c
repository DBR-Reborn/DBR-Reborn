// Wizard: Hood
// Leather glove
// l_glove.c
// used in Sabrina's House of Leather cuz I'm 
//to stupid right now to make them virtualy for the shop.


inherit "/std/armour";

void create() {
    ::create();
set_name("black glove");
set("id", ({"glove","black glove","black leather glove","leather glove"}) );
set("short", "black-leather glove");
set("long","This is a black soft-leather glove, "
"it looks very well crafted.\n");
    set_weight(50);
    set_value(1);
    set_type("leather hand");
    set_limbs( ({ ({ "right hand", "left hand", 
      "first branch", "second branch", "third branch", "fourth branch" }) }) );
set_material("misc/leather");
set_ac(7);
}
