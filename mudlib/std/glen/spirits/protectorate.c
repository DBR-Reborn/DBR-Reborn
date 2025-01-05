
inherit "/std/glen/spirits/base_spirit";

#define TP this_player()
#define TPQL this_player()->query_level()

void create() {
    ::create();
    set_name("protector");
    set_id(({ "protectorate", "protector", "spirit", "bodyguard" }));
    set("race", "undead");
    set_body_type("human");
    set_attack(0);
    set_carry(0);
    set_save(0);
    set_level(1);
    set_bodyguard(1);
    set_short("ethereal bodyguard");
    set_long("This sleek little spirit watches over its owner.");
    set_aggr_status(0);
    return;
}

void set_up(int pow) {
    set_level(pow);
    set_property("enhance criticals",
      query_property("enhance criticals") * 2);
    set_overall_ac(query_overall_ac() / 2);
    return;
}


