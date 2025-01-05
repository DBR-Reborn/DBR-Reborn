
// Priest of the stone death cult - symbol, grey rose
 //using code from Arctic and Amel
  // Modified by Shade Maelstorm.
#include <std.h>

inherit MONSTER;

void create()
{
object sword, money;
object sgreaves, smail;
  ::create();
  set_name("Priest");
   set("id", ({"priest"}));
  set_level(14);
  set("short", "Priest of the Stone rose");
  set("long", 
 "This is the high priest of the Stone death cult. He wears robes which flow "
 "over his body, and you notice the emblem on it is of a grey rose. He appears "
 "to be quite young, and would be human except he seems to be made out of stone.");
  set("race","stone human");
  set_gender("male");
  set_body_type("human");
  set_overall_ac(9);
  set_wielding_limbs(({"right hand","left hand"}));
  set("gang bang", 1);
  set_lang_prof("common", 8);
  sword = new("/d/damned/virtual/long-sword_6.weapon");
  sword -> set("short", "shining longsword");
  sword -> set("long",
"This weapon is extremely well made. The long, sharp blade is finely "
"balanced. Soft leather is wrapped around the pommel, making the sword "
"a pleasure to wield.");
  sword -> set_material("metal/steel");
  sword -> move(this_object());
  command("wield sword in right hand");
  sgreaves = new("/d/damned/virtual/scale-greaves.armour");
  sgreaves -> move(this_object());
  command("wear greaves");
  smail = new("/d/damned/virtual/scale-mail.armour");
  smail -> move(this_object());
  command("wear mail");
  money = new("/std/obj/coins");
  money -> set_money("gold", 150);
  money -> move(this_object());  

}


