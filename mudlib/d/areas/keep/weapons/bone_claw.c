inherit "/std/weapon";

/* This is the white bone claw that is dual wielded by the undead warriors lurking throughout the black keep. The weapon itself is above average for a mob weapon, but is incomparable to mineral weapons forged by merchants. */

void create() {
::create();
set_ac(0);
set_name("bone claw");
set("id", ({ "claw", "white claw", "bone claw", "white bone claw" }));
set_short("sharp white claw");
set_long("This is a very sharp claw fashioned entirely of stark white bone. It has five blade edges and can be gripped with a small crafted handle to be used somewhat like a knife.");
set_type("knife");
set_quality(6);
set_weight(25);
set_material("bone");
set_value(2500);
set_wc(50, "cutting");
set_wc(50, "impaling");
set_verb("rip");
}
