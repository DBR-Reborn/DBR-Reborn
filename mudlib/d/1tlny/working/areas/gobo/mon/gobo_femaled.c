  //Area: Gobos
  //Mon:  Female gobo diseased
  //Creators: Amel & Arctic

#include <std.h>

  inherit MONSTER;

  string random_short();
object money;
  int rand_money;

  void create()
  {
  string rand_short;
    ::create();
    rand_short = random_short();
    rand_money = random(20) +10;
    set_name("gobo female");
    set("id", ({"gobo_female","gobo female","gobo","female","goblin"}));
    set_level(1);
    set("short", rand_short);
    set("long","A female gobo some four feet in height goes about takeing care"
        " of the children and males who need attention.");
    set("race","goblin");
    set_gender("female");
    set_body_type("human");
    set_overall_ac(6);
    set_wielding_limbs(({"right hand","left hand"}));
    set("gang bang", 0);
  set_lang_prof("goblinish",10);
    set_speech(35, "goblinish", ({"Don't hurt me please..",
                                  "I'll do anything you want.. ",}), 0);
    money = new("/std/obj/coins");
    money -> set_money("silver", rand_money);
    money -> move(this_object());
 set_melee_damage((["crushing":5]));
    set_hp(40);
    set("aggressive", 0);
    set_skill("melee", 10);
    set_skill("attack",10);
    set_skill("dodge", 5);
    set_skill("parry", 5);
    set_body_type("humanoid");
    set_emotes(20, ({"The female gobo moves about scrounging",
                 "The female gobo glances at you and quickly looks away",
                 "The female gobo cowers in the corner.."})
  ,1);
  }

  string random_short()
  {
  int i;
    i = random(10);
    switch(i)
    {
    case 0 : return "An young female gobo";
    case 1 : return "A pudgy female gobo";
    case 2 : return "A dirty female gobo";
    case 3 : return "A thin female gobo";
    case 4 : return "A fat female gobo";
    case 5 : return "A tall female gobo";
    case 6 : return "A fat female gobo";
    case 7 : return "A toothless female gobo";
    case 8 : return "A ugly female gobo";
    case 9 : return "A naked female gobo";
    }
  }
