inherit "/std/weapon";

	create() {
	::create();
	set_ac(1);
	set("id", ({"staff", "Staff of pestilence"}));
	set_short("Staff of Nurgle");
	set_long("This is the Staff of Nugle, on of the very few in existance.  The staff is only given to champions of nugle that have proved themselves in the wars of mortals.");
	set_type("two handed staff");
	set_quality(6);
	set_weight(200);
	set_wc(25, "fire");
	set_material("bone");
	set_verb("decay");
	set_property("no add quality", 1);
	set_wield("Your arm suddenly feels tired and worn.");
	set_hit_bonus(10);
	set_property("no decay", 1);
	set_value(0);
}
