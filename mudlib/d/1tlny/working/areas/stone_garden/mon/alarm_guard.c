 // Wizard: Shade Maelstorm //
 // need to adjust the monster file for this. This file is for the guards which
 // block the exit to the hut, when the alarm bells sound at death of mother.
 // Monster File: Stone Garden Caretaker//
 
#include <std.h>
inherit MONSTER;
 
void create() {
object hammer;
object corslet;
   ::create();
  set_name("Temple Guard");

    set("id", ({"guard"}));
  set_level(10+random(10));
set_skill("blunt", 75);
set_money("gold",  random(50)+30);
  set("short", "Temple Guard");
   set("long",
 "This temple guard is one of the stone soldiers that guard the temple of the "
 "Stone Rose. His one duty in life he believes is to guard this temple at "
 "all costs, and he is more than willing to fulfill his duty."
   );
  set("race", "high-man");
   set_overall_ac(30);
   set_gender("male");
   set_body_type("human");
   set_moving(0);
   set_speed(120);

 set_emotes(5, ({
  "The guard looks sternly at you, then ignores your presence ",
  "The stone soldier checks his sword sheath and resumes his vigilance ",
  "The temple guard stands still like stone, and you start to wonder ...",
  "The guard checks his sword sheath and resumes his vigilance "
  "The temple guard stands still like stone, and you start to wonder ..."
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
 
 
