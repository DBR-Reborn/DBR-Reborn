inherit "/std/weapon";

/* This is the two handed sword wielded by the ferocious shadow knights living on the keeps upper level. It is a very powerful mob weapon, among the best, and despite the fact it cannot be runed it fares half decent against runed weaponry. However, to balance this it comes innate with [XX---] chance of breaking brittleness */

void create() {
::create();
set_ac(0);
set_name("dark cleaver");
set("id", ({ "sword", "two handed sword", "cleaver", "dark sword", "dark cleaver" }));
set_short("%^BOLD%^%^WHITE%^Dark Cleaver%^RESET%^");
set_long("This is an enormous two handed sword. It is fashioned entirely, handle and all, out of pure mcgrail, and the blade is constantly wrapped in flowing darkness.");
set_type("two handed blade");
set_property("brittle", 35);
set_quality(6);
set_weight(300);
set_material("mcgrail");
set_value(25000);
set_wc(100, "cutting");
set_wc(100, "impaling");
set_wc(100, "stress");
set_wc(100, "disruption");
set_verb("cleave");
}
