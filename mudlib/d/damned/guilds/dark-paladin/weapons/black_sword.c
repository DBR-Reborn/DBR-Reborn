inherit "/std/weapon";

void create() {
::create();
set_ac(0);
set_name("black sword");
set("id", ({ "sword", "two handed sword", "black sword", "sword of owedquar", "black sword of owedquar" }));
set_short("%^BOLD%^%^BLUE%^The Black Sword of Owedquar%^RESET%^");
set_long("This is a very powerful weapon adeptly crafted of perfectly pure mcgrail. The handle is wrapped in mystic silver, and its blade is covered with ancient inscriptions and shimmers black and violet endlessly.");
set_type("two handed blade");
set_quality(6);
set_weight(200);
set_property("no add quality", 1);
set_property("no decay", 1);
set_property("no save", 1);
set_material("mcgrail");
set_value(1000);
set_verb("ionize");
}
