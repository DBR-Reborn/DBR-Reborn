inherit "/std/armour";

/* This is the dark black robe that is worn exclusively by the dark robed warlocks in the black keep. It provides slightly better protection than the vampiric demons and death soldiers' red robes, and is comparable in protection to a robe crafted from very good skin. */

void create() {
::create();
set_name("dark robe");
set("id", ({ "robe", "dark robe", "wrinkled robe", "dark wrinkled robe" }));
set_short("A dark wrinkled robe");
set_long("This very dark colored robe carries an unusual amount of wrinkles, likely from extreme usage. It goes down to slightly above the feet, across the arms ending just before the hands, and completely over the torso.");
set_type("robe");
set_ac(75);
set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg" }));
set_value(3000);
set_weight(60);
set_material("leather");
}
