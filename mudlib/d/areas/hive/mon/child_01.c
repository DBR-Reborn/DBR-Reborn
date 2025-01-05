//       Wizard:   Myrddin
//       Monster:  Child
//       File:     child_01.c
//       June 97

inherit "/std/monster";

create() {
::create();
    set_name("child");
    set_id( ({ "child"}) );
    set_level(1);
    set_short("child");
    set_long("The child looks fearfully at you, but looks with greater "
                  "fear back up the path." 
      );
    set("race", "human");
    set_gender("female");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 1]));
    set_skill("melee", 2);
    set_skill("dodge", 2);
    set_skill("parry", 2);
    set_wimpy(1);
    set_max_hp(10);
    set_hp(10);
    set_alignment(50);
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_emotes(1, ({
  "The child cringes pathetically.",
  "The child watches the forest nearby with distrust.",
  "The child whimpers in its misery.",
}),0);
  set_speech(1,"common",({ 
  "I want to go home.",
  "When will we be there?",
  "I think they are following us!",
  "There were monsters, coming from the forest!",
}),0);
  set_speech(1,"common",({ 
  "Aaiieee!!!  Mommy!!! Daddy!!!  Help!!!!",
  }),1);
}





