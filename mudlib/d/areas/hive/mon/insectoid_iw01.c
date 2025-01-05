//  Wizard:   Myrddin
//  Monster: Injured Worker
//  File:        insectoid_iw01.c
//  June 97

inherit "/std/monster";

create() {
  int    zlevel,zskill;
  ::create();
    set_name("injured worker");
    set_id( ({ "injured worker", "insectoid", "worker" }) );
    zlevel=random(2)+2;
    zskill=zlevel*6;
    set_level(zlevel);
    set_short("insectoid worker");
    set_long("The insectoid worker sits quietly, waiting for his "
                  "wounds to heal.  He is the first insectoid you have seen "
                  "not moving about continuously.");
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
    set_hp(25);
    set_wimpy(0);
    set_alignment(100);
    set_emotes(5, ({
  "The insectoid fights in complete silence.",
}),1);
}



