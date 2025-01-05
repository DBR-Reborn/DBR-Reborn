//  Wizard:   Myrddin
//  Monster:  Mayor
//  File:         mayor.c
//  June 97

#include "../defs.h"

inherit "/std/monster";

create() {
  object money;
  ::create();
    set_name("Mayor");
    set_id( ({ "mayor","man" }) );
    set_level(5);
    set_short("mayor");
    set_long("The Mayor of the village looks as tough as an old root "
                   "and very dangerous in combat." 
      );
    set("race", "human");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    set_property("melee damage", ([ "crushing" : 40]));
    set_overall_ac(6);
    set_skill("melee", 50);
    set_skill("dodge", 50);
    set_skill("parry", 50);
    set_skill("attack", 50);
    set_skill("blade",60);
    set_skill("block",60);
    set_stats("dexterity", 70);
    set_stats("intelligence", 75);
    set_stats("strength",100);
    set("gang bang",1);
    set_wimpy(0);
    set_alignment(300);
    new(HIV_OBJ+"bsword")->
                 move(this_object());
             force_me("wield sword in right hand");
    new("d/damned/virtual/chain-mail.armour")->
                 move(this_object());
             force_me("wear chain mail");
    new("d/damned/virtual/studded-leather-pants.armour")->
                 move(this_object());
             force_me("wear pants");
    new("/d/damned/virtual/cloak.armour")->
                 move(this_object());
             force_me("wear cloak");
    new("/d/damned/virtual/large-shield.armour")->
                 move(this_object());
             force_me("wear shield on left hand");
    new("/d/damned/virtual/great-helm.armour")->
                 move(this_object());
             force_me("wear helm");
    money=new("std/obj/coins");
    money->set_money("silver",(random(50)+50));
    money->move(this_object());
    set_emotes(2, ({
    "The Mayor looks around worridly.",
    "The Mayor looks at the farmers, but returns to his work",
}),1);
    set_speech(5,"common",({ 
    "We need someone to scout to the north, to assess the real "
    "situation.",
    "There may be another attack, be ready at all times.",
    "Has ANYONE seen any sign of giant insects in the past?",
    "Send a ranger to Akkad to petition for aid.  Perhaps some heroes "
    "will be willing to come to our aid.",
    "If they come again, hit them with overwhelming force, we lost "
    "too many people in that first surprise attack.",
    "Make sure the village is completely evacuated, except those able "
    "to fight.",
    "Maybe we should put a guard over the villages hidden storehouse."
}),0);
    set_speech(2,"common",({ 
    "Boys, take care of him!",
}),1);
}



