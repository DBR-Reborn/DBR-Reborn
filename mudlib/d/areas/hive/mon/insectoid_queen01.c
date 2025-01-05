//  Wizard:   Myrddin
//  Monster: Insectoid Queen 1
//  File:        insectoid_queen01.c
//  June 97

inherit "/std/monster";

create() {
  ::create();
    set_name("insectoid queen");
    set_id( ({ "insectoid queen", "insectoid", "queen" }) );
    set_level(10);
    set_short("insectoid queen");
    set_long("The insectoid stands before you in her impressive "
                  "majesty.  Unlike the queen of an ant colony, she appears "
                  "to be the most capable fighter of her hive.   Her "
                  "appearance is very similar to here guards, except that "
                  "she is twice as large.  You admire her, for she is "
                  "beautiful in her own way.  You notice her watching you "
                  "back you think you detect real intelligence in her.");
    set("race", "insectoid");
    set_gender("female");
    set_body_type("thranx");
    set_wielding_limbs( ({ "first hand", "second hand", "third hand",
                                        "fourth hand" }) );
    set_property("melee damage", ([ "crushing" : 140]));
    set_overall_ac(50);
    set_skill("melee", 100);
    set_skill("dodge", 75);
    set_skill("parry", 100);
    set_skill("attack", 100);
    set_skill("combo",50);
    set_skill("offhand training",200);
    set_skill("dual attack",100);
    set_skill("perception",100);
    set_stats("dexterity", 100);
    set_stats("intelligence", 80);
    set_stats("strength", 100);
    set("aggressive", 1);
    set_wimpy(0);
    set_alignment(100);
    set_emotes(5, ({
  "The queen fights in complete silence.",
}),1);
}



