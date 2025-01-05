// Wizard: Hood
// leather mask
// l_mask.c


inherit "/std/armour";
object shadow;

void create() {
    ::create();
set_name("leather mask");
set("id", ({"mask","leather mask", "black mask","black leather mask"}) );
set("short","A black leather mask");
set("long","Crafted from hard and soft black leather, this "
"mask covers the entire head.  Two holes have been left in "
"the front for the wearers eyes, as well as another for the "
"mouth.  A small slit has been made for breathing through the nose. "
"Thin steel bars have been stitched into the leather to provide "
"some add protection to the head, as well as the nose.\n");
    set_weight(20);
    set_value(50);
    set_type("leather face");
    set_limbs( ({ "head" }) );
    set_ac(10);
set_material("misc/leather");
set_wear( (: call_other, this_object(), "wear_mask" :) );
set_remove( (: call_other, this_object(), "remove_mask" :) );
}
int wear_mask(){
shadow=clone_object("/wizards/hood/shadow");
shadow->sh_init(this_player());
return 1;
}
