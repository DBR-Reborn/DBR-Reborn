inherit "/std/weapon";

	create() {
	::create();
	set_name("mp5");
	set("id", ({"mp5", "gun", "weapon", "smg", "mp5/10"}));
	set_short("An MP5/10");
	set_long("The MP5 is the standard weapon Daybreak Ridge Defense Force. This particular model has been chambered for 10mm ammo, and holds a 30 round clip.");
	set_type("sub-machine gun");
        set_weight(7);
	set_quality(6);
	set_property("no add quality", 1);
	set_property("no decay", 1);
	set_weight(180);
	set_wc(200, "impact");
	set_verb("shoot");
	set_hit_bonus(200);
	set_ac(1);
	set_value(1000000000);
}
