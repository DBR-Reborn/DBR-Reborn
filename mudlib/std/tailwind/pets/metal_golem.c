inherit "/std/pet";

int g_skill = 1;
int g_power = 1;

void   setup_golem();

void create() {
    ::create();
    set_name("golem");
    set_id(({ "metal golem", "golem" }));
    set("race", "human");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_save(1);
    set_level(30);
    set_short("metal golem");
    set_long("This is a metal golem. He looks like a tough customer.");
    set_max_hp(260);
    set_learning_spells(1);
    set_bodyguard(1);
    set_intelligent(1);
    set_hp(260);
    set_skill("melee", 250);
    set_skill("attack", 250);
    set_skill("dodge", 140);
    set_skill("parry", 180);
    set_stats("strength", 105);
    set_aggr_status(0);
    setup_golem();
    return;
}

string query_short() {
    return capitalize(article(query_property("material_name") + " golem"));
}

void setup_golem(){
    force_me("say ready to serve");
    set_level(20 + g_power  + g_skill / 10);
    set_max_hp(1200 + g_skill * 45 );
    set_hp(1200 + g_skill * 45);

    set_max_mp(1000 + g_power * 45 );
    set_mp(1000 + g_power * 45);

    set_property("enhance criticals", -1*(g_skill/25));
    set_overall_ac(4*g_skill);

    set_skill("melee", 120 + g_skill *3);
    set_skill("attack",70 + g_skill *3);
    set_skill("dodge", 160 + g_skill);
    set_skill("parry", 140 + g_skill);

    set_aggr_status(0);
}

void set_power(int power){
    g_power = power;
}

void set_create_skill(int skill){
    g_skill = skill;
}

void set_owner(string who) {
    object ob;

    ob = find_player(who);
    if(!ob) {
	::set_owner(who);
	return;
    }
    set_languages(({ "undead-tongue", "common", "elvish", "dwarvish",
	"serra", "yin", "treefolk",
	(string)ob->query_primary_lang() }) );
    ::set_owner(who);
    return;
}

void set_dur(int dur) {
    call_out("remove_servant", dur);
    return;
}

void remove_servant() {
    this_object()->force_me("drop all");
    message("info", "A metal golem crumbles to dust.",
      environment());
    remove();
    return;
}


