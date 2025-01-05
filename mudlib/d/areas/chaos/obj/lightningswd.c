inherit "/std/weapon";

	create() {
	::create();
	set_ac(1);
	set("id", ({"sword", "sword of dancing light"}));
	set_short("Sword of Dancing electricty");
	set_long("A sword, forged from the blacksmiths of chaos, this sword has been embued the power of living lightning from the mountains inhabited by the dragon-ogres.");
	set_type("blade");
	set_quality(6);
	set_weight(120);
	set_wc(18, "lightning");
	set_verb("electrify");
	set_property("no add quality", 1);
	set_wield("Sharp jolts of electricty jump up and down your arm as you wield the sword.");
	set_hit_bonus(10);
	set_value(2000);
}
