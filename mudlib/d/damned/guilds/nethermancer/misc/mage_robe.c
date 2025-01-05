inherit "/std/armour";

void create() {
    ::create();
    set_name("robe");
    set("id", ({ "robe", "purple robe", "black robe", "purple and black robe" }));
    set_short("A purple and black robe");
    set_long("This is a very neat and somewhat intimidating robe. It is mostly black with several patches of purple added in intelligent places to give it a very imposing overall color.");
    set_type("robe");
    set_ac(75);
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg" }));
    set_value(3000);
    set_weight(60);
    set_material("leather");
}
