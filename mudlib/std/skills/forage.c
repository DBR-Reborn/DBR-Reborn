#include <clock.h>
 
inherit "/std/skills/skill.c";

int skill, killchance;
string animal;

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(7);
    set_fast_dev_cost(15);
    set_property("no target", 1);
}
 
void info() {
message("help", 
"This skill enables a player to run into the wilderness and forage for food. You must have a campfire to cook your dead prey, but you can eat it raw if you so desire. One may only forage in the wilderness.",
this_player());
}
 
void skill_func(object from, object at, string arg) {
  int time;
  object ob = environment(from);

if(!ob->query_is_underworld() && !ob->query_is_overworld()) {
	message("info","You are not in the wilderness.", from);
        return;
    }

   skill = (int)from->query_skill("forage");

   seteuid(geteuid(this_object()));
  
   message("info", "You run out into the wilderness. You begin to search for a fuzzy little critter for lunch.", from);

time = 180-skill;
if(time<60) {
time=60;
}
   call_out("sneak_fuzzy_critter", time, from);
   return;
}

void set_animal() {
switch(random(7)){
case 0:
animal="rabbit";
break;
case 1:
animal="fox";
break;
case 2:
animal="possum";
break;
case 3:
animal="prarie chicken";
break;
case 4:
animal="wild pheasant";
break;
case 5:
animal="squirrel";
break;
case 6:
animal="chipmunk";
break;
case 7:
animal="small beaver";
break;
}
return;
}

void sneak_fuzzy_critter(object from) {
  object ob;

set_animal();

message("info", "After a while, you find a "+animal+" and stealthily approach it.", from);

killchance=random(200);
if(skill >= killchance) {
   call_out("kill_fuzzy_critter", 10, from);
   return;
}
if(skill < killchance) {
   call_out("miss_fuzzy_critter", 10, from);
   return;
}
   message("info", "The skill bugged out. Tell Tailwind.", from);
  return;
}

void kill_fuzzy_critter(object from) {
  object ob;
  message("info", "You jump on the "+animal+" and break its fuzzy little neck! MUAHAHA! You grab the carcass and return to camp.", from);


  ob = new("/std/food");
  ob->set_name("carcass");
  ob->set_id(({ "carcass", animal }) );
  ob->set_short("The carcass of "+ animal);
  ob->set_long("An animal carcass. Raw. Ick.");
  ob->set_my_mess("You eat a raw animal carcass. Savage!");
  ob->set_your_mess("eats an animal carcass.");
ob->set_strength(25);
  ob->move(from);
  remove();
  return;
}

void miss_fuzzy_critter(object from) {
  message("info", "You leap at the "+animal+" and fall on your face. The animal scampers off, laughing at you. You return to camp with empty hands.", from);
  remove();
  return;
}
