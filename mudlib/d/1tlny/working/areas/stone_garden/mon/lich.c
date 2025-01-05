/* Monster coded by Duridian for DarkeMud. */
 
#include <std.h>
#include <stone_garden.h>
inherit MONSTER;
 
void create() {
   object ob;

   ::create();
   set_name("lich");
   set("id", ({"lich", "evil lich", "lich_to_start_invasion"}) );
   set_level(40);
   set_property("enhance criticals",-5);
   set_max_hp(10000);
   set_hp(10000);
   set("short", "evil lich");
   set("long",
   "The horrible creature before you is the most feared of all undead, the "
   "lich.  The living corpses of powerful wizards, liches retain their "
   "magical skills they acquired during their mortal lives.  This particular "
   "lich is clothed in fancy garments that are torn and rotted.  Every once "
   "in a while he laughs a loud, evil laugh that echoes in the dungeons.",
   );
   set("race", "lich");
   set_gender("male");
   set_money("mithril", 100+(random(25)));
   set_body_type("human");
}
 
void catch_tell(string str) {
   string a, b;
 object tp, ob, bas, pet_bas;
   int flag;
 bas=this_object();

   flag = 0;
   if(sscanf(str, "%s soul%s", a, b) == 2)
      flag = 1;
   if(sscanf(str, "%s rufus%s", a, b) == 2)
      flag = 1;
   if(sscanf(str, "%s Rufus%s", a, b) == 2)
      flag = 1;
   if(flag == 1) {
      message("info", 
"\nThe lich speaks in a deep, booming voice.  \"Rufus, that fool.  He dared\n"+
"to cross me, so I stole his greatest possession - his soul.  Bring me\n"+
"the Elixir of Youth and I will restore his life.\"\n",
                environment(this_object()), this_object());
      flag = 0;
   }
 
   if(sscanf(str, "%s gives you %s", a, b) == 2) {

      a = lower_case(a);
      tp = present(a, environment(this_object()));
      if(!tp) return;
      ob = present("rose", this_object());
      if(ob) {
         message("info", 
 "\nThe basilisk eats the rose greedily. Its eyes change color from red to\n"+
 "a lighter yellow color. It seems to like you, or at least those roses.\n",
                environment(this_object()), this_object());
  ob->remove();
pet_bas=new(MON_PATH+"pet_basilisk")->move(environment(this_object()));
 pet_bas->set_owner(tp);
 pet_bas->set_up(random(6));
 pet_bas->set_dur(120);
         message("info", 
"The undead creature continues: \"Now leave my sight before I decide to\n"+
"crush you like the scrawny insect you are!  Begone!\"\n",
                environment(this_object()), this_object());
 bas->remove();
      }
   }

}
