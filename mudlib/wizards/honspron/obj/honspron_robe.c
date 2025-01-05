inherit "/std/armour";

void create() {
    ::create();
    set_name("jedi robe");
    set("id", ({ "robe", "honspron robe" }));
    set_short("%^BLUE%^Jedi Robe%^RESET%^");
    set_long("This is Honspron’s robe");
    set_type("robe");
    set_ac(5000);
    set_property("extra ac",5000);
    //set_property("enchantment",50);
    set_property("armour bonus",1000);
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg", "right foot", "left foot", "head", "left hand", "right hand"  }));
    set_value(99999);
    set_weight(90);
    set_enh_critical(-500);
    set_material("leather");
    set_ac(5000, "aether");
    set_ac(5000, "infernal");
    set_ac(5000, "unholy");
    set_ac(5000, "holy");
    set_ac(5000, "plasma");
    set_ac(5000, "disruption");
    set_ac(5000, "electricity");
    set_ac(5000, "vacuum");
    set_ac(5000, "cold");
    set_ac(5000, "fire");
    set_ac(5000, "stress");
    set_ac(5000, "impact");
    set_ac(5000, "strike");
    set_ac(5000, "impaling");
    set_ac(5000, "cutting");
    set_ac(5000, "crushing");
}