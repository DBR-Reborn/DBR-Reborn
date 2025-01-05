inherit "/std/armour";

create() {
    ::create();
    set_name("robe");
    set("id", ({"robe", "robe of taul"}) );
    set_short("The robe of Taul");
    set_long("This plan brown robe bears the symbol of taul.");
    set_type("pants");
    set_weight(0);
    set_value(0);
    set_limbs( ({"head", "torso", "right arm", "left arm",
	"right hand", "left hand", "left leg", "right leg",
	"right foot", "left foot"}));
    set_material("metal/mcgrail");
    set_property("no save", 1);
}
void set_up(int skill){
    set_ac(skill);
    set_property("enhance criticals", -1*skill / 50);
}


