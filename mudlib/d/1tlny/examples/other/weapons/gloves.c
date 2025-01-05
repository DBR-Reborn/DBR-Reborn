inherit "/std/weapon";

	create() {
	::create();
	set_ac(15);
	set("id", ({"gauntlets", "glove", "claws"}));
	set_short("Spiked iron gauntlets");
	set_long("A gauntlets with four, two inch long spikes at the end of the knuckles.  The gauntlets are made exceptionally well from iron and leather.");
	set_type("melee");
	set_quality(6);
    set_verb("punch");
	set_property("decay", 1500);
	set_value(1000);
	set_wc(12, "impaling");
	set_wc(14, "impact");
	set_wc(2, "crushing");
	set_hit_bonus(5);
}
