inherit "/std/armour";

/* This is a breast plate fashioned of hard bone that is worn by some of the monsters in the black keep. Its protection gives inferior on protection limb, which is slightly less than the steel armour forged by a great merchant. */

void create() {
::create();
set_name("bone plate");
set("id", ({ "plate", "bone plate" }));
set_short("A bone crafted breast plate");
set_long("This is a breast plate fashioned entirely of well crafted tough bone.");
set_type("metal torso");
set_ac(75);
set_limbs(({ "torso" }));
set_value(100);
set_weight(300);
set_material("bone");
}
