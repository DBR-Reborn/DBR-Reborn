inherit "/std/weapon";

/* This axe is a hidden weapon that can only be found in the room dividing the grand library and the basement entrance. To find it, the player must push the brick on the left wall containing the torch bearing. The brick will then fall through the wall, revealing the weapon. Powerwise, it is about the same as the shadow knights dark cleaver weapon, more powerful than manor chaotic longswords but not powerful enough to warrant adding innate brittleness. */

void create() {
::create();
set_ac(0);
set_name("black axe");
set("id", ({ "axe", "black axe" }));
set_short("black axe");
set_long("This is a medium sized hand axe, pitch black in appearance from both the blade and the handle. It appears to have been heavily used and abused, likely for breaking cracks in stone for construction and design purposes judging by its somewhat dull edge.");
set_type("axe");
set_quality(3);
set_weight(75);
set_material("dark steel");
set_value(10000);
set_wc(100, "cutting");
set_wc(100, "stress");
set_verb("whack");
}
