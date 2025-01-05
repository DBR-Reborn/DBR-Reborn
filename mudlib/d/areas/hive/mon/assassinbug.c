//  Wizard:   Myrddin
//  Monster:  Mayor
//  File:         assassinbug.c
//  June 97

#include "../defs.h"

inherit "/std/monster";

create() {
  object money;
  ::create();
    set_name("Assassin Bug");
    set_id( ({ "assassin bug","bug" }) );
    set_level(25);
    set_short("Assassin Bug");
    set_long("Behind you, the shadows move.  In the light, you can "
                  "only see the blurring of an outline, an insectoid creature "
                  "of great speed and power, of lethal force." );
    set("race", "insect");
    set_gender("neuter");
    set_body_type("thranx");
    set_wielding_limbs( ({ "first hand", "second hand", "third hand", "fourth hand" }) );
    set_property("melee damage", ([ "crushing" : 100]));
    set_overall_ac(80);
    set_skill("melee", 50);
    set_skill("dodge", 125);
    set_skill("parry", 125);
    set_skill("attack", 150);
    set_skill("knife",150);
    set_skill("whirlwind strike",100);
    set_skill("offhand training",200);
    set_skill("dual attack",100);
    set_skill("assassination",100);
    set_skill("perception",100);
    set_skill("chaos magic",150);
    set_skill("illusionism",150);
    set_skill("concentrate",100);
    set("concentrate", 1);
    set_stats("dexterity", 130);
    set_stats("intelligence", 120);
    set_stats("strength",100);
    set_casting_chance(100);
    add_spell("perm_invis", "$(ME)");
    set_spell_level("perm_invis", 6);
    set("gang bang",1);
    set_wimpy(0);
    set_property("magic resistance", 50);
    force_me("cast *6 perm_invis at assassin bug");
    new("/d/damned/virtual/dagger_6.weapon")->
                 move(this_object());
             force_me("wield dagger in first hand");
    new("/d/damned/virtual/dagger_6.weapon")->
                 move(this_object());
             force_me("wield dagger in second hand");
    new("/d/damned/virtual/dagger_6.weapon")->
                 move(this_object());
             force_me("wield dagger in third hand");
    new("/d/damned/virtual/dagger_6.weapon")->
                 move(this_object());
             force_me("wield dagger in fourth hand");
    money=new("std/obj/coins");
    money->set_money("mithril",(random(50)+50));
    money->move(this_object());
    set_emotes(5, ({
    "You hear something behind you.",
}),1);

}



