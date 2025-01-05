/* Monster coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
  set_name("lost donkey");
   set_level(1);
  set("id", ({"donkey", "lost donkey"}) );
  set("short", "lost donkey");
   set("long",
  "The donkey hee's and haw's, hoping his master will someday find him. "
 "He looks quite famished. "
   );
  set("race", "donkey");
  set_max_hp(300);
    set_exp(10);
   set_hp(300);
   set_body_type("equine");
  set_gender("male");
   set_alignment(0);
   set_emotes(5,
                ({
       "The donkey stomps a hoof.",
        "The donkey nudges you.",
          "The donkey tries to eat your pants!",
                }), 0);
   set_achats(30,
                ({
         "The donkey haws in pain!",
      "The donkey foams at the mouth.",
                }) );
}
