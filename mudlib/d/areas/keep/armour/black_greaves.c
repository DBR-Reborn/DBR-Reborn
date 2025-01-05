inherit "/std/armour";

/* This is a pair of greaves forged of extremely durable black steel. They are worn exclusively by the shadow knights residing on the black keep's second floor. They give slightly higher AC than the steel armour forged by a high level merchant. */

void create() {
::create();
set_name("black greaves");
set("id", ({ "greaves", "black greaves", "pitch black greaves" }));
set_short("A pitch black pair of greaves");
set_long("This is an extremely durable pair of greaves. They are fashioned of dark steel and to your eyes appear pitch black.");
set_type("metal legs");
set_ac(60);
set_limbs(({ "right leg", "left leg" }));
set_value(1000);
set_weight(400);
set_material("dark steel");
}
