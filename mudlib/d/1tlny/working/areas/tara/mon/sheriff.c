#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

inherit MONSTER;

void create() {
  ::create();
   set_name("sheriff");
   set_id( ({ "halfling sheriff", "halfling", "sheriff" }) );
   set_level(6);
   set_short("A halfling sheriff");
   set("long", @SHER
This is the halflings sheriff.  He attempts to keep law and
order in this town.  He is young for a halfling of his
status, and obviously a smart fellow.  He knows about almost
everything that goes on in his town, including the recent
theft of a golden pipe.  He might be willing to talk about it.
SHER
);
   set("race", "halfling");
   set_gender("male");
   set_skill("attack", 89);
    set_languages(({ "common" }));
   force_me("speak common");
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   new("/d/damned/virtual/hammer_4.weapon")->move(this_object());
   force_me("wield hammer in left hand");
   set_emotes(4,
    ({
     "The sheriff looks over some important papers.",
     "The sheriff nods to you.",
     "The sheriff checks on the jail.",
     "The sheriff mumbles about a golden pipe.",
    }), 0);
   set_speech(4,"common",({
     "Old Donny the rich feller lost a golden pipe.",
     "Stay out of trouble here, and you'll do just fine.",
     "If your interested, I can tell you about a lost "+
     "pipe, there is a reward out for it.",
     "I do my best to seek justice.",
   }),0);
}

varargs void say_this(string str, object whom) {
   string your_lang;
   if(objectp(whom))
    your_lang = (string)whom->query_primary_lang();
   if(your_lang && stringp(your_lang) &&
    (int)this_object()->query_lang_prof(your_lang)
     >= 8) force_me("speak "+your_lang);
   else force_me("speak common");
   force_me("say "+str);
  return;
}

void directed_message(object whom, string cmd) {
   string who, what, p1, p2;

   who = (string)whom->query_cap_name();
   if((sscanf(cmd, "%suest%s", p1, p2) == 2) ||
     (sscanf(cmd, "%sgolden pipe%s",p1, p2) == 2)){
     tell_room(environment(this_object()),
"The sheriff smiles and begins speaking: \n"+
"About six months ago, Donny, a very wealthy halfling, had "+
"a pipe made of gold.  This pipe signified his wealth and "+
"position in the town.  He was very proud of his pipe, showing "+
"it off to all of his guests and friends.  Word quickly spread "+
"threw the town about his extremely expensive pipe. \n"+
"   One day, Donny came home from managing his business's, "+
"and found his pipe missing!  After the initial shock, he came to "+
"me, begging that I track down the thief, and find his pipe. "+
"I worked long and hard to find his pipe, but unfortunately, "+
"I never got any leads, whoever did it must have been an "+
"expert burglar.  Eventually more important things came up, and "+
"I had to hault me investigation.  Since then, Donny has been "+
"offering handsome rewards to whoever finds his pipe. \n"+
"   Donny lives in the rich district, his house has a door "+
"with a pipe carved into it.  Maybe he can provide more information "+
"on this matter.\n", ({ this_object() }));
     return;
   }
}

void catch_tell(string str) {

  string lang;
  
  if(sscanf(str, "%*s says something in %s.", lang) == 2) {
    say_this("I don't understand "+lang+".  Please speak in common.");
    return;
  }
}
