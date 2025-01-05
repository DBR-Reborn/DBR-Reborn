inherit "/std/armour";
void create() {
    ::create();
    set_name("cloth hooded cloak");
    set("id", ({ "cloak", "cloth hooded cloak" }) );
    set("short", "A cloth cloak");
    set("long", "Made of fine light-weight, comfortable fabric, this "
    			    "cloak is a very dark shade of blue. It's material "
                "is one that makes little noise when it's wearer "
                "moves around. It is slightly loose fitting for "
                "additional comfort.");
    set_weight(50);
    set_value(150);
    set_type("cloth back");
    set_limbs( ({ "torso", "right arm", "left arm", "head" }) );
    set_ac(10);
        set_ac(10, "fire");
        set_ac(10, "cold");
        set_ac(5, "impact");
        set_ac(5, "stress");
        set_material("misc/cloth");
}
