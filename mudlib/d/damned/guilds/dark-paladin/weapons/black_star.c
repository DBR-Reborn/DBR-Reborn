inherit "/std/weapon";

void create() {
::create();
set_ac(0);
set_name("black star");
set("id", ({ "star", "two handed star", "black star", "star of owedquar", "black star of owedquar" }));
set_short("%^BOLD%^%^BLUE%^The Black Star of Owedquar%^RESET%^");
set_long("This is a relatively long morning star, with a long handle fashioned completely of well crafted silver. The chain and extremely vicious spiked ball on its end are crafted of pure mcgrail and glow black and violet with considerable dark power.");
set_type("two handed flail");
set_quality(6);
set_weight(200);
set_property("no add quality", 1);
set_property("no decay", 1);
set_property("no save", 1);
set_material("mcgrail");
set_value(1000);
set_verb("ionize");
}
