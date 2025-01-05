inherit "/std/weapon";

void create() {
::create();
set_ac(0);
set_name("shadow spear");
set("id", ({ "spear", "two handed spear", "shadow spear", "spear of owedquar", "shadow spear of owedquar" }));
set_short("%^BOLD%^%^BLACK%^The Shadow Spear of Owedquar%^RESET%^");
set_long("This is a six foot long spear fashioned entirely of dark steel. It only has one rune which continously drains the light all around it.");
set_type("two handed polearm");
set_quality(6);
set_weight(150);
set_property("no add quality", 1);
set_property("no decay", 1);
set_property("no save", 1);
set_material("dark steel");
set_value(500);
set_verb("dim");
}
