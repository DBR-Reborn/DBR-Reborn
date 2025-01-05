  //Area: Gobos
  //Mon:  Gobo Champion(aggresive)
  //Creators: Amel & Arctic

#include <std.h>

  inherit MONSTER;

  string random_short();
  int rand_money;

  void create()
  {
  string rand_short;
object axe, money, plate;
    ::create();
    rand_short = random_short();
    rand_money = random(60) +15;
set_name("gobo champion");
    set("id", ({"gobo_male","gobo male","gobo","champion","gobo champion","male","goblin"}));
    set_level(3);
    set("short", rand_short);
    set("long","A muscular male gobo standing some five feet tall, with green"
               " skin, yellow eyes, and mangled pointy teeth.  This"
               " one seems to have donned plate and wields a large battle-axe.");
    set("race","goblin");
    set_gender("male");
    set_body_type("human");
    set_overall_ac(10);
    set_wielding_limbs(({"right hand","left hand"}));
    set("gang bang", 1);
    set_lang_prof("goblinish", 8);
    set_speech(10, "goblinish", ({"Cower in fear..",
                                  "for I am the CHAMPION!!.. ",}), 0);
    axe = new("/d/damned/virtual/battle-axe_5.weapon");
    axe -> set("battleaxe", "axe");
    axe -> set("long",
  "This battle-axe was made some time ago and but is still in descent shape. "
  "The metal is scarred with deep grooves from constant use but looks to "
  "have a few good blows left in it.");
    axe -> set_material("metal/steel");
    axe -> move(this_object());
    command("wield axe in right hand");
    plate = new("/d/damned/virtual/breast-plate.armour");
    plate -> move(this_object());
    command("wear plate");
    plate = new("/d/damned/virtual/iron-greaves.armour");
    plate -> move(this_object());
    command("wear greaves");
    plate = new("/d/damned/virtual/metal-boots.armour");
    plate -> move(this_object());
    command("wear boots");
    money = new("/std/obj/coins");
    money -> set_money("silver", rand_money);
    money -> move(this_object());
set_melee_damage((["crushing":5]));
    set_hp(200);
set ("aggressive", 0);
    set_skill("axe", 40);
    set_skill("melee", 15);
    set_skill("attack",30);
    set_skill("dodge", 20);
    set_skill("parry", 20);
    set_body_type("humanoid");
    set_emotes(10, ({"The gobo champ struts before you",
                 "The gobo champ shifts position..",
                 "The gobo champ flexes his bicept.."})
  ,1);
  }

  string random_short()
  {
  int i;
    i = random(3);
    switch(i)
    {
    case 0 : return "A buff gobo champion";
    case 1 : return "A lean and mean gobo champion";
    case 2 : return "A massive gobo champion";
    }
  }
   
