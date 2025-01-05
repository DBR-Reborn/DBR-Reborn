inherit "/std/weapon";

void create() {
::create();
set_ac(0);
set_name("black hammer");
set("id", ({ "hammer", "two handed hammer", "black hammer", "hammer of owedquar", "black hammer of owedquar" }));
set_short("%^BOLD%^%^BLUE%^The Black Hammer of Owedquar%^RESET%^");
set_long("This is a noticeable large hammer with a large handle completely fashioned of pure silver. At its end is a perfectly square block of mcgrail inscribed with numerous runes which glows black and violet with dark energy.");
set_type("two handed blunt");
set_quality(6);
set_weight(200);
set_property("no add quality", 1);
set_property("no decay", 1);
set_property("no save", 1);
set_material("mcgrail");
set_value(1000);
set_verb("ionize");
}
