//TLNY2020 added to Goblin boss room d/camps/goblin/areas/s/m2
inherit "/std/armour";

void create() {
	::create();
	set_name("hooded robe");
	set("id", ({"robe", "hooded  robe" }) );
	set("short", "hooded robe");
	set("long",
		"Long flowing robes that cover almost the entire body. as well as your head  "
	);
	set_type("robe");
	set_ac(20);
	set_limbs( ({ "torso", "head", "left arm", "right arm", "left leg",
		"right leg", "left foot", "right foot", "left hand", "right hand" }) );
	set_value(400);
	set_weight(100);
	set_material("cloth");
}
