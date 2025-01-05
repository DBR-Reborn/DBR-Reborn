inherit "/std/armour";

void create() {
    ::create();
    set_name("dragon skin");
    set("id", ({ "skin", "dragon skin" }));
    set_short("dragon skin");
    set_long("This is a dragons skin");
    set_type("robe");
    set_ac(500);
    set_property("extra ac",500);
    set_property("armour bonus",200);
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg", "right foot", "left foot", "head", "left hand", "right hand"  }));
    set_value(99999);
    set_weight(90);
    set_enh_critical(-7);
    set_material("leather");
    set_ac(2000, "aether");
    set_ac(2000, "infernal");
    set_ac(2000, "unholy");
    set_ac(2000, "holy");
    set_ac(2000, "plasma");
    set_ac(2000, "disruption");
    set_ac(2000, "electricity");
    set_ac(2000, "vacuum");
    set_ac(2000, "cold");
    set_ac(2000, "fire");
    set_ac(2000, "stress");
    set_ac(2000, "impact");
    set_ac(2000, "strike");
    set_ac(2000, "impaling");
    set_ac(2000, "cutting");
    set_ac(2000, "crushing");
    
    set_wear((: call_other, this_object(), "check_dragon" :));
    return;
}

int check_dragon() {

  if((string)this_player()->query_race() != "undead dragon") {

    write("%^ORANGE%^The dragon skin disintegrates as you attempt to wear it.%^RESET%^");
	remove();
    return 0;

  }
return 1;
}
