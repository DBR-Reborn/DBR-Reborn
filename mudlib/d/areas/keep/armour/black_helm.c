inherit "/std/armour";

/* This is a black helm and mask combination worn on the head of the shadow knights roaming the black keep's upper level. It is worn on the head and provides slightly higher protection than high merchant steel armour. */

void create() {
::create();
set_name("black helm");
set("id", ({ "helm", "black helm", "pitch black helm", "mask", "black mask", "pitch black mask", "helm and mask" }));
set_short("A pitch black helm and mask");
set_long("This is a combination of a helm and an intimidating mask of what appears to be an ancient warrior's face. It is pitch black in color and when worn drives fear into the enemy while providing excellent protection.");
set_type("metal head");
set_ac(60);
set_limbs(({ "head" }));
set_value(1000);
set_weight(150);
set_material("dark steel");
}
