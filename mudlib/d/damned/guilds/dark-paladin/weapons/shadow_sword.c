inherit "/std/weapon";

void create() {
::create();
set_ac(0);
set_name("shadow sword");
set("id", ({ "sword", "two handed sword", "shadow sword", "sword of owedquar", "shadow sword of owedquar" }));
set_short("%^BOLD%^%^BLACK%^The Shadow Sword of Owedquar%^RESET%^");
set_long("This is a powerful weapon crafted of refined dark steel. The handle is wrapped in runed steel, and its blade is covered with drawings that seem to swirl with darkness.");
set_type("two handed blade");
set_quality(6);
set_weight(150);
set_property("no add quality", 1);
set_property("no decay", 1);
set_property("no save", 1);
set_material("dark steel");
set_value(500);
set_verb("dim");
}
