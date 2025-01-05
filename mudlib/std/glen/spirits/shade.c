inherit "/std/glen/spirits/base_spirit";

void create() {
    ::create();
    set_skill("spiritmancy", 200);
    set_skill("curse lore", 200);
    set_spell_level("devour soul", 6);
    set_spell_level("darken soul", 6);
    set_spell_level("shatter soul", 6);

    add_spell("devour soul", "$A");
    add_spell("darken soul", "$A");
    add_spell("shatter soul", "$A");
    return;
}

void copy_body(object ob){
    string *skills;
    int i;

    ::copy_body(ob);

    undead_data["name"] = "shade";
    undead_data["ids"] = undead_data["ids"] + ({ "shade" });
}

void setup_body(){
    ::setup_body();

    set_max_hp(query_max_hp() * 2);
    set_hp(query_max_hp());

}

string query_short(){
    return "Shade of " +undead_data["short"];
}

