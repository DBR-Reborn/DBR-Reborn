//  Wizard:   Myrddin
//  Monster: Injured Insectoid
//  File:        ininsectoid.c
//  June 97

inherit "/std/monster";

create() {
  int    zlevel,zskill;
  ::create();
    set_name("injured insectoid");
    set_id( ({ "insectoid" }) );
    zlevel=random(2)+3;
    zskill=zlevel*8;
    set_level(zlevel);
    set_short("injured insectoid");
    set_long("The wounded insectoid is trying to slowly crawl back to "
                   "the north." 
      );
    set("race", "insectoid");
    set_gender("neuter");
    set_body_type("thranx");
    set_wielding_limbs( ({ "first hand", "second hand", "third hand",
                                        "fourth hand" }) );
    set_property("melee damage", ([ "crushing" : zskill]));
    set_overall_ac(6);
    set_skill("melee", zskill);
    set_skill("dodge", zskill);
    set_skill("parry", zskill);
    set_skill("attack", (zskill+10));
    set_stats("dexterity", zskill);
    set_stats("intelligence", 50);
    set_stats("strength", (zskill+20));
    set_max_hp(250);
    set_hp(50);
    set_wimpy(0);
    set_alignment(100);
    set_emotes(5, ({
  "The insectoid twitches from the pain of his wounds.",
  "The insectoid weakly tries to crawl to the northwest.",
  "The insectoid seems to sense your presence for a moment, but then "
  "forgets you.",
}),0);
}



