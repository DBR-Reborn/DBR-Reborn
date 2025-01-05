//Wiztower 7
// Coded by Glitch for DBR
// 06-28-00

#include <std.h>
#include "../wiztower.h"

inherit "std/room";

void create() {
  ::create();
  set_property("indoors", 1);
  set_property("light", 1);
  set("short","Bedroom.");
  set("long", "You've entered a very nice bedroom. A four poster bed with comfortable quilts is against the west wall. Near the bed is a small night stand. Beside that is a dresser. All are of good quality and are sound.");
  add_exit(ROOMS+"wiztower7","east");
  set_items( ([ ({ "room", "bedroom", "here" }) : "The room you're in.",
     ({ "bed","four poster bed"}) : "A bed with four large posts at each corner",
     ({ "wall", "west wall" }) : "The wall is bare save for one small painting.",
     "painting" : "The painting is of a man in armour figting some sort of evil undead. Acrost the top of the painting is a name.",
     "name" : "The name reads, Bladestorm. During his younger years.",
     ({ "quilts", "comfortable quilts" }) : "The quilts look as though they'd keep you warm and cozy all night.",
     ({ "small night stand", "night stand", "stand" }) : "Its a small table near the bed.",
     "dresser" : "Used to store clothes.",
     ]) );
}
