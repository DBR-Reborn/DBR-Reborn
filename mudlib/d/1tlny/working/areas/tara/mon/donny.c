#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

inherit MONSTER;

void create() {
  ::create();
   set_name("donny");
   set_id( ({ "donny", "halfling" }) );
   set_level(6);
   set_short("Donny the depressed halfling");
   set("long", @DONNY
Donny holds his head in his hands.  He hasnt been the same
since his golden pipe was stolen from him, it was by far the most
precious thing he has ever owned.  He has been slacking
off on managing his business's lately because of his depression.
DONNY
);
   set("race", "halfling");
   set_body_type("human");
   set_gender("male");
   add_money("gold", 50);
   set_property("melee damage", ([ "crushing" : 7]));
   set_languages(({ "common" }));
   force_me("speak common");
   set_emotes(3, ({
     "Donny drinks down a shot of tequila.",
     "Donny shakes his head and sighs.",
     "Donny looks at you, a faint glimmer of hope showing "+
     "in his eyes",
   }), 0);
   set_speech(5,"common",({
     "Please bring me my pipe!  I will reward you greatly!",
     "If you are interested in earning a reward, ask "+
     "me about my golden pipe.",
     "Who would do such a thing to me?",
     "Why me?  Why not someone else?  I did nothing to "+
     "deserve being stolen from!",
     "The sheriff tried his hardest, but could not find my "+
     "golden pipe."
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

  who  = (string)whom->query_cap_name();
  if((sscanf(cmd, "%suest%s", p1, p2) == 2) ||
    (sscanf(cmd, "%sgolden pipe%s",p1, p2) == 2)){
    tell_room(environment(this_object()),
"Donny gets ahold of himself, and begins telling you what he knows: \n"+
"I am a collector of fine goods, and also the owner of a pipe "+
"shop here in town.  One day I decided to have a golden pipe "+
"made for me, so I went ahead and did it, although it cost me more "+
"then most people in this town have ever seen!  Anyways, this pipe "+
"became my pride and joy, there was none who were not impressed "+
"by it.  Then one day, I came home and it was gone from it's "+
"locked safe!  It wasnt any ordinary thief, it must have been "+
"one skills with stealth, and picking locks.  No doubt it was "+
"someone from the other side of town, where the poor scrubs "+
"live in there filthy houses. \n"+
"   I offer you a handsome reward for the return of this pipe, "+
"and I will ask no questions about how you came upon it, or who "+
"stole it.  I just want it back!   Please help me, I am nothing "+
"without this pipe... \n", ({ this_object() }));
   return;
   }
}

void catch_tell(string str) {
 
  string a, b, lang;
  object tp, ob;
  
  if(sscanf(str, "%*s says something in %s.", lang) == 2) {
    say_this("I don't understand "+lang+".  Speak in common.");
    return;
  }
  if(sscanf(str, "%s gives you %s", a, b) == 2) {
    a = lower_case(a);
    tp = present(a, environment(this_object()));
    if(!tp) return;
    ob = present("golden_pipe_quest_object", this_object());
    if(!ob) {
      tell_object(tp, "I want my golden pipe, not this piece of crap.\n");
      return;
   }
   ob->remove();
   if(!tp->set_quest("golden pipe")) {
     tell_object(tp,"Donny says: You already gave me my pipe, is this a fake?\n"+
       "Sheriff!\n"); 
     return; 
   }
   tell_object(tp, "Donny says: My pipe!  Wow!\n"+
     "The halfling thanks you heartily.\n");
   tell_object(tp, "Donny gives you 250 mithril for your work.\n");
   tell_object(tp, "You gain 1000 experience points.\n");
   tp->add_money("mithril", 200);
   tp->add_exp(1000);    
   return;
  }
}
