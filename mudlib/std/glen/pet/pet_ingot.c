// base inherit for demon class
#include <colors.h>

inherit "/std/pet";

void die(){
    object ob;
    message("info", CYELLOW + "All the life is beaten out of the ingot.  " +
      "It returns to its inanimate state.",
      environment());
    ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material(query_material());
    ob->move(environment(this_object()));
    remove();
}

int do_damage(string limb, int amt) {
    object prev = previous_object();
    return ::do_damage(limb, 1);
}

void create() {
    ::create();
    set_name("ingot");
    set_id(({ "ingot", "pet" }));
    set("race", "ingot");
    set_body_type("ingot");
    set_attack(0);
    set_carry(0);
    set_save(1);
    set_level(1);
    set_bodyguard(0);
    set_short("Pet Ingot");
    set_long("This little ingot has come to life");
    set_aggr_status(0);
    return;
}

void set_up(int power) {
    string desc;
    int hn = prop("hardness") * power / 60;
    set_overall_ac(hn);
    set_max_hp(hn);
    set_hp(hn);
    desc = query_material();
    if(!desc)desc = "/metal/iron";
    desc = replace_string(desc, "/metal/", "");
    set_short("Pet " + desc + " ingot");
    return;
}


