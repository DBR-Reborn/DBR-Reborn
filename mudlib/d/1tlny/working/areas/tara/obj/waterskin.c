#include <std.h>

inherit OBJECT;

int strength;
int intox;
int drinks_left;


int full() { return strength; }

void create() {
  ::create();
  strength = 0;
  intox = 0;
  set_id( ({ "skin", "water skin", "waterskin" }) );
  set_name("water skin");
   set("short", "A halfling waterskin");
   set("long", @SKIN
This waterskin was made by a halfling from the town of Tara.
It can be used to carry around water for those who travel far
from fountains.
SKIN
);
  set_weight(15);
  set_value(5);
  return;
}

string query_short() {
  if(strength) {
    switch(drinks_left) {
    case 8..15:
      return "A full waterskin";
    case 4..7:
      return "A partially full waterskin";
    case 1..3:
    default:
      return "An almost empty waterskin";
    }
  }
  else return "An empty waterskin";
}

void fill(string id, int drink, int alc) {
  set_id(query_id() + ({ id }));
  strength = drink;
  intox = alc;
  drinks_left = 10;
  return;
}

void empty() {
  set_id(({ "skin", "water skin", "waterskin" }) );
  set_weight(15);
  strength = 0;
  intox = 0;
  return;
}

void init() {
  ::init();
  add_action("drink_me", "drink");
  return;
}

int drink_me(string str) {
  if(present(str, this_player()) != this_object()) return 0;
  if(!strength) {
    write("It is empty.");
    return 1;
  }
  write("You gulped down some water from your waterskin.  Very refreshing.");
  this_player()->add_quenched(strength);
  this_player()->add_intox(intox);
  drinks_left--;
  if(drinks_left <= 0)
    this_object()->empty();
  return 1;
}
