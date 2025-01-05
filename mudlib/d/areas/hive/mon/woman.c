//  Wizard:   Myrddin
//  Monster:  Woman
//  File:        woman.c
//  June 97

inherit "/std/monster";

create() {
  object money;
  ::create();
    set_name("woman");
    set_id( ({ "woman","lady"}) );
    set_level(1);
    set_short("woman");
    set_long("The woman looks lost, lonely, and effectively alone." 
      );
    set("race", "human");
    set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 3]));
    set_skill("melee", 5);
    set_skill("dodge", 5);
    set_stats("dexterity", 20);
    set_stats("intelligence", 20);
    set_stats("strength",20);
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
    set_emotes(2, ({
	  "The woman pretends she is confident about this journey.",
	  "The woman helps keep watch over the children.",
	  "The mumbles to herself.",
               }),0);
	 set_speech(2,"common",({ 
	  "Yes, this journey really is for the best.",
	  "Did you see what they did to the village walls?.",
	  "I heard the farmers we going to try fighting back.",
	  "Maybe I should have gone to the farms.  It should be "
               "safe enough there.",
	}),0);
	set_speech(1,"common",({ 
               "Not the children!",
	}),1);
}

