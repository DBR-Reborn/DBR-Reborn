inherit "/std/armour";

void create() {
	::create();
	set_name("rare dragon scale");
	set("id", ({"scale", "dragon scale", "rare"}) );
	set("short", "rare dragon scale");
	set("long",
		"Special dragon scale that can be worn on the chest.  "
	);
	set_type("dragon scale");
	set_ac(12);
	set_limbs( ({ "torso" }) );
	set_value(5000);
	set_weight(120);
}
