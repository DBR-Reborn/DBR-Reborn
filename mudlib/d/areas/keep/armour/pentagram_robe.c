inherit "/std/armour";

/* This is a secret item that can be obtained by searching the abandoned room near the great hall of the keep, which is blocked by a red door requiring the blood stained key found outside to open. The robe is unique for a special item because even though it adds good skill bonuses, namely 30% increase in rifting, demon lore, and circle lore, it carries a drawback. That drawback is that when the robe is worn, ALL protection on the entire body drops to none. */

void create() {
::create();
set_name("pentagram robe");
set("id", ({ "robe", "pentagram robe" }));
set_short("Pentagram Robe");
set_long("This is a large red and black robe shaped exactly like a demonic pentagram. As it touches parts of your body, it glows fiercely and you feel as if it is junctioning with your soul.");
set_type("robe");
set_ac(-10000);
set_limbs(({ "torso", "head", "right arm", "right leg", "right foot", "right hand", "left foot", "left arm", "left leg", "left hand" }));
set_wear("You feel your soul junction with the robe as you put it on.");
set_remove("You feel liberated as you remove the robe from your body.");
//TLNY2020 do not have this code
//add_bonus_skill("rifting", 30);
//add_bonus_skill("circle lore", 30);
//add_bonus_skill("demon lore", 30);
set_value(5000);
set_weight(50);
set_material("leather");
}
