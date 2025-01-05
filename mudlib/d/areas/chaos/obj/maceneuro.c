inherit "/std/weapon";

	create() {
	::create();
	set_ac(1);
	set("id", ({"mace", "Neural Mace of Depression"}));
	set_short("Neural Mace of Depression");
	set_long("A mace of chaos, dark veins run along the side of the mace up to a skull like top.  The skull is fashioned from a grey type steel");
	set_type("blunt");
	set_quality(6);
	set_weight(120);
	set_wc(25, "impact");
	set_verb("depress");
	set_property("no add quality", 1);
	set_wield("You feel dizzy as you wield the mace.");
	set_hit_bonus(20);
	set_value(2000);
}
