  //Area: Gobos
  //Diseased gobo child
  //Creators: Amel & Arctic

#include <std.h>

  inherit MONSTER;

  string random_short();
string random_sex();

  void create()
  {
  object money;
  string rand_short;
  string rand_sex;
    ::create();
    rand_short = random_short();
    rand_sex = random_sex();
    set_name("gobo child");
    set("id", ({"gobo_child","gobo child","gobo","child","goblin"}));
    set_level(1);
    set("short", rand_short);
    set("long","A small gobo child covered in dirt wearing only rags.");
  set_gender(rand_sex);
    set("race","goblin");
    set_body_type("human");
    set_overall_ac(3);
    set_wielding_limbs(({"right hand","left hand"}));
    set("gang bang", 0);
    set_lang_prof("goblinish", 2);
    set_speech(35, "goblinish", ({"Gurgggle..",
                                  "Hungry.. ",}), 0);
    money = new("/std/obj/coins");
    money -> set_money("coper", 5);
    money -> move(this_object());
set_melee_damage((["crushing":5]));
    set_hp(10);
    set("aggressive", 0);
    set_skill("melee", 5);
    set_skill("attack", 5);
    set_skill("dodge", 2);
    set_skill("parry", 2);
    set_body_type("humanoid");
    set_emotes(10, ({"The small gobo crawls across the room",
                 "The gobo child sticks his filthy hand in his mouth",
                 "The gobo child begins to cry..",
                 "The small gobo holds up a handful of dirt to you..",
                 "The small gobo looks at you with tears in its eyes.."}),1);
  }
  string random_sex()
  {
  int i;
  i = random(2);
  if (i == 1) return "male";
  else return "female";
  }
  string random_short()
  {
  int i;
    i = random(10);
    switch(i)
    {
    case 0 : return "An evil little gobo";
    case 1 : return "A mottley little gobo";
    case 2 : return "A dirt covered little gobo";
    case 3 : return "A little gobo covered in rags";
    case 4 : return "A crying little gobo covered in snot";
    case 5 : return "A smileing little gobo";
    case 6 : return "A small gobo covered with mites";
    case 7 : return "A toothless little gobo";
    case 8 : return "An ugly little gobo";
    case 9 : return "A green little gobo";
    }
  }
