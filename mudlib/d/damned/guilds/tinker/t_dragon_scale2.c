inherit "/std/armour";

void create() {
	::create();
	set_name("rare dragon shard");
	set("id", ({"shard", "dragon shard", "rare"}) );
	set("short", "rare dragon shard");
	set("long",
		"Special dragon scale that can be worn on the chest.  "
	);
	set_type("dragon scale");
	set_ac(12);
	set_limbs( ({ "torso" }) );
	set_value(5000);
	set_weight(120);
}
