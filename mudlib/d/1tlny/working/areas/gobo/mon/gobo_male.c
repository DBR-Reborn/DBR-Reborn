  //Area: Gobos
  //Mon:  Male gobo
  //Creators: Amel & Arctic

#include <std.h>

  inherit MONSTER;

  string random_short();
  int rand_money;

  void create()
  {
  object money;
  string rand_short;
    ::create();
    rand_short = random_short();
    rand_money = random(30) +15;
    set_name("gobo male");
    set("id", ({"gobo_male","gobo male","gobo","male","goblin"}));
    set_level(1);
    set("short", rand_short);
    set("long","A male gobo standing some four feet tall, with green"
               " skin, yellow eyes, and mangled pointy teeth.  Though"
               " small he looks to have mean streak.");
    set("race","goblin");
    set_gender("male");
  set_body_type("human");
    set_overall_ac(6);
    set_wielding_limbs(({"right hand","left hand"}));
    set("gang bang", 0);
 set_lang_prof("goblinish", 10);
set_speech(15, "goblinish", ({"Get out of my way..",
                                  "or I'll kick your but.. ",}), 0);
  money= new("/std/obj/coins");
    money -> set_money("silver", rand_money);
    money -> move(this_object());
set_melee_damage((["crushing":5]));
    set_hp(40);
    set("aggressive", 0);
    set_skill("melee", 15);
    set_skill("attack",15);
    set_skill("dodge", 7);
    set_skill("parry", 7);
    set_body_type("humanoid");
    set_emotes(20, ({"The male gobo growls at you standing his ground",
                 "The male gobo spits at your feet..",
                 "The male gobo glances around nervously.."})
  ,1);
  }

  string random_short()
  {
  int i;
    i = random(10);
    switch(i)
    {
    case 0 : return "An young male gobo";
    case 1 : return "A pudgy male gobo";
    case 2 : return "A dirty male gobo";
    case 3 : return "A thin male gobo";
    case 4 : return "A fat male gobo";
    case 5 : return "A tall male gobo";
    case 6 : return "A fat male gobo";
    case 7 : return "A muscular male gobo";
    case 8 : return "An ugly male gobo";
    case 9 : return "A strapping male gobo";
    }
  }
