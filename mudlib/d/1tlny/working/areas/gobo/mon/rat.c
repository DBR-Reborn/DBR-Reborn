#include <std.h>

inherit MONSTER;

string random_short();

void create()
{
string rand_short;
  ::create();
  rand_short = random_short();
  set_name("rat");
  set_level(1);
  set("short", rand_short);
  set("long","A disgusting flea-bitten rat. Careful it might have germs!");
  set("race","rodent");
  set_overall_ac(2);
  set_melee_damage((["crushing":2]));
  set_body_type("quadruped");
  set_hp(10);
  set_skill("melee", 10);
  set_skill("attack", 10);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  set("aggressive", 1);
  set_emotes(10, ({"The rat skitters across the room",
		   "The rat bites your toe"}), 1);
}

string random_short()
{
int i;
  i = random(10);
  switch(i)
  {
    case 0 : return "An evil looking black rat";
    case 1 : return "A mottled grey rat";
    case 2 : return "A disgusting white rat";
    case 3 : return "A plaque ridden rat";
    case 4 : return "A dranged looking rat";
    case 5 : return "A diseased rat";
    case 6 : return "A flea-bitten rat";
    case 6 : return "A sleek white rat";
    case 7 : return "A mangy looking rat";
    case 8 : return "An angry rat";
    case 9 : return "A pathetic looking rat";
  }
}

