//  Wizard:   Myrddin
//  Monster: Insectoid Worker
//  File:        insectoid_w01.c
//  June 97

inherit "/std/monster";

create() {
  int    zlevel,zskill;
  ::create();
    set_name("insectoid worker");
    set_id( ({ "insectoid worker", "insectoid", "worker" }) );
    zlevel=random(2)+2;
    zskill=zlevel*6;
    set_level(zlevel);
    set_short("insectoid worker");
    set_long("The insectoid worker busily move about, performing his "
                  "duties.");
    set("race", "insectoid");
    set_gender("neuter");
    set_body_type("thranx");
    set_wielding_limbs( ({ "first hand", "second hand", "third hand",
                                        "fourth hand" }) );
    set_property("melee damage", ([ "crushing" : (zskill+10)]));
    set_overall_ac(15);
    set_skill("melee", (zskill+10));
    set_skill("dodge", zskill);
    set_skill("parry", zskill);
    set_skill("attack", (zskill+10));
    set_skill("offhand training",200);
    set_skill("dual attack",100);
    set_skill("perception",50);
    set_stats("dexterity", zskill);
    set_stats("intelligence", 50);
    set_stats("strength", (zskill+20));
    set_wimpy(0);
    set_alignment(100);
    set_emotes(5, ({
  "The insectoid fights in complete silence.",
}),1);
}



