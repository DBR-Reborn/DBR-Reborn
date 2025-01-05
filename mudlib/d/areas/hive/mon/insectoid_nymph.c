//       Wizard:   Myrddin
//       Monster:  insectoid nymph
//       File:         insectoid_nymph.c
//       June 97

inherit "/std/monster";

create() {
::create();
    set_name("insectoid nymph");
    set_id( ({ "insectoid nymph", "insectoid", "nymph" }) );
    set_level(1);
    set_short("insectoid nymph");
    set_long("The insectoid nymph, the youngest form of insectoid "
                  "after hatching from an egg, stands motionless.  Pretty "
                  "soon it will begin rapidly growing, but until then it is "
                  "pretty much helpless.");
    set("race", "insectoid");
    set_gender("neuter");
    set_body_type("thranx");
    set_wielding_limbs( ({ "first hand", "second hand", "third hand",
                                        "fourth hand" }) );
    
    set_property("melee damage", ([ "crushing" : 1]));
    set_skill("melee", 2);
    set_wimpy(1);
    set_max_hp(10);
    set_hp(10);
}





