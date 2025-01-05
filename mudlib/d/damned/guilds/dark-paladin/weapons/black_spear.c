inherit "/std/weapon";

void create() {
::create();
set_ac(0);
set_name("black spear");
set("id", ({ "spear", "two handed spear", "black spear", "spear of owedquar", "black spear of owedquar" }));
set_short("%^BOLD%^%^BLUE%^The Black Spear of Owedquar%^RESET%^");
set_long("This is a six foot long spear fashioned entirely of highly pure mcgrail. It shimmers endlessly with black and violet energy and is covered completely with numerous engravings and runes.");
set_type("two handed polearm");
set_quality(6);
set_weight(200);
set_property("no add quality", 1);
set_property("no decay", 1);
set_property("no save", 1);
set_material("mcgrail");
set_value(1000);
set_verb("ionize");
}
