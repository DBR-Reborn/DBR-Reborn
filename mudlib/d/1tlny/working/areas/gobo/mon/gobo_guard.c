  //Area: Gobos
  //Mon:  Gobo guard(aggresive)
  //Creators: Amel & Arctic

#include <std.h>

  inherit MONSTER;

  string random_short();
  int rand_money;

  void create()
  {
  string rand_short;
object sword, money, vest;
    ::create();
    rand_short = random_short();
    rand_money = random(30) +15;
set_name("gobo guard");
    set("id", ({"gobo_male","gobo male","gobo","guard","gobo guard","male","goblin"}));
    set_level(1);
    set("short", rand_short);
    set("long","A male gobo standing some four feet tall, with green"
               " skin, yellow eyes, and mangled pointy teeth.  This"
               " one seems to have donned some armour and wields a weapon.");
    set("race","goblin");
    set_gender("male");
    set_body_type("human");
    set_overall_ac(6);
    set_wielding_limbs(({"right hand","left hand"}));
    set("gang bang", 1);
    set_lang_prof("goblinish", 8);
    set_speech(10, "goblinish", ({"Get out of my way..",
                                  "or I'll kick your but.. ",}), 0);
    sword = new("/d/damned/virtual/short-sword_6.weapon");
    sword -> set("short", "shortsword");
    sword -> set("long",
  "This weapon was made some time ago and but is still in descent shape. "
  "The blade is scarred with deep grooves from constant use but looks to "
  "have a few good blows left in it.");
    sword -> set_material("metal/iron");
    sword -> move(this_object());
    command("wield sword in right hand");
    vest = new("/d/damned/virtual/leather-vest.armour");
    vest -> move(this_object());
    command("wear vest");
    vest = new("/d/damned/virtual/leather-pants.armour");
    vest -> move(this_object());
    command("wear pants");
    vest = new("/d/damned/virtual/leather-boots.armour");
    vest -> move(this_object());
    command("wear boots");
    money = new("/std/obj/coins");
    money -> set_money("silver", rand_money);
    money -> move(this_object());
set_melee_damage((["crushing":5]));
    set_hp(50);
set ("aggressive", 0);
    set_skill("blade", 17);
    set_skill("melee", 15);
    set_skill("attack",15);
    set_skill("dodge", 7);
    set_skill("parry", 7);
    set_body_type("humanoid");
    set_emotes(10, ({"The male gobo growls at you standing his ground",
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
    case 0 : return "An young gobo guard";
    case 1 : return "A pudgy gobo guard";
    case 2 : return "A dirty gobo guard";
    case 3 : return "A thin gobo guard";
    case 4 : return "A fat gobo guard";
    case 5 : return "A tall gobo guard";
    case 6 : return "A fat gobo guard";
    case 7 : return "A muscular gobo guard";
    case 8 : return "An ugly gobo guard";
    case 9 : return "A strapping gobo guard";
    }
  }
   
