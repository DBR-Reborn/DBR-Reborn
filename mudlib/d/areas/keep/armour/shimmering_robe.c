inherit "/std/armour";

/* This robe is the most powerful piece of mob armour on the mud, for it gives 250 AC to all major limbs. However, it is worn by the Owedquar's Shadow boss on the second floor of the black keep, meaning it is excessively difficult to obtain. */

void create() {
::create();
set_name("shimmering robe");
set("id", ({ "robe", "shimmering robe", "black robe", "blue robe", "black and blue robe", "shimmering black robe", "shimmering blue robe", "shimmering black and blue robe" }));
set_short("A shimmering black and blue robe");
set_long("The intricate black and blue designs of this robe strike you as you look upon it. It is a replica of the legendary robe worn by the dark god Owedquar himself, as told by an inscription on its left side. It is shimmering with a powerful energy, hinting that when worn it provides incredible protection against aggressors.");
set_type("robe");
set_ac(250);
set_limbs(({ "torso", "left hand", "right hand", "left arm", "right arm", "right leg", "left leg", "right foot", "left foot", "head" }));
set_value(250000);
set_weight(50);
set_material("unknown leather");
}
