inherit "/std/armour";

/* This is the amulet worn by Owedquar's Shadow on the second floor of the black keep. It provides very little physical protection, but it does have one special use, when worn it gives 100% bonuses to concentrate, spell sense, fast casting and focus casting. This may seem like a lot, but the skills boosted do not cause any imbalance within the game, even if a newbie got to wear it, plus the amulet is extremely hard to get because to get it the player must kill Owedquar's Shadow. */  

void create() {
::create();
set_name("amulet");
set("id", ({ "amulet", "amulet of hades", "hades amulet" }));
set_short("The Amulet of Hades");
set_long("This is an extremely valuable looking amulet, with a fear striking skull imbued in the center of a perfectly circular surface. The eyes of the skull pulsate a fierce red, and you feel as if the amulet is speaking into your soul, granting you unspeakable power.");
set_type("neck");
set_wear("You place the amulet around your neck, and almost immediately you feel a rush of power flow into your soul as well as a voice speaking incomprehensible words.");
//TP->add_skill_bonus("concentrate", 100);


set_remove("You remove the amulet and feel extremely wierd as your body almost instanteneously returns to normal.");

//add_bonus_skill("spell sense", 100);
//add_bonus_skill("focus casting", 100);
//add_bonus_skill("fast casting", 100);
set_ac(5);
set_limbs(({ "head" }));
set_value(250000);
set_weight(100);
set_material("unearthly material");
}
