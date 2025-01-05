//      Wizard:  Gellor
//      City Guard 2
//      city_guard2.c
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
   set_level(35);
   set_body_type("human");
   set_alignment(20);
   set("race", "elf");
   set_gender("male");
   set_stats("strength", 120);
   set_stats("dexterity", 130);
   set_stats("constitution", 120);
   set_stats("wisdom", 80);
   set_stats("intelligence", 70);
   set_stats("charisma", 120);
   set_skill("reverse stroke", 80);
   set_property("magic resistance", 40);
   set_skill("perception", 95);
   set_skill("resist stun", 50);
   
   set_emotes(5, ({"The guard glances off towards the forest.",
                   "The guard scratches his face.",
                   "The guard coughs loudly.",
                   "The guard looks you over."}),0 );
   set_languages( ({"elvish"}) );
   set_speech(3, "elvish", ({"Keep moving!","Move along!",
			     					  "Welcome to New Firn'Ville, "
                             "keep moving!"}),0 );
   set_moving(3);
   set_speed(60);
}
