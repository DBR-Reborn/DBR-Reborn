
  // Wandering Acolyte 
  // Created by Shade Maelstorm.
  // Using code from Arctic and Amel.
#include <std.h>

inherit MONSTER;

void create()
{
object sword, money;
object sgreaves, smail;
  ::create();
  set_name("Acolyte of the Stone Rose");
   set("id", ({"acolyte"}));
  set_level(14);
  set_cmd_array(({"south", "east", "south", "southeast", "south", "east", "south",
  "east", "south", "east", "west", "north", "west", "north", "west", "north",
  "north", "northwest", "north", "west", "north"}));
  set_cmd_interval(20);
  set_cmd_cycle(1);
  set("short", "Acolyte");
  set("long", 
"Grubuk is taller, fatter and smellier than any other goblin. That must "
"be why he is the chief. He is wearing rather nice armour and wielding "
"a rather nice weapon for a goblin.");
  set("race","goblin");
  set_gender("male");
  set_body_type("human");
  set_overall_ac(9);
  set_wielding_limbs(({"right hand","left hand"}));
  set("gang bang", 1);
  set_lang_prof("common", 8);
  set_speech(25, "common", ({"get outta here!", 
             "who lets these morons in here?!", "grrrrr"}), 0);
  set_speech(25, "common", ({"Guards!!", "kill tha bastards!"}), 1);
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


