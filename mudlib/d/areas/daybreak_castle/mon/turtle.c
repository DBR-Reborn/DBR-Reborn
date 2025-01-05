#include <std.h>

inherit MONSTER;

string random_short();

void create() {
string rand_short;
   //object ob;
  ::create();
  rand_short = random_short();
  set_name("Turtle");
  set_id( ({ "turtle","Turtle" , "turtle", "turtle", "turtle"}) );
  set_level(3);
  set("short", rand_short);
  set("long","A disgusting hairy turtle. Careful it might have germs or even worse COVID-19!");
  set("turtle","rodent");
  set_body_type("quadruped");
  set_overall_ac(3);
  set_melee_damage((["crushing":3]));
  set_hp(25);
  set_skill("melee", 15);
  set_skill("attack", 15);
  set_skill("dodge", 15);
  set_skill("parry", 15);
	set_money("silver", 30);
   //ob = new("/d/damned/virtual/great-helm.armour");
   //ob->move(this_object()); 
  set("aggressive", 0);
  set_emotes(10, ({"The turtle drags himslf from a hole between two stone slats and paces himself across the room",
                   "The turle bites your ankle"}), 1);
				   }

string random_short()
{
int i;
  i = random(10);
  switch(i)
  {
    case 0 : return "[3]evil looking hairy turtle";
    case 1 : return "[3]mottled grey turtle";
    case 2 : return "[3]disgusting slow moving turtle";
    case 3 : return "[3]sad looking  turtle";
    case 4 : return "[3]dranged looking tutrle";
    case 5 : return "[3]diseased looking turtle";
    case 6 : return "[3]ankle-bitten turtle";
    case 6 : return "[3]possible a ninja turtle";
    case 7 : return "[3]mangy looking turtle";
    case 8 : return "[3]angry but depressed looking turtle";
    case 9 : return "[3]pathetic looking turtle who has poor eye site";
  }
}
