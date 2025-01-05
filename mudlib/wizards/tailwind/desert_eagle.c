inherit "/std/weapon";

	create() {
	::create();
	set_name("desert eagle");
	set("id", ({"de", "eagle", "weapon", "pistol", "desert eagle"}));
	set_short("A Desert Eagle");
	set_long("The Desert Eagle is the uniform sidearm of all members of the Daybreak Ridge Defense Force. It holds 7 .50 caliber rounds - enough to blow the limbs off of anyone and everyone very quickly.");
	set_type("pistol");
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
