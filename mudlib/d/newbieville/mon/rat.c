#include <std.h>

inherit MONSTER;

string random_short();

void create() {
string rand_short;
   object ob;
  ::create();
  rand_short = random_short();
  set_name("rat");
  set_level(1);
  set("short", rand_short);
  set("long","A disgusting flea-bitten rat. Careful it might have germs!");
  set("race","rodent");
  set_body_type("quadruped");
  set_overall_ac(2);
  set_melee_damage((["crushing":2]));
  //set_hp(10);
  set_skill("melee", 10);
  set_skill("attack", 10);
  set_skill("dodge", 10);
  set_skill("parry", 10);
	set_money("silver", 10);
    ob = new("/d/damned/virtual/great-helm.armour");
    ob->move(this_object()); 
  set("aggressive", 0);
  set_emotes(10, ({"The rat skitters across the room",
                   "The rat bites your toe"}), 1);
}

string random_short()
{
int i;
  i = random(10);
  switch(i)
  {
    case 0 : return "[1]evil looking black rat";
    case 1 : return "[1]mottled grey rat";
    case 2 : return "[1]disgusting white rat";
    case 3 : return "[1]plaque ridden rat";
    case 4 : return "[1]dranged looking rat";
    case 5 : return "[1]diseased rat";
    case 6 : return "[1]flea-bitten rat";
    case 6 : return "[1]sleek white rat";
    case 7 : return "[1]mangy looking rat";
    case 8 : return "[1]angry rat";
    case 9 : return "[1]pathetic looking rat";
  }
}
