//  Wizard:   Myrddin
//  Monster:  Father
//  File:         father.c
//  June 97

inherit "/std/monster";

create() {
  object money;
  ::create();
    set_name("father");
    set_id( ({ "father","man"}) );
    set_level(1);
    set_short("father");
    set_long("The man encourages his family to keep moving quickly."
        "His face shows he is torn between their current poor state and "
        "the desire to keep moving as quickly as possible."
      );
    set("race", "human");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 5]));
    set_skill("melee", 10);
    set_skill("dodge", 5);
    set_skill("parry", 5);
    set_stats("dexterity", 30);
    set_stats("intelligence", 50);
    set_stats("strength",30);
    set("gang bang",1);
    set_wimpy(0);
    new("d/damned/virtual/leather-vest.armour")->
                 move(this_object());
             force_me("wear vest");
    new("d/damned/virtual/leather-pants.armour")->
                 move(this_object());
             force_me("wear pants");
    money=new("std/obj/coins");
    money->set_money("silver",(random(20)+5));
    money->move(this_object());
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_emotes(3, ({
	  "The man rubs his eyes tiredly, then continues walking. ",
	  "The father looks back to make sure no one is being left "
                "behind.",
	  "The man watches the surrounding forest suspiciously. ",
	}),0);
	set_speech(3,"common",({ 
	  "Keep up everyone, don't fall behind.",
	  "Don't worry, we are far away from any danger now.",
	  "I am sure everyone who stayed will be ok.",
	  "We will just rebuild outside Akkad, where it is safer.",
	}),0);
	set_speech(1,"common",({ 
	  "Not the children!",
	}),1);
}

