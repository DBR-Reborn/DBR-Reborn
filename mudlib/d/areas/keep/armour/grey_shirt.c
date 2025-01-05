inherit "/std/armour";

/* This is the dark grey shirt worn by the Necromancer mini-boss present in the black keep. It covers the torso and arms and gives cyan level protection. */

void create() {
::create();
set_name("grey shirt");
set("id", ({ "shirt", "grey shirt", "dark grey shirt" }));
set_short("A dark grey shirt");
set_long("This shirt is relatively think and is somewhat wrinkled yet smooth. It covers the torso and arms very tightly.");
set_type("cloth torso");
set_ac(100);
set_limbs(({ "torso", "right arm", "left arm" }));
set_value(20000);
set_weight(25);
set_material("leather");
}
