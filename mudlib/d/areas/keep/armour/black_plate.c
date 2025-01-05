inherit "/std/armour";

/* This is a breast plate forged of extremely durable black steel. It is worn on the torso by the black keep's powerful shadow knight mobs. It offers slightly higher AC than a high merchants steel armour. */

void create() {
::create();
set_name("black plate");
set("id", ({ "plate", "black plate", "pitch black plate" }));
set_short("A pitch black breast plate");
set_long("This breast plate, fashioned of dark steel and pitch black in color, appears and feels extremely durable and capable of withstanding punishment.");
set_type("metal torso");
set_ac(60);
set_limbs(({ "torso" }));
set_value(1000);
set_weight(400);
set_material("dark steel");
}
