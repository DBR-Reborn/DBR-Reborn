inherit "/std/armour";

void create() {
    ::create();
    set_name("hood");
    set("id", ({ "hood", "purple hood", "black hood", "purple and black hood" }));
    set_short("A purple and black hood");
    set_long("This is a small but notably comfortable hood. Its color is mostly black but several patches of purple are present throughout it in very well thought out places to make it appear very intimidating if worn on the head of a frightening enough mage.");
    set_type("leather head");
    set_ac(75);
    set_limbs(({ "head" }));
    set_value(2500);
    set_weight(45);
    set_material("leather");
}
