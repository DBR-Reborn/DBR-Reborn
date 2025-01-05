inherit "/std/glen/spirits/base_spirit";

void create() {
    ::create();
    set_skill("spiritmancy", 120);
    set_skill("curse lore", 120);
    set_spell_level("weaken", 6);
    set_spell_level("lesser curse", 6);
    set_spell_level("disease cold", 6);
    set_spell_level("consume soul", 6);
    add_spell("weaken", "$A");
    add_spell("lesser curse", "$A");
    add_spell("disease cold", "$A");
    add_spell("consume soul", "$A");
    return;
}

void copy_body(object ob){
    string *skills;
    int i;

    ::copy_body(ob);

    undead_data["name"] = "shadow";
    undead_data["ids"] = undead_data["ids"] + ({ "shadow" });
}

string query_short(){
    return "Shadow of " +undead_data["short"];
}

