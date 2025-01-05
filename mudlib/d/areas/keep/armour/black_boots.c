inherit "/std/armour";

/* This is a pair of boots worn by the shadow knight mobs in the black keep. Forged of black steel, they are worn on both feet and offer slightly higher protection than a high merchants steel. */

void create() {
::create();
set_name("black boots");
set("id", ({ "boots", "black boots", "pitch black boots" }));
set_short("A pitch black pair of boots");
set_long("These boots appear extremely dark and durable, with the potential to absorb a good deal of punishment.");
set_type("metal foots");
set_ac(60);
set_limbs(({ "right foot", "left foot" }));
set_value(1000);
set_weight(150);
set_material("dark steel");
}
