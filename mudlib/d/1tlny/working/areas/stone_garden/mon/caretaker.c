 // Wizard: Shade Maelstorm //
 // Monster File: Stone Garden Caretaker//
 
#include <std.h>
inherit MONSTER;
 
void create() {
object hammer;
object corslet;
   ::create();
  set_name("Caretaker");

  set("id", ({"caretaker", "large caretaker" }));
   set_level(5+random(5)+random(5));
set_skill("blunt", 75);
set_money("gold",  random(50)+30);
  set("short", "A Caretaker");
   set("long",
  "A rather large and muscle bound caretaker is arranging the stone statues"
  " that abound in the garden. His constant moving of the stone statues has "
  "developed his muscles well, and he looks quite strong."
   );
  set("race", "high-man");
   set_overall_ac(30);
   set_gender("male");
   set_body_type("human");
   set_moving(1);
   set_speed(120);

 set_emotes(5, ({
    "The caretaker chips away at a realistic stone figure of a warrior", 
"You watch as the caretaker delicately taps at his stone work.",
"Small bits of stone fly about as the figure is slowly carved ",
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
 
 
