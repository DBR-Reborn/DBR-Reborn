inherit "/std/glen/spirits/base_spirit";

void create() {
    ::create();
    set_skill("spiritmancy", 500);
    set_skill("curse lore", 500);
    set_spell_level("devour soul", 6);
    set_spell_level("darken soul", 6);
    set_spell_level("shatter soul", 6);
    set_spell_level("greater curse", 6);
    set_spell_level("black curse", 6);
    set_spell_level("fatigue", 6);
    set_spell_level("disease black plague", 6);
    set_spell_level("disease rot", 6);
    set_spell_level("disease bone rot", 6);

    add_spell("devour soul", "$A");
    add_spell("darken soul", "$A");
    add_spell("shatter soul", "$A");
    add_spell("greater curse", "$A");
    add_spell("black curse", "$A");
    add_spell("disease black plague", "$A");
    return;
}

void copy_body(object ob){
    string *skills;
    int i;

    ::copy_body(ob);

    undead_data["name"] = "wraith lord";
    undead_data["ids"] = undead_data["ids"] 
    + ({ "wraith", "wraith lord" });

}

void setup_body(){
    ::setup_body();

    set_max_hp(query_max_hp() * 3);
    set_hp(query_max_hp());
    set_property("enhance criticals", 
      -2 + (int)query_property("enhance criticals"));
}



string query_short(){
    return "Wraith Lord of " +undead_data["short"];
}

