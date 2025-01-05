inherit "/std/weapon";

/* This is a two handed polearm axe that looks similar to a great axe, only it has a more complex design and its blade is larger. It is almost identical to a virtual weapon but it carries a special purpose. It is the only weapon in the armour that is not virtual, and if the player catches on to it, he can take the grand axe to the clone statues chamber of the keep. There he can insert the weapon into the open hands of the fifth statue and fight the blue wyvern mini-boss to get the red gem needed to activate the red orb on the second floor, part of the crystal key quest. */

void create() {
::create();
set_ac(0);
set_name("grand axe");
set("id", ({ "axe", "grand axe" }));
set_short("grand axe");
set_long("This is a very large polearm, almost seven feet long. It has a large double sided axe blade at its top having its center molded onto the weapon, an even larger blade than that of a great axe."); 
set_type("two handed polearm");
set_quality(6);
set_weight(300);
set_material("iron");
set_value(100);
set_verb("chop");
}
