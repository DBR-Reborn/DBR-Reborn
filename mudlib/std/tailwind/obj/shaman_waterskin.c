// Just like the one in Die's std dir, except you can set the amount of drinks with "set_capacity"

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
  set_long("This is a skin bag with a spigot which may be used for "+
	   "containing water, wine, or the like.");
  set_weight(15);
  set_value(5);
  return;
}

string query_short() {
  if(strength) {
    switch(drinks_left*10/this_object()->query_property("maxcap")) {
    case 8..11:
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
  drinks_left = this_object()->query_property("maxcap");
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
  write("You drink the contents of the waterskin....aaaaahh.");
  this_player()->add_quenched(strength);
  this_player()->add_intox(intox);
  drinks_left--;
  if(drinks_left <= 0)
    this_object()->empty();
  return 1;
}

int set_capacity(int water) {
this_object()->set_property("maxcap", water);
return 1;
}
