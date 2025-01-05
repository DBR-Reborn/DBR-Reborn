//  Wizard:   Khojem
//  Monster:  Young Troll

#include <std.h>

inherit MONSTER;

varargs void say_this(string str, object whom);

create() {
  object money;
  int    zskill;
  ::create();
    set_name("Young Troll");
    set_id( ({ "troll","gardener", "young troll" }) );
    set_level(5);
    set_short("young troll");
  set_long("This is a young troll gardener, who is learning his gardening "+
  "profession. As usual, an apprentices first job is always to clean "+
  "something, and this poor troll's job is to clean out the gardeners "+
  "workshed."
      );
    set("race", "half-troll");
    set_gender("male");
    set_body_type("human");
    set_property("melee damage", ([ "crushing" : 5]));
    zskill=random(3)*10+40;
    set_skill("melee",zskill);
    set_skill("dodge",zskill);
    set_stats("intelligence", 120);
    set_stats("wisdom", 120);
    money=new("std/obj/coins");
    money->set_money("silver",random(zskill)+30);
    money->move(this_object());
    set_wimpy(0);
    set_alignment(350);
    set_languages(({"common", "troll" }));
    set_lang_prof("troll",10);
    set_emotes(2, ({
   "The young troll shakes the dust off his rag and continues cleaning.",
   "With great care, the young troll stands all of the shovels together upright.",
   "The young troll races around thinking of what else there is to clean.",
    "Looking up at the window, the troll sighs, 'Ill never reach that window, too high.'"
	}),0);
}

void directed_message(object whom, string cmd) {
  string who, what, p1, p2;

  who  = (string)whom->query_cap_name();
  if(sscanf(cmd,"%scloth%s",p1,p2) ==2){
      say_this("Yes, its just a small dusty cloth but it works sortof.",whom);
  }
  if(sscanf(cmd,"%sclean%s",p1,p2) == 2) {
      say_this("Clean, clean, spic and span, thats what they want as fast as I can.",whom);
  }
  if(sscanf(cmd,"%sneed help?%s",p1,p2) == 2) {
     say_this("Sure I could use some help, I would be very grateful "+
   "I have so much to clean but I still want to do some digging before nightfall.",whom);
    force_me("give cloth to "+whom->query_name());
  }
  return;
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

void catch_tell(string str) {
  string lang;

  if(sscanf(str, "%*s says something in %s.", lang) == 2 && random(2)) {
    say_this("I don't understand "+lang+".");
    return;
  }
}
