inherit "/std/glen/spirits/base_spirit";

void create() {
    ::create();
    set_skill("spiritmancy", 120);
    set_skill("curse lore", 120);
    set_spell_level("lesser curse", 6);
    set_spell_level("fatigue", 6);
    set_spell_level("disease yellow fever", 6);
    add_spell("lesser curse", "$A");
    add_spell("fatigue", "$A");
    add_spell("disease yellow fever", "$A");
    return;
}

void copy_body(object ob){
    string *skills;
    int i;

    ::copy_body(ob);

    undead_data["name"] = "ghast";
    undead_data["ids"] = undead_data["ids"] + ({ "ghast" });
}

string query_short(){
    return "Ghast of " +undead_data["short"];
}

