inherit "/std/armour";

   create() {
	::create();
	set_name("chaos armour");
	set("id", ({"suit", "chaos armour", "chaos armor", "armor"}));
	set_short("suit of heavy armour");
	set_long("A suit of heavy armour made from metal and crafted from the forges of chaos.");
	set_type("metal torso");
	set_ac(8);
	set_limbs( ({"torso", "left arm", "right arm", "left leg", "right leg"}) );


	set_value(500);
	set_weight(200);
}
