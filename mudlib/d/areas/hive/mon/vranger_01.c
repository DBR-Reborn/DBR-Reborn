//  Wizard:   Myrddin
//  Monster: Veteran Ranger
//  File:        vranger.c
//  June 97

inherit "/std/monster";

create() {
  object money;
  int    zlevel,zskill;
  ::create();
    set_name("veteran ranger");
    set_id( ({ "veteran ranger","ranger", "man"}) );
    zlevel=random(3)+3;
    zskill=zlevel*10;
    set_level(zlevel);
    set_short("ranger");
    set_long("A veteran ranger, very experienced in his lore and well "
                  "trained in combat."
      );
    set("race", "human");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : zskill]));
    set_skill("melee", zskill);
    set_skill("attack", zskill);
    set_skill("dodge", zskill);
    set_skill("parry", zskill);
    set_skill("axe", zskill);
    set_skill("block", zskill);
    set_stats("dexterity", 40);
    set_stats("intelligence", 50);
    set_stats("strength",40);
    set_wimpy(0);
    set("gang bang",1);
    set_alignment(20);
    switch(random(2)){
      case 0:new("/d/damned/virtual/battle-axe_4.weapon")->
                 move(this_object());
             force_me("wield axe in right hand");
             break;
      case 1: new("d/damned/virtual/broad-sword_4.weapon")->
                 move(this_object());
             force_me("wield sword in right hand");
             break;
}
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
    money=new("std/obj/coins");
    money->set_money("silver",(random(20)+20));
    money->move(this_object());
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_emotes(1, ({
  "The veteran ranger watches you carefully.",
  "The veteran ranger seems to consider everyone and everything a "
  "danger."
}),0);
set_speech(2,"common",({ 
  "You picked the wrong place to start trouble!",
  "Time to end this fight!",
  "Curse you, brigand!",
}),1);
set_speech(1,"common",({ 
  "Let's not have any trouble with you.",
}),0);
}


