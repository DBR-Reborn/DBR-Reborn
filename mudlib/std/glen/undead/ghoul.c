
inherit "/std/glen/undead/base_undead";

void create() {
    ::create();
    return;
}

void copy_body(object ob){
    string *skills;
    int i;

    ::copy_body(ob);
    // set all skills to 4/5 what they were
    skills = query_all_skills();
    for(i = 0; i < sizeof(skills); i++){
	set_skill(skills[i], 
	  query_base_skill(skills[i]) * 4 / 5);
    }
    undead_data["name"] = "ghoul";
    undead_data["ids"] = undead_data["ids"] + ({ "ghoul" });
}

string query_short(){
    return "Ghoul of " +undead_data["short"];
}

