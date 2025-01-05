 // Wizard: Shade Maelstorm //
 // Monster File: Troll Gardener//
 
#include <std.h>
inherit MONSTER;
 
void create() {
object hammer;
object corslet;
   ::create();
  set_name("Troll Gardener");

  set("id", ({"gardener", "troll" }));
   set_level(5+random(5)+random(5));
set_skill("blunt", 75);
set_money("gold",  random(50)+30);
  set("short", "A Troll Gardener");
   set("long",
"  Taking care of the flora side of the stone garden is a small half-troll"
  "gardener. He seems extremely skilled with his tools as he digs up the hard"
  "broken stoned ground allowing small flowers to grow through the cracks."
  "developed his muscles well, and he looks quite strong."
   );
  set("race", "half-troll");
   set_overall_ac(30);
   set_gender("male");
   set_body_type("human");
   set_moving(1);
   set_speed(120);

 set_emotes(10, ({
  "The troll digs in the small garden, turning the soil.",
  "The troll gardener crouches and pulls up a few weeds that appear unwarranted. ",
"The gardener picks one of the flowers and gives it to the baby basilisks nearby.",
   }), 0);
hammer = new("/d/damned/virtual/hammer_5.weapon");
  hammer->set_material("misc/granite");
  hammer->set("short", "stone hammer");
  hammer->set("long", "This is a large stone hammer used for chiseling stone. It is "
   " quite heavy and looks like it could inflict quite a bit of damage. ");
  hammer->set_wc(20, "crushing");
  hammer->move(this_object());
force_me("wield hammer in right hand");

 corslet = new("/d/damned/virtual/corslet.armour");
corslet->set("short", "stone corslet");
corslet->set_material("/misc/granite");
corslet->move(this_object());
force_me("wear corslet");
}
 
 
