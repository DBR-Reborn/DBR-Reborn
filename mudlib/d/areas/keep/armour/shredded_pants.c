inherit "/std/armour";

/* This is a pair of nearly useless leather pants. These are worn by the zombie mobs that lurk in the misty field surrounding the black keep */

void create() {
::create();
set_name("shredded pants");
set("id", ({ "pants", "shredded pants" }));
set_short("A pair of shredded pants");
set_long("This is a pair of extremely worn out and torn pants, fashioned of cheap thin leather.");
set_type("leather legs");
set_ac(5);
set_limbs(({ "right leg", "left leg" }));
set_value(0);
set_weight(50);
set_material("leather");
}
