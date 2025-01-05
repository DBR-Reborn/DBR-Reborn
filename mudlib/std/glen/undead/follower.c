inherit "/std/glen/undead/base_undead";

void create() {
    ::create();
    set_change_ownership(0);
    set_learning_spells(1);
    set_intelligent(1);
    return;
}

void copy_body(object ob){
    string *skills;
    int i;

    ::copy_body(ob);
    undead_data["name"] = "follower";
    undead_data["ids"] = undead_data["ids"] + ({ "follower" });
}

string query_short(){
    return ::query_short() + " (follower) ";
}


