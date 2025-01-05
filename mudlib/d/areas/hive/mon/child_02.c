//        Wizard:   Myrddin
//        Monster:  Child
//        File:     child_02.c
//        June 97

inherit "/std/monster";

create() {
::create();
    set_name("child");
    set_id( ({ "child"}) );
    set_level(1);
    set_short("child");
    set_long("The child tries to act brave, but looks fearfully back up "
                   "the path." 
      );
    set("race", "human");
    set_gender("male");
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
  "The child cries quietly",
  "The child watches the forest nearby with distrust.",
  "The child sighs and tries to look brave.",
}),0);
  set_speech(1,"common",({ 
  "I want to go home.",
  "When will we be there?",
  "My daddy will save us.",
  "I never did like ants.",
  }),0);
  set_speech(1,"common",({ 
  "Aaiieee!!!  Mommy!!! Daddy!!!  Help!!!!",
  }),1);
}





