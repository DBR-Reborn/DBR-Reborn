inherit "/std/armour";

/* This is the grey robe worn by the Necromancer in the black keep. It covers the same limbs a normal robe covers, those being the torso, right arm, left arm, right leg, and left leg. Its protection is higher than that of the warlock's robe, but not nearly as high as the all limb robe worn by Owedquar's Shadow. */ 

void create() {
::create();
set_name("grey robe");
set("id", ({ "robe", "light robe", "light grey robe", "grey robe" }));
set_short("A light grey robe");
set_long("This robe is a very bright grey, and is relatively long covering everything from the neck down except the hands and feet. It is extremely lightweight and blows very easily at the slightest gust of windy air.");
set_type("robe");
set_ac(100);
set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg" }));
set_value(30000);
set_weight(1);
set_material("leather");
}
