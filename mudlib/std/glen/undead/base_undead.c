inherit "/std/pet";

#define HOUR (60*60)

int body_copied;
int inited = 0;
mapping pet_skills = ([]);
mapping pet_spells = ([]);
mapping undead_data = ([]);

void setup_body();

void set_data(string mapkey, mixed value){
    undead_data[mapkey] = value;
}

mapping dump_data(){ return undead_data; }
mapping dump_skills(){ return pet_skills; }
mapping dump_spells(){ return pet_spells; }

int is_ul_pet() { return 1; }

void create() {
    ::create();
    if(!body_copied)
	set_level(1);
    set("race", "undead");
    set_short("bug");
    set_long("bug");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_bodyguard(1);
    set_save(1);
    set_aggr_status(0);
    set_learning_spells(1);
    set_change_ownership(1);
    set_can_change_aggr(1);
    set_skill("concentrate", 120);
    set_skill("necromancy", 120);
    set_spell_level("instill fear", 6);
    add_spell("instill fear", "$A");
    set_combat_chance(80);
    set_property("no corpse", 1);
    inited = 0;
    set_property("type", "death");
    return;
}

void restore_stuff() {
    ::restore_stuff();
    setup_body();
}

void set_owner(string who) {
    object ob;

    ob = find_player(who);
    if(!ob) {
	set_languages(({ "undead-tongue", "common", "elvish", "dwarvish"} ));
    ::set_owner(who);
    return;
}
set_languages(({ "undead-tongue", "common", "elvish", "dwarvish",
    (string)ob->query_primary_lang() }) );
::set_owner(who);
return;
}

void set_up(int pow) {
    set_max_hp( pow * 50 + 80 );
    set_hp( pow * 50 + 80 );
    set_skill("melee", 30 + 7*pow);
    set_skill("dodge", 5 + 7*pow);
    set_skill("parry", 10 +7*pow);
    set_property("melee damage", ([ "cutting" : 3 + (2 * pow) ]) );
set_property("physical resistance",
  ([ "default" : 20, "iron" : 20, "steel" : 20, "wood" : 20 ]));
return;
}

void set_dur(int dur) {
    call_out("remove_servant", dur);
    return;
}

void remove_servant() {
    this_object()->force_me("drop all");
    message("info", "A "+query_short()+"crumbles to dust.",
      environment());
    remove();
    return;
}

void reduce_spells(){
    int i;
    string *keys;
    keys = keys(pet_spells);
    for(i = 0; i < sizeof(keys); i++)
	if(random(5) == 2 && pet_spells[keys[i]] > 0)
	    pet_spells[keys[i]]--;
    keys = keys(pet_skills);
    for(i = 0; i < sizeof(keys); i++)
	if(random(5) == 2 && pet_skills[keys[i]] > 0)
	    pet_skills[keys[i]] -= 5;
}

void setup_body(){
    int i;
    string *keys;
    inited = 1;
    if(!body_copied)
	return;
    set_level(undead_data["level"]);
    keys = keys(pet_skills);
    for(i = 0; i < sizeof(keys); i++)
	set_skill(keys[i], pet_skills[keys[i]]);
    keys = keys(pet_spells);
    for(i = 0; i < sizeof(keys); i++)
	set_spell_level(keys[i], pet_spells[keys[i]]);
    set_short(undead_data["short"]);
    set_long(undead_data["long"]);
    set_max_hp(undead_data["hp"]);
    set_max_mp(undead_data["mp"]);
    set_name(lower_case(undead_data["name"]));
    set_id(undead_data["ids"]);
    set_body_type(undead_data["body type"]);
    set_hp(query_max_hp());
    set_mp(query_max_mp());
    set_property("charge", 5*query_level());
    if(time() - undead_data["last load"] > 8*HOUR)
	reduce_spells();
    undead_data["last load"] = time();
}

void copy_body(object ob){
    string *shrt;
    body_copied = 1;
    pet_skills = ob->query_skills();
    pet_spells = ob->query_spells();
    undead_data["level"] = ob->query_level();
    undead_data["short"] = ob->query_old_short();
    undead_data["long"] = ob->query_old_long();
    undead_data["hp"] = ob->query_old_hp();
    undead_data["mp"] = ob->query_old_mp();
    undead_data["race"] = ob->query_race();
    undead_data["ids"] = ob->query_old_ids() + ({ "undead" });
    undead_data["name"] = ob->query_old_name();
    undead_data["body type"] = ob->query_body_type();
    undead_data["is player"] = ob->is_player();

    shrt = explode(undead_data["short"], " ");
    if( lower_case(shrt[0]) == "a" || lower_case(shrt[0]) == "an")
	shrt = exclude_array(shrt, 0);
    undead_data["short"] = implode(shrt, " ");

}

