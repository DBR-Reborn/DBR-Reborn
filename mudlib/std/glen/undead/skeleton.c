inherit "/std/glen/undead/base_undead";

void create() {
    ::create();
    set_name("skeleton");
    set_id(({ "skeleton", "undead" }));
    set("race", "undead");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_save(1);
    set_level(1);
    set_bodyguard(1);
    set_short("Skeleton");
    set_long("The odd-looking undead creature ambles about "
      "clumsily.");
    set_aggr_status(0);
    return;
}
void set_up(int pow) {
    set_max_hp( pow * 8);
    set_hp( pow * 8);
    set_skill("melee", 20*pow);
    set_skill("dodge", 4*pow);
    set_skill("parry", 3*pow);
    set_overall_ac(0);
    set_property("melee damage", ([ "cutting" : 3 + (3 * pow) ]) );
return;
}

