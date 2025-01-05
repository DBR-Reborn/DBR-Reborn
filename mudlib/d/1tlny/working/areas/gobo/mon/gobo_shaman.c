//From Gobo Area
//Creators: Amel and Arctic
//May 97
//gobo_shaman.c

#include <std.h>
#include "/wizards/amel/defs/gobo.h"

inherit MONSTER;

void create()
{
  set_name("gobo shaman");
  set("id", ({"shaman", "gobo shaman", "gobo", "goblin"}));
  set_level(3);
  set("short", "An evil gobo shaman");
  set("long", 
"Dressed in dark tattered robes, this evil looking gobo glares at you "
"more intelligence in his eyes than all the other gobos combined.");

