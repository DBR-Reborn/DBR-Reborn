inherit "/std/armour";

/* This is a relatively large blood red robe worn by the vampiric demons in the black keep. The robe offers inferior on protection limb on both arms, both legs, and the torso, equivalent to that of most leather crafted with high skill from a corpse the level of the vampiric demons. */  

void create() {
::create();
set_name("red robe");
set("id", ({ "robe", "blood robe", "red robe", "blood red robe" }));
set_short("A blood red robe");
set_long("This robe, bright blood red in color and relatively large, appears very demonic in nature.");
set_type("robe");
set_ac(75);
set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg" }));
set_value(1000);
set_weight(50);
set_material("leather");
}
