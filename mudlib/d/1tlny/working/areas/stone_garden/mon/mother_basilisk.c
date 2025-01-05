 // Wizard: Shade Maelstorm //
 
 // Monster File: Mother Basilisk //
#include <std.h>
#include <stone_garden.h>

inherit MONSTER;
 
void create() {
  object ob;
   ::create();
  set_name("Mother Basilisk");
   set_level(5+random(5));
set("id", ({"basilisk", "mother basilisk" }));
  set_money("silver", random(50));
   set("short", "A Mother basilisk");
   set("long",

   "A relatively young basilisk seems to be playing in the grass with some "
   "insects. You look at its form, so sleek and playful, its shiny chitinous "
   "black shell shimmering. "
   );
  set("race", "basilisk");
   set_overall_ac(30);
   set_gender("neuter");
   set_body_type("basilisk");

 set_emotes(5, ({
 "The large basilisk growls several low gutteral sounds, warning you away. ",
 "The eyes of the basilisk light up bright red, showing its hatred toward you. " ,
   }), 0);

 
}
 
void die(object ob) {
object ob1,ob2,ob3,ob4,ob5,ob6;
object *players;

  ob1 = new(MON_PATH+"alarm_guard");
  ob1 -> move(find_object_or_load(PATH + "temple2"));
  message("info","A temple guard stomps into the room.", environment(ob1));
  ob2 = new(MON_PATH+"alarm_guard");
  ob2 -> move(find_object_or_load(PATH + "temple2"));
  message("info",
          "You hear a horrible scream coming from within the temple. "
          "Alarm bells sound and you hear approaching footsteps", 
           environment(ob2));
  ob3 = new(MON_PATH+"angry_a_basilisk1");
  ob3 ->move(find_object_or_load(PATH + "temple6"));
  message("info",
          "Some basilisks were were hiding in the room and after hearing "
          "a scream, suddenly appear, uncontrollable fury in their "
          "eyes", environment(ob3));
  ob4 = new(MON_PATH+"angry_a_basilisk1");
  ob4 ->move(find_object_or_load(PATH + "temple6"));
  message("info",
          "Two basilisks appear from the corner of the room. Fury, like "
          "no other shows in their eyes, there one aim in life is but to "
          "kill you", environment());
  ob5 = new(MON_PATH+"angry_a_basilisk2");
  ob5 ->move(find_object_or_load(PATH + "temple9"));
  ob6 = new(MON_PATH+"angry_a_basilisk2");
  ob6 ->move(find_object_or_load(PATH + "temple9"));
 // tell_room(caretaker hut )
  tell_room(PATH + "temple9",
            "The basilisk gives out one last gutteral scream, which "
            "echos along the walls of the temple. You hear alarm bells "
            "in the far distance ");
 //tell all temple rooms. plus change tells for rooms in which monsters appear
  players = filter_array(users(), "check_location");
  message("info", "test message", players);
 ::die();
 }

int check_location(object ob)
{
string cur_room;
  cur_room = file_name(environment(ob));
  if(cur_room[0..(sizeof(PATH)-1)] == PATH)
    return 1;
  return 0;
}

