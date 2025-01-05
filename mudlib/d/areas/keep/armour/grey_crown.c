inherit "/std/armour";

/* This is the crown worn on the head by the Necromancer mini-boss in the black keep. It provides cyan protection and covers the head. */

void create() {
::create();
set_name("grey crown");
set("id", ({ "crown", "grey crown", "priest crown", "light grey crown", "light grey priest crown", "grey priest crown" }));
set_short("A light grey priest crown");
set_long("This is a light grey crown very closely resembling that of a priest. It carries the insignia of Owedquar on its front suggesting it was worn by a practicioner of undead and/or chaotic power.");
set_type("metal head");
set_ac(75);
set_limbs(({ "head" }));
set_value(20000);
set_weight(50);
set_material("leather");
}
