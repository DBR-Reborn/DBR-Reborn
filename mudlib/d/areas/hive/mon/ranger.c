//  Wizard:   Myrddin
//  Monster: Ranger
//  File:        ranger.c
//  June 97

inherit "/std/monster";

create() {
  object money;
  int    zlevel,zskill;
  ::create();
    set_name("ranger");
    set_id( ({ "ranger", "man"}) );
    zlevel=random(2)+2;
    zskill=zlevel*8;
    set_level(zlevel);
    set_short("ranger");
    set_long("A ranger, recently arrived from the forest to aid in the "
                  "defense of the village."
);
    set("race", "human");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : zskill]));
    set_skill("melee", zskill);
    set_skill("attack", zskill);
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
    new("/d/damned/virtual/large-shield.armour")->
                 move(this_object());
             force_me("wear shield on left hand");
    money=new("std/obj/coins");
    money->set_money("silver",(random(20)+20));
    money->move(this_object());
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_emotes(1, ({
  "The ranger keeps a close watch for any danger.",
  "The ranger watches you closely.",
  "The ranger looks carefully at his surroundings."
}),0);
set_speech(2,"common",({ 
  "Can't you find better things to fight?",
  "So, you just have to be a troublemaker!",
  "As if the village doesn't already have enough trouble!.",
}),1);
}


