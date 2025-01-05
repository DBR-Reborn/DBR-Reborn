inherit "/std/weapon";

void create() {
    ::create();
    set_ac(0);
    set_name("halcyon axe");
    set("id", ({ "axe", "halcyon", "halcyon axe" }));
    set_short("%^BOLD%^%^BLUE%^Halcyon Axe%^RESET%^");
    set_long("This relatively large and surprisingly light one handed weapon is the legendary Halcyon Axe, believed to have be as old as the gods themselves and one of their sacred chosen weapons of war. Its handle and blade are heavily inscribed with ancient runes which blow blood red, suggesting that a powerful dark curse rests over this tool of power. Should the curse ever be dispelled, this weapon is believed by myth to be the owner of the unspecified but only means of defeating true evil.");
    set_type("axe");
    set_quality(6);
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_weight(50);
    set_material("hellsbane");
    set_value(1000000);
    set_wc(200, "disruption");
    set_wc(200, "disruption A");
    set_wc(200, "disruption B");
    set_wc(200, "infernal");
    set_wc(200, "infernal A");
    set_wc(200, "infernal B");
    set_wc(200, "darkness");
    set_wc(200, "darkness A");
    set_wc(200, "darkness B");
    set_verb("dessicate");
}
