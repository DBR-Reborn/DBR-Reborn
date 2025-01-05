//From Gobo Area
//May 97
//Creators: Arctic and Amel
//fly.c

#include <std.h>
#include <gobo.h>

inherit MONSTER;

void create()
{
  ::create();
  set_name("cave fly");
  set("id", ({"fly", "cave fly"}));
  set("short", "An annoyed looking cave fly");
  set("long", 
"This fly is HUUUGE! Nearly as big as a childs fist, the fly buzzes " 
"around the room angrily. Wonder what kinda shit this fly must feed "
"on to get so damn big.");
  set_level(1);
  set("race", "insect");
  set_body_type("insectoid-winged");
  set_overall_ac(1);
  set_gender("nueter");
  set_emotes(30, ({"The fly buzzes around.", 
		   "The fly lands on a pile of shit."}),0);
  set_skill("melee", 5);
  set_skill("attack", 5);
  set_skill("dodge", 5);
  set_skill("parry", 1);
}


