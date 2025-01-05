//        Wizard:   Myrddin
//        Monster:  Old Man
//        File:     oldman.c
//        June 97

inherit "/std/monster";

create() {
::create();
    set_name("old man");
    set_id( ({ "man", "human", "old man"}) );
    set_level(1);
    set_short("old man");
    set_long("The old man sits on his bed, staring toward the door as "
                  "if expecting trouble." 
      );
    set("race", "human");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_property("melee damage", ([ "crushing" : 2]));
    set_skill("melee", 4);
    set_skill("dodge", 4);
    set_skill("parry", 4);
    set_wimpy(0);
    set_max_hp(20);
    set_hp(20);
    set_alignment(50);
    set_languages(({ "common" }));
    set_lang_prof("common",10);
    set_emotes(1, ({
  "The old man looks toward the door with quiet determination.",
  "The old man looks into the distance, perhaps reliving old "
  "memories.",
  "The old man rummages through his meager belongings.",
}),0);
  set_speech(1,"common",({ 
  "Im to old to be going on a long trip, even for my own safety.",
  "I wont let them push me out of my house!",
  "I might as well stay, I dont have much longer to live anyway.",
  "I remember when this village was nothing but a log cabin in the "
  "wilderness.",
  }),0);
 
}





