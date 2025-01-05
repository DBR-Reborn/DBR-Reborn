//  Wizard:   Myrddin
//  Monster:  Farmer
//  File:         farmer.c
//  June 97

inherit "/std/monster";

create() {
  object money;
  int    zlevel,zskill;
  ::create();
    set_name("farmer");
    set_id( ({ "farmer", "man"}) );
    zlevel=random(2)+2;
    zskill=zlevel*6;
    set_level(zlevel);
    set_short("farmer");
    set_long("A farmer, from the outlying farms, come to offer his aid "
                  "to the mayor of the village."
);
    set("race", "human");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "left hand", "right hand" }) );
    set_property("melee damage", ([ "crushing" : zskill]));
    set_skill("melee", zskill);
    set_skill("attack", zskill);
    set_skill("parry", zskill);
    set_skill("axe", zskill);
    set_stats("dexterity", 40);
    set_stats("intelligence", 50);
    set_stats("strength",40);
    set_wimpy(0);
    set("gang bang",1);
    set_alignment(20);
    new("/d/damned/virtual/quarter-staff_4.weapon")->
                 move(this_object());
             force_me("wield staff in right hand and left hand");
    new("d/damned/virtual/leather-vest.armour")->
                 move(this_object());
             force_me("wear vest");
    new("d/damned/virtual/leather-pants.armour")->
                 move(this_object());
             force_me("wear pants");
    money=new("std/obj/coins");
    money->set_money("silver",(random(10)+10));
    money->move(this_object());
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_emotes(1, ({
  "The farmer stands, patiently waiting.",
}),0);
set_speech(1,"common",({ 
  "This aint the kinda trouble we came to help with!",
}),1);
}


