inherit "/std/armour";

/* This is a metallic necklace crafted by dark steel. It provides very little protection, has no special use, and is generally used for decoration on the dark robed warlock mobs in the black keep that wear them. */

void create() {
::create();
set_name("skull necklace");
set("id", ({ "necklace", "metallic necklace", "skull necklace", "metallic skull necklace" }));
set_short("A metallic skull necklace");
set_long("A menacing skull centered between two chains, all of which are pitch black in color, comprise this necklace. Based on its appearance, it likely blends in with a robe and hood for decoration on a powerful magus to strike fear into its aggressors.");
set_type("neck");
set_type("bracelet");
set_ac(5);
set_limbs(({ "head" }));
set_value(2000);
set_weight(50);
set_material("dark steel");
}
