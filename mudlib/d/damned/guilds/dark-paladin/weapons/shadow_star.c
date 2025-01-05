inherit "/std/weapon";

void create() {
::create();
set_ac(0);
set_name("shadow star");
set("id", ({ "star", "two handed star", "shadow star", "star of owedquar", "shadow star of owedquar" }));
set_short("%^BOLD%^%^BLACK%^The Shadow Star of Owedquar%^RESET%^");
set_long("This is a relatively long morning star, with a long handle fashioned completely of well crafted steel. The chain and vicious spiked ball on its end are crafted of dark steel and seem to darken the area.");
set_type("two handed flail");
set_quality(6);
set_weight(150);
set_property("no add quality", 1);
set_property("no decay", 1);
set_property("no save", 1);
set_material("dark steel");
set_value(500);
set_verb("dim");
}
