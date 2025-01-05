inherit "/std/armour";

/* This is the headpiece worn by the undead warriors in the black keep. It gives inferior level protection to the head, the rough equivalent of steel armour forged by a mid to high level merchant. */

void create() {
::create();
set_name("bone mask");
set("id", ({ "mask", "bone mask", "skull mask", "bone skull mask" }));
set_short("A bone crafted skull mask");
set_long("This mask is expertly fashioned to closely resemble a humanoid skull. It looks very frightening.");
set_type("metal face");
set_ac(75);
set_limbs(({ "head" }));
set_value(150);
set_weight(150);
set_material("bone");
}
