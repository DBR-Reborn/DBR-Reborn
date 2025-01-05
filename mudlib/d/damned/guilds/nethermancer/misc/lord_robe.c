inherit "/std/armour";

void create() {
    ::create();
    set_name("robe");
    set("id", ({ "robe", "red robe", "black robe", "red and black robe" }));
    set_short("A %^RED%^red%^RESET%^ and %^BOLD%^%^BLACK%^black%^RESET%^ robe");
    set_long("This is an extremely thick black robe, covered almost entirely by numerous and intricate red designs. The overall appearance of the robe gives the impression that it was intended to be worn by an extraordinarily imposing figure.");
    set_type("robe");
    set_ac(100);
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg", "right foot", "left foot"  }));
    set_value(6666);
    set_weight(90);
    set_material("leather");
}
