inherit "/std/weapon";

void create() {
::create();
set_ac(0);
set_name("shadow hammer");
set("id", ({ "hammer", "two handed hammer", "shadow hammer", "hammer of owedquar", "shadow hammer of owedquar" }));
set_short("%^BOLD%^%^BLACK%^The Shadow Hammer of Owedquar%^RESET%^");
set_long("This is a noticeable large hammer completely fashioned of dark steel. At its end is a square block of dark steel inscribed with one rune which seems to be draining the light around it.");
set_type("two handed blunt");
set_quality(6);
set_weight(150);
set_property("no add quality", 1);
set_property("no decay", 1);
set_property("no save", 1);
set_material("dark steel");
set_value(500);
set_verb("dim");
}
