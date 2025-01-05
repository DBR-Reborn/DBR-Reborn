//#include "../newbieville.h"
#include <daybreak.h>
#include <std.h>
#define WEAPONS ({ "long-sword", "short-sword", "bastard-sword", \
  "two-handed-sword", "halberd", "glaive", "dagger", "footman's-mace", \
  "footman's-flail", "quarter-staff", "great-axe", "hand-axe", \
  "morning-star" })

inherit "/std/vault";

void clone_once();

//inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "Upper Level of The Castle of Tailwind");
    set("long", "This is the upper floor of the castle. You see before you scattered many weapons left by other adventures.\n%^B_RED%^If you are a new player you should wait and%^YELLOW%^look%^RESET%^%^RESET%^\nAfter you gather the weapon or weapons you need\n%^B_RED%^you should go%^YELLOW%^u%^RESET%^%^RESET%^\n\n you can also%^YELLOW%^'look sign'%^RESET%^for further directions
");
    add_exit("/d/newbieville/rooms/castle", "down");
    add_exit("/d/newbieville/rooms/upperfloor2", "up");
set_items((["window" :
"You peer down.
  #     B: Bar
 B#A    A: Armor Shop
##T##   W: Weapon Shop
 G#W    G: General Store
  #     T: Town Square/Castle
"]));
set_items( (["sign": (: call_other, this_object(), "read_sign" :)]) );
return;
}

int read_sign() {
string msg;

  msg =
"This sign is to help you pick up items and equip\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
"You can type%^YELLOW%^'get (item)'%^RESET%^to pick up a weapon\n\n"
"Once you have a item you can type%^YELLOW%^'equip'%^RESET%^or wield weapon in a certain hand\n\n"
"Please note that you must have weapon skill such as blade, axe, or blunt to be of any use with that weapon type\n\n"
"You will need to join a guild in daybreak first to train weapon skills for now read the rooms description and follow directions\n\n"

"If this room is Empty and does not have any weapons wait for it to respawn or message a Wizard or Arche with%^YELLOW%^who%^RESET%^ then type%^YELLOW%^tell (person) msg%^RESET%^\n\n"

"You can also type%^YELLOW%^help newbie%^RESET%^and read the helpfile while you wait";
  this_player()->more(explode(msg, "\n"));
return 1;
}

void init() {
  ::init();
  add_action("read_it", "read");
  return;
}

int read_it(string str) {
   if(str == "sign") {
      read_sign();
   return 1;
   }
   return 0;
} 

void reset() {
    if(!present("long-sword")) new("/d/damned/virtual/long-sword_1.weapon")->move(this_object());
    if(!present("short-sword")) new("/d/damned/virtual/short-sword_1.weapon")->move(this_object());
    if(!present("bastard-sword")) new("/d/damned/virtual/bastard-sword_1.weapon")->move(this_object());
    if(!present("two-handed-sword")) new("/d/damned/virtual/two-handed-sword_1.weapon")->move(this_object());
    if(!present("halbred")) new("/d/damned/virtual/halberd_1.weapon")->move(this_object());
    if(!present("dagger")) new("/d/damned/virtual/dagger_1.weapon")->move(this_object());
    if(!present("footman's-mace")) new("/d/damned/virtual/footman's-mace_1.weapon")->move(this_object());
    if(!present("quarter-staff")) new("/d/damned/virtual/quarter-staff_1.weapon")->move(this_object());
    if(!present("hand-axe")) new("/d/damned/virtual/hand-axe_1.weapon")->move(this_object());
}
