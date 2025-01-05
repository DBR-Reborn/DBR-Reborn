inherit "/std/armour";

void create() {
    ::create();
    set_name("chainmail jacket");
    set("id", ({ "jacket" }) );
    set("short", "A chainmail jacket");
    set("long", "This jacket is made of the finest chain produced "
    				 "by the hands of the best Elven blacksmiths. It is "
                "remarkably lightweight and loose fitting while "
                "providing excellent protection.");
    set_weight(75);
    set_value(150);
    set_type("chain torso");
    set_limbs( ({ "torso", "right arm", "left arm" }) );
    set_ac(10);
        set_ac(30, "impact");
        set_ac(10, "stress");
        set_ac(10, "strike");
        set_ac(25, "crushing");
        set_material("misc/chainmail");
}
