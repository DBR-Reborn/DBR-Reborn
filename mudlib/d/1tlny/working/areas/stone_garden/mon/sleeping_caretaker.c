 // Wizard: Shade Maelstorm //
 // Monster File: Stone Garden Caretaker//
 
#include <std.h>
inherit MONSTER;
 
void create() {
object hammer;
object corslet;
   ::create();
  set_name("Sleeping caretaker");

  set("id", ({"caretaker", "sleeping caretaker" }));
   set_level(5+random(5)+random(5));
  set_skill("iron fist", 50);
set_skill("whirlwind attack", 50);
set_skill("melee", 80);
set_money("gold",  random(50)+30);
  set("short", "A Sleeping Caretaker");
   set("long",
  "A very exhausted caretaker is sleeping on one of the beds. He is weary after his"
  "hard days work."
   );
  set("race", "high-man");
   set_overall_ac(30);
   set_gender("male");
   set_body_type("human");
   set_moving(1);
   set_speed(0);

 set_emotes(5, ({
  "Loud snoring sounds can be heard from the sleeping caretaker.",
  "The caretaker rolls a little in his sleep.",
  "The caretaker makes a few loud snorts, then goes back to sleep.",
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
 
  void catch_tell(string str) {
   string a;
    object ob1;
    if(sscanf(str, "%s enters.", a) ==1) {
  a = lower_case(a);
   ob1 = present(a, environment(this_object()));
   if(ob1)
     if (random(1) == 0) {

  write("You have just pissed off a caretaker who was trying to get some sleep.\n");
    set("short", "A extremely annoyed Caretaker");
  set("long",
  "This caretaker is extremely pissed that you woke him up. He looks extremely"
  "mad.");
  force_me("use whirlwind attack");
  force_me("use iron fist");
  force_me("kill " + a);
    }
 
   }

  }




