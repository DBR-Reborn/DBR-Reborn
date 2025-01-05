inherit "/std/armour";

/* These are the grey pants worn by the Necromancer in the black keep. They provide cyan protection on both the right and left leg. */

void create() {
::create();
set_name("grey pants");
set("id", ({ "pants", "grey pants", "dark grey", "dark grey pants", "pair of pants", "grey pair of pants", "dark grey pair of pants" }));
set_short("A dark grey pair of pants");
set_long("These pants, dark grey in color, appear smooth but slightly wrinkled.");
set_type("cloth legs");
set_ac(60);
set_limbs(({ "right leg", "left leg" }));
set_value(20000);
set_weight(25);
set_material("leather");
}
