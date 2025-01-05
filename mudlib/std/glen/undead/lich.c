inherit "/std/glen/undead/base_undead";

void create() {
    ::create();
    set_change_ownership(0);
    set_combat_chance(160);
    set_can_change_aggr(1);
    return;
}

void copy_body(object ob){
    string *skills;
    int i;

    ::copy_body(ob);
    undead_data["name"] = "lich";
    undead_data["ids"] = undead_data["ids"] + ({ "lich" });

}

void setup_body(){
    ::setup_body();
    set_property("enhance criticals",
      query_property("enhance criticals") - 3);
    set_max_hp(query_max_hp() * 3);
    set_hp(query_max_hp());
}


string query_short(){
    return "Lich of " +undead_data["short"];
}


