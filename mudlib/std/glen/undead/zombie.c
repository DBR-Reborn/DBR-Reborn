inherit "/std/glen/undead/base_undead";

void create() {
    ::create();
    return;
}

void copy_body(object ob){
    string *skills;
    int i;

    ::copy_body(ob);
    // set all skills to 2/3 what they were
    skills = query_all_skills();
    for(i = 0; i < sizeof(skills); i++){
	set_skill(skills[i], 
	  query_base_skill(skills[i]) * 2 / 3);
    }
    undead_data["name"] = "zombie";
    undead_data["ids"] = undead_data["ids"] + ({ "zombie" });
    set_max_hp(query_max_hp() * 2);
    set_hp(query_max_hp());
}

void setup_body(){
    ::setup_body();
    set_max_hp(query_max_hp() * 2);
    set_hp(query_max_hp());
}

string query_short(){
    return "Zombie of " +undead_data["short"];
}


