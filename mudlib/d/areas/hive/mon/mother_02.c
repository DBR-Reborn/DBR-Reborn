//  Wizard:   Myrddin
//  Monster:  Mother
//  File:        mother_02.c
//  June 97

inherit "/std/monster";

create() {
  object money;
  ::create();
    set_name("mother");
    set_id( ({ "mother","mom"}) );
    set_level(1);
    set_short("mother");
    set_long("The mother seems to be quite angry about being lost." 
      );
    set("race", "human");
    set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 3]));
    set_skill("melee", 5);
    set_skill("dodge", 5);
    set_stats("dexterity", 20);
    set_stats("intelligence", 50);
    set_stats("strength",30);
    set("gang bang",1);
    set_wimpy(0);
    new("d/damned/virtual/leather-jacket.armour")->
                 move(this_object());
             force_me("wear jacket");
    new("d/damned/virtual/cloth-pants.armour")->
                 move(this_object());
             force_me("wear pants");
    money=new("std/obj/coins");
    money->set_money("silver",(random(10)+5));
    money->move(this_object());
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_speech(10,"common",({ 
	  "I told you this would happen, but nooooo, you knew a "
                "shortcut!",
	  "I should have married the blacksmith!  Even he was "
                "smarter than you!",
	  "Following a tracker on a known trail was to easy for you, "
                "huh?  Good move, smart guy!",
	  "My mother warned me you would bring me to grief!",
	}),0);
    set_speech(1,"common",({ 
	  "Not the children!",
	}),1);
    set_emotes(3, ({
	  "The mother glares at everything in general.",
	  "The mother snaps a tree branch that gets in her way.",
	  "The mother mutters angrily under her breath.",
             }),0);
}

