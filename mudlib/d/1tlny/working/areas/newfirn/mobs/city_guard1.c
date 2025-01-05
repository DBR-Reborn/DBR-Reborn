//      Wizard:  Gellor
//      City Guard 1
//      city_guard1.c
inherit "/std/monster";
void create() {
   object ob;
   ::create();
   set_name("guard");
   set("id", ({ "guard", "Guard", "City Guard", "city guard", "elf" }));
   set("short", "A Royal Elven Guard");
   set("long", "Standing proud at his post, this elf radiates with honour, "
     	       "pride, and confidence. From his facial features and general "
               "build it is obvious that he is pure elf, trained to be one "
               "of the finest soldiers of the Elven Army.");
   set("aggressive", 0);
   set_level(30);
   set_body_type("human");
   set_alignment(10);
   set("race", "elf");
   set_gender("male");
   set_stats("strength", 100);
   set_stats("dexterity", 120);
   set_stats("constitution", 100);
   set_stats("wisdom", 90);
   set_stats("intelligence", 90);
   set_stats("charisma", 100);
   set_skill("reverse stroke", 80);
   set_property("magic resistance", 40);
   set_skill("perception", 95);
   set_skill("resist stun", 50);
   set_emotes(5, ({"The guard shifts his weight from one foot to the "
		   			 "other.",
                   "The guard looks you over.",
                   "The guard kicks a stone around."}),0 );
   set_languages( ({"elvish"}) );
   set_speech(3, "elvish", ({"Keep moving!","Move along!",
   			     "Welcome to New Firn'Ville, "
                             "keep moving!"}),0 );
	set_moving(3);
   set_speed(60);
}
