/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
int zlevel;
   ::create();
   set_name("guard");
   set("id", ({"guard", "guard", "guard"}) );
   set_level(10+random(3));
if (zlevel == 5) set_short("[5]guard");
else
if (zlevel == 6) set_short("[6]guard");
else 
if (zlevel == 7) set_short("[7]guard");
else
if (zlevel == 8) set_short("[8]guard");
else set("short", "[12]guard");
	set_level(zlevel);
   set("long",
   "This is one of the formidable guards of Daybreak Castle."
   " Heavily armored and afraid of nothing, the guard would give his life"
   " for this is his area, the Daybreak Castle.  He looks very strong and very"
   "dangerous."
   );
   set("race", "human");
   set_gender("male");
   set_alignment(-150);
   set_money("silver", random(250)+150);
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
                ({
                  "The guard eyes you warily.",
                  "The guard shifts his position.",
                  "The guard looks at you up and down.",
                  "The guard adjusts his shield.",
                  "The guard stands at attention.",
                }), 0);
   set_achats(30,
                ({
                  "The guard screams a battle cry!",
                  "The guard swings his mace wildly.",
                  "The guard grits his teeth in pain.",
                  "The guard foams at the mouth.",
                }) );
   //new(WEAP_PATH+"mace")->move(this_object());
   //new(ARMOR_PATH+"chainmal")->move(this_object());
   //new(ARMOR_PATH+"shield")->move(this_object());
   //new(ARMOR_PATH+"helmet")->move(this_object());
   //new(ARMOR_PATH+"boots")->move(this_object());
   force_me("wield mace in right hand");
   force_me("wear chainmail");
   force_me("wear shield on left hand");
   force_me("wear helmet");
   force_me("wear boots");
}
 
void catch_tell(string str) {
   string a, b;
   object ob1;
   if(sscanf(str, "%s attacks %s", a, b) == 2) {
      a = lower_case(a);
      ob1 = present(a, environment(this_object()));
      if(ob1) {
         if(interact("Kobold", b)) {
            ob1->add_follower(this_object());
            force_me("kill "+a);
            return;
         }
      }
   }   
}
 
