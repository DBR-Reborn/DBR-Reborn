inherit "/std/weapon";

/* This is the horribly powerful spear staff wielded by Owedquar's Shadow, the ruler of the black keep. It has truly insane power that few if any weapons in existence can match, even those fully chanted and runed by players. The downside is that the weapon has max brittleness and cannot be enhanced. */

void create() {
::create();
set_ac(0);
set_name("spear staff");
set("id", ({ "ultima umbra", "spear staff", "spear", "staff" }));
set_short("%^RED%^Ultima Umbra%^RESET%^, %^RED%^the Legendary Spear Staff of Owedquar%^RESET%^");
set_long("This is the legendary tool of magic casting and war wielded by the powerful Owedquar's Shadow. It is an enormous combination of a spear and a staff, covered with an insane amount of glowing jewels with a point at the end fashioned of hardened trapped light from a star itself. As you grip the weapon with both hands, you feel catastrophic evil flow directly into your body and the weapon glows pulsing red. You then instantaneously know this object of destruction was not constructed in this realm or any other realm you could possibly imagine, and that TRUE power is in your grasp.");  
set_type("two handed polearm");
set_wield("%^BLUE%^Phantasmagoric power enters your body immediately upon gripping the weapon.%^RESET%^");
set_unwield("The rush of sickening power leaves your body in what seems to be a millisecond and you feel extremely disoriented.");
set_property("brittle", 200);
set_quality(6);
set_property("no add quality", 1);
set_property("no decay", 1);
set_weight(500);
set_material("unearthly material");
set_value(250000);
set_wc(250, "impaling");
set_wc(250, "cutting");
set_wc(250, "crushing");
set_wc(250, "fire");
set_wc(250, "cold");
set_wc(250, "air");
set_wc(250, "electricity");
set_verb("obliterate");
}
