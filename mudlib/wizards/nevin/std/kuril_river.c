// an inhertitable water room
// Excelsior 2-15-96
// set("difficulty",int i); to set how hard it is to swim in these waters.
// 100 is hard, 1 is a puddle you can walk through
// set("damage",int i); to set how much damage is done. 1 is instant death,
// 20 is normal. 50+ is low.
//
// Modified from Excelsior's water_room.c for use in the Kuril River System

#include <std.h>

inherit "/std/pier";

int living_filter(object who) {
  return who->is_player();
}

void damage_all() {
  object *who_here;
  int i, j, dif;
  string *limbs;
  int flag;
  who_here = filter_array(all_inventory(this_object()),
                          "living_filter", this_object());
  if(!who_here || !sizeof(who_here)) return;
  i = sizeof(who_here);
  dif = query("difficulty");
  if(!dif) dif = 100;
  while(i--) {
    limbs = (string *)who_here[i]->query_limbs();
    j = sizeof(limbs);
    flag = 0;
    while(j--)
      if(member_array("wing", explode(limbs[i], " "), 4) >= 0)
        flag = 1;
    if(flag) continue;
    if(who_here[i]->query_boat()) continue;
    if(who_here[i]->query_flying()) continue;
    if(random(dif) >= (int)who_here[i]->query_skill("swimming")) {
      who_here[i]->add_hp(-(int)who_here[i]->query_max_hp()/query("damage"));
      message("info", "%^BLUE%^You are drowning!", who_here[i]);
    }
  }
  remove_call_out("damage_all");
  call_out("damage_all", 5);
  return;
}

string query_terrain() { return "W"; }

// modified to have all non living items disappear into the water

void init() {
        object *inv;
        int i;
  ::init();
  this_object()->damage_all();
        inv = all_inventory(TO);
        i = sizeof(inv);
        while(i--) { 
                if(!living(inv[i])) { inv[i]->move("/d/nocte/kuril/rooms/"
                        "incinerator"); }
        }
  return;
}

void create() {
        ::create();
// lowered the difficulty to swim and the damage you take from 100->70 and
// 20->15
        set("difficulty",70);
        set("damage",15);
// default fishing in the rivers of kuril =b
        set_max_fishing(10);
        set_chance(5);
        set_max_catch(3);
        set_fish( ([
                "gerufish": 1,
        ]) );
}

