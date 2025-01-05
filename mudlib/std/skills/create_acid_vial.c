// modded by Glen

inherit "/std/skills/skill";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(5);
    set_fast_dev_cost(24);
    set_property("no target", 1);
}

void info() {
    message("help",
      "This skill creates a volatile vial of acid that may be "+
      "thrown as a weapon.  A higher skill will make a more lethal "+
      "vial of acid.  You must be on the Mountains to use this skill.",
      this_player());
}

void skill_func(object from, object at, string arg) {
    int skill = props["skill level"];
    object ob;

    if(environment(from)->query_terrain() != "M"){
	message("info", "You must use this skill in the Mountains.", from);
	remove();
	return;
    }

    if((time() - (int)from->query_last_use("create acid vial")) < 10){
	message("info", "You may not use that skill again yet.", from);
	remove();
	return;
    }
    from->set_last_use("create acid vial");
    ob = new("/std/glen/obj/acid_vial");
    ob->set_create_skill(random(skill) + 1);
    ob->move(from);
    message("info",
      "You create a vial of acid.", from);
    message("info",
      from->query_name() + " creates a vial of some sort.",
      all_inventory(environment(from)), from);
    remove();
    return;
}

