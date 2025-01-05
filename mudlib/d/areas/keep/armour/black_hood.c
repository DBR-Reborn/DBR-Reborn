inherit "/std/armour";

/* This hood is the head piece worn by the dark robed warlocks in the black keep. It provides cyan level protection, equivalent to that of leather forged from very good skins. */

void create() {
::create();
set_name("black hood");
set("id", ({ "hood", "black hood" }));
set_short("A black hood");
set_long("Covering the head relatively loosely, this dark black hood allows the entire face to be seen by the naked eye, but in a considerably darker light.");
set_type("cloth head");
set_ac(50);
set_limbs(({ "head" }));
set_value(2000);
set_weight(50);
set_material("leather");
}
