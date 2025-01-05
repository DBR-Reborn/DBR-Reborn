inherit "/std/armour";

/* This is a virtually useless shirt. It is worn by the zombie mobs lurking in the misty field outside the black keep. */

void create() {
::create();
set_name("tattered shirt");
set("id", ({ "shirt", "old shirt", "tattered shirt", "old tattered shirt" }));
set_short("An old tattered shirt");
set_long("This is a very thin, heavily torn and rotting shirt.");
set_type("cloth torso");
set_ac(5);
set_limbs(({ "torso" }));
set_value(0);
set_weight(50);
set_material("leather");
}
