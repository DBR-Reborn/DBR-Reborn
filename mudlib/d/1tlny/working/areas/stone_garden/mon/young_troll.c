 // Wizard: Shade Maelstorm //
 // Monster File: Young troll gardener wanna-be//
 
#include <std.h>
inherit MONSTER;
 

  varargs void say_this(string str, object whom);

void create() {
object swrd;
object jerkin;
   ::create();
  set_name("Troll Gardener");

  set("id", ({"gardener", "troll" }));
   set_level(5+random(5)+random(5));
set_skill("blunt", 75);
set_money("gold",  random(50)+30);
  set("short", "A Young Troll");
   set("long",
  "This is a young troll gardener, who is learning his gardening profession."
  "As usual an apprentice's first job is always to clean something, and this poor"
  " trolls job is to clean out the gardeners workshed."
   );
  set("race", "half-troll");
   set_overall_ac(30);
   set_gender("male");
 set_languages(({"common","troll"}));
set_lang_prof("troll",10);
   set_body_type("human");

 set_emotes(5, ({
  "The young troll shakes the dust off his cloth and continues cleaning.",
  "With great care, the young gardener troll stands all the shovels together upright.",
  "The young troll races around, thinking of what else he could clean.",
  "Looking up at high window, the young troll sighs and goes back to his cleaning.",
  "I'll never be able to clean that window, sigh, its too high. ",
   }), 0);
swrd = new("/d/damned/virtual/short-sword_4.weapon");
  swrd->set_material("misc/wood");
  swrd->set("short", "wooden sword");
  swrd->set("long", "This is a wooden sword, normally given to young children, so "
  " they do not poke their eyes out. ");
  swrd->move(this_object());
force_me("wield sword in right hand");

  jerkin = new("/d/damned/virtual/leather-vest.armour");
jerkin->move(this_object());
force_me("wear leather vest");
}
 
 
  void directed_message(object whom, string cmd) {
   string who, what, p1, p2
  
whom = (string)whom->query_cap_name();
  if(sscanf(cmd, "%scloth%s", p1, p2)==2) {
  say_this("Yes, its just an old dusty cloth, but its all i have, and it works, sortof.",whom);
}


varargs void say_this(string str, object whom) {
  string your_lang;

if(objectp(whom))
  your_lang=(string)whom->query_primary_lang();
  if(you_lang && stringp(your_lang) &&
  (int)this_object()->query_lang_prof(your_lang)
  >=8) force_me("speak "+your_lang);
  else force_me("speak common");
  force_me("say "+str);
  return;
 }

 void catch_tell(string str) {
  string lang;
 if(sscanf(str, "%*s says something in %s.",lang)==2 &&random(2)) {
  say_this("I dont understand "+lang+".");
 return;
  }
}
