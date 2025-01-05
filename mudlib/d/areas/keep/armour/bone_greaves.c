inherit "/std/armour";

/* This is a pair of greaves fashioned of hard bone that are worn by some of the black keep monsters. It gives inferior level protection on both legs, which is equivalent to that of the steel forged by a mid to high level merchant. */

void create () {
::create();
set_name("bone greaves");
set("id", ({ "greaves", "bone greaves" }));
set_short("A bone crafted pair of greaves");
set_long("This is a pair of greaves fashioned entirely of well crafted tough bone.");
set_type("metal legs");
set_ac(75);
set_limbs(({ "right leg", "left leg" }));
set_value(100);
set_weight(300);
set_material("bone");
}
