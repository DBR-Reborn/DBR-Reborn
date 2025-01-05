#include <clock.h>
 
inherit "/std/skills/skill.c";
 
void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(35);
    set_fast_dev_cost(75);
    set_property("no target", 1);
}
 
void info() {
message("help",
"This allows the thief to prepare for combat by heightening his/her senses and preparing to tumble out of the way of attacks.  A successful tumbleing check will allow the thief to reduce the damage from attacks or even avoid damage altogether.",
this_player());
}
 
void skill_func(object from, object at, string arg) {
  object ob;
  int dodge_mod = 0;
  int skill;
  string he_she, his_her, He_She;
 
 
   skill = (int)from->query_skill("tumble");
   if((time() - (int)from->query_last_use("tumble")) < 3600/(skill/20))
    {
    message("info", "You are too tired to use this skill again yet.", from);
    remove();
    return;
   }   
   from->set_last_use("tumble");
   seteuid(geteuid(this_object()));
 
   if(from->query_gender() == "female") {
      he_she = "she";
      He_She = "She";
      his_her = "her";
   }
   else {
      he_she = "he";
      He_She = "He";
      his_her = "his";
   }
 
   message("info", "%^BOLD%^%^CYAN%^You prepare yourself to tumble away from attacks.", from);
 
message("info",from->query_cap_name()+" prepares "+his_her+"self to tumble away from attacks.", environment(from), ({ from }));
   dodge_mod = skill/5;
    
   ob = new("/std/spells/shadows/tumble_shad");
   ob->start_shadow(from, (5 + skill/5 + random(skill/3))*2, "%^YELLOW%^You find yourself unable to keep up your state of hightened readiness.");
   return;
}
