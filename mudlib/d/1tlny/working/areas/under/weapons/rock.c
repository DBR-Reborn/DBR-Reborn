inherit "/std/weapon";

create() {
	::create();
	set_ac(1);
	set("id", ({"rock"}));
	set_short("A large obsidian rock");
	set_long("This is a large obsidian rock about the size of a honey-dew melon.");
	set_type("blunt");
	set_quality(2);
	set_name("rock");
	set_property("decay", 250);
	set_property("no add quality",1);
	set_value(60);
	set_weight(750);
	set_wc(20, "crushing");
	set_throwable(1);

return;
	set_wield("You feel like a monkey using this as a weapon.");
	set_hit_bonus(-5);
}
