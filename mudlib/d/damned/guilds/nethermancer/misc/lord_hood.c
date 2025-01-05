inherit "/std/armour";

void create() {
    ::create();
    set_name("hood");
    set("id", ({ "hood", "red hood", "black hood", "red and black hood" }));
    set_short("A %^RED%^red%^RESET%^ and %^BOLD%^%^BLACK%^black%^RESET%^ hood");
    set_long("This is a notably thick hood, providing an extremely comfortable but very hot covering to the head. Its color is a very artistic combination of both red and black, the design made to look as it if was intended to be worn by a staggeringly powerful sorcerer.");
    set_type("leather head");
    set_ac(100);
    set_limbs(({ "head" }));
    set_value(4900);
    set_weight(50);
    set_material("leather");
}
