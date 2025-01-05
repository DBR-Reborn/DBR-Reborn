inherit "/std/weapon";

	create() {
	::create();
	set_ac(5);
	set("id", ({"axe", "axe of blood"}));
	set_short("Axe of atrocity");
	set_long("An axe of chaos, this axe is one given only to powerful champions of chaos, as it is immensly heavy and hard to wield, but at the same time it is destructive and awesome.");
	set_type("two handed blade");
	set_quality(6);
	set_property("no decay", 1);
	set_weight(300);
	set_wc(25, "cutting");
	set_verb("gash");
	set_property("no add quality", 1);
	set_wield("As you wield the axe an evil feeling rushes into you.");
	set_hit_bonus(20);
	set_property("enchantment", 5);
	set_parry_bonus(-30);
	set_value(5000);
}
