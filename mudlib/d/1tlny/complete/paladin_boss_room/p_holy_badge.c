inherit "/std/armour";

void create() {
	::create();
	set_name("holy badge");
	set("id", ({"holy", "holy badge", "badge"}) );
	set("short", "A holy bade");
	set("long",
		"Special badge that can be worn on the chest.  "
	);
	set_type("holy badge");
	set_ac(12);
	set_limbs( ({ "torso" }) );
	set_value(5000);
	set_weight(120);
}
