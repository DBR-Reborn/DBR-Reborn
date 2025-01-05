inherit "/std/weapon";

	create() {
	::create();
	set_ac(1);
	set("id", ({"sword", "searing sword"}));
	set_short("Searing sword of reality");
	set_long("A sword of chaos, it is smelted in the forges of chaos, runes of power run along the side of the sword, as you look carefully at the sword, the area around it seems to warp.");
	set_type("blade");
	set_quality(6);
	set_property("enchantment", 5);
	set_weight(120);
	set_wc(18, "vacuum");
	set_verb("distort");
	set_property("no add quality", 1);
	set_wield("The area around the sword shifts around as you wield it");
	set_hit_bonus(20);
	set_value(1000);
}
