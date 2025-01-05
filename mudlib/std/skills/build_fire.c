#include <clock.h>
 
inherit "/std/skills/skill.c";

int skill;

object ob;

void create() {
    ::create();
    set_stat("wisdom");
    set_dev_cost(8);
    set_fast_dev_cost(17);
    set_property("no target", 1);
}
 
void info() {
message("help", 
"Shamen, being the nature-lovers they are, spend lots of time in the wilderness. Therefore, they are able to build camp fires which they can use to cook food, make light, and send smoke signals.",
this_player());
}
 
void skill_func(object from, object at, string arg) {
  int time;

if(present("campfire", environment(from))) {
   message("info", "You may only build one campfire per room.", from);
return 0;
}

   skill = (int)from->query_skill("build fire");

   seteuid(geteuid(this_object()));
  
   message("info", "You begin building a camp fire to keep warm.", from);

time = 180-skill;

if(time<60) {
time=60;
}

   call_out("make_fire", time, from);

  ob=new("/std/tailwind/obj/campfire");
  ob->set_length(skill*5);
  ob->move(environment(from));
   return;
}

void make_fire(object from) {

  message("info", "%^CYAN%^%^BOLD%^You build your camp fire, and feel warmed by it!", from);
  message("info", "%^CYAN%^You feel warmed by "+(string)from->query_cap_name() +"'s new camp fire .",
      environment(from), ({ from }));
ob->set_short("A campfire");


  remove();
  return;
}
