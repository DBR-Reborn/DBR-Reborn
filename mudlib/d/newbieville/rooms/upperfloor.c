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
    set("long", "This is the upper floor of the castle. You see before you scattered many weapons left by other adventures.\n%^B_RED%^If you are a new player you should%^RESET%^ %^COLOR120%^stop%^RESET%^ wait at least 30 secounds and\ntype%^RESET%^ %^YELLOW%^read sign%^RESET%^%^RESET%^ for further isntructions\nAfter you have read the sign and gathered the weapon or weapons you need\n%^BOLD%^%^RED%^you should go%^YELLOW%^ up or 'u' for short%^RESET%^%^RESET%^\n\n you can also %^YELLOW%^'look sign'%^RESET%^ for further directions
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
"If this room is empty wait 10 secounds in this room it will respawn. After it respawns type %^YELLOW%^'look'%^RESET%^ or %^YELLOW%^'l'%^RESET%^ for short to see what is on the ground\n\n"
"You can type %^YELLOW%^'get (item)'%^RESET%^ to pick up a weapon for example %^YELLOW%^'get sword'%^RESET%^\n\n"
"Once you have a item you can type %^YELLOW%^'equip'%^RESET%^ or wield weapon in a certain hand example %^YELLOW%^'wield sword in right hand'%^RESET%^ you should check what hand you prefer with %^YELLOW%^'score'%^RESET%^\n\n"
"Please note that you must have weapon skill such as blade, axe, or blunt to be of any use with that weapon type\n\n"
"You will need to join a guild in daybreak first to train weapon skills for now read the rooms description and follow directions\n\n"

"If this room is Empty and does not have any weapons wait for it to respawn or message a Wizard or Arche with %^YELLOW%^'who'%^RESET%^ then type %^YELLOW%^'tell (person) msg'%^RESET%^ example 'tell TLNY hi'\n\n"

"You can also type %^YELLOW%^'help newbie'%^RESET%^ and read the helpfile while you wait";
  this_player()->more(explode(msg, "\n"));
return 1;
}

void init() {
  ::init();
  add_action("read_it", "read");
  call_out("reset",10,this_player());
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
object ob;
if(!present("longsword")) {
    ob = new("/d/damned/virtual/long-sword_1.weapon");
    ob -> set("short", "burning longsword");
    ob -> set("long","This is a long sword that's blade is magicaly burning and on fire it is used by new players to help them explore and understand the world of DayBreak");
    ob -> set("id", ({ "sword", "Sword","long sword","burning long sword","cheap burning long sword", "longsword"}));
    //ob -> set_wc(40,"cutting");
    //ob -> set_wc(20,"impaling");
    //ob -> set_wc(40,"fire");
    ob->set_decay_rate(1000);
    ob -> set_hit_bonus(50);
    ob -> set_parry_bonus(50);
    ob -> set_material("metal/mithril");
    ob->move(this_object());
}
if(!present("short sword")) {
    ob = new("/d/damned/virtual/short-sword_1.weapon");
    ob -> set("short", "frozen short sword");
    ob -> set("long","This is a short sword that's blade is frozen solid as it comes close in contact with living things it begins to freeze all that is near. It is used by new players to help them explore and understand the world of DayBreak");
    ob -> set("id", ({ "sword", "Sword","short sword","frozen short sword","cheap frozen short sword"}));
    //ob -> set_wc(40,"cutting");
    //ob -> set_wc(20,"impaling");
    //ob -> set_wc(40,"cold");
    ob->set_decay_rate(1000);
    ob -> set_hit_bonus(50);
    ob -> set_parry_bonus(50);
    ob -> set_material("metal/elrodnite");
    ob->move(this_object());
}
if(!present("rapier")) {
    ob = new("/d/damned/virtual/rapier_1.weapon");
    ob -> set("short", "wind rapier");
    ob -> set("long","This is a rapier that's blade is surrounded by what looks like a tornado. It is used by new players to help them explore and understand the world of DayBreak");
    ob -> set("id", ({ "rapier", "Rapier","wind rapier","cheap wind rapier" }));
    ob -> set_wc(10,"impaling");
    ob -> set_wc(10,"vacuum");
    ob->set_decay_rate(1000);
    ob -> set_hit_bonus(50);
    ob -> set_parry_bonus(50);
    ob->move(this_object());
}
if(!present("scimitar")) {
    ob = new("/d/damned/virtual/scimitar_1.weapon");
    ob -> set("short", "electric scimitar");
    ob -> set("long","This is a scimitar that's blade is surounded by tiny electric bolts as you look closer it almost appears to pulse with energy. It is used by new players to help them explore and understand the world of DayBreak");
    ob -> set("id", ({ "scimitar", "scimitar","electric scimitar","cheap electric scimitar", "sword" }));
    //ob -> set_wc(40,"cutting");
    //ob -> set_wc(20,"impaling");
    //ob -> set_wc(40,"electricity");
    ob->set_decay_rate(1000);
    ob -> set_hit_bonus(50);
    ob -> set_parry_bonus(50);
    ob -> set_material("metal/platnite");
    ob->move(this_object());
}
    if(!present("two handed sword")) {
    ob = new("/d/damned/virtual/two-handed-sword_1.weapon");
    ob -> set("short", "electric two handed sword");
    ob -> set("long","This is a two handed sword that's blade is surounded by tiny electric bolts as you look closer it almost appears to pulse with energy. It is used by new players to help them explore and understand the world of DayBreak");
    ob -> set("id", ({ "two handed sword", "electric two handed sword","cheap electric two handed sword" }));
    //ob -> set_wc(50,"cutting");
    //ob -> set_wc(30,"impaling");
    //ob -> set_wc(50,"electricity");
    ob->set_decay_rate(1000);
    ob -> set_hit_bonus(50);
    ob -> set_parry_bonus(50);
    ob -> set_material("metal/platnite");
    ob->move(this_object());
}
    if(!present("halberd")) {
ob = new("/d/damned/virtual/halberd_1.weapon");
    ob -> set("short", "electric halberd");
    ob -> set("long","This is a halberd that's blade is surounded by tiny electric bolts as you look closer it almost appears to pulse with energy. It is used by new players to help them explore and understand the world of DayBreak");
    ob -> set("id", ({ "halberd", "electric halberd","cheap electric halberd" }));
    //ob -> set_wc(51,"cutting");
    //ob -> set_wc(31,"impaling");
    //ob -> set_wc(51,"electricity");
    ob->set_decay_rate(1000);
    ob -> set_hit_bonus(50);
    ob -> set_parry_bonus(50);
    ob -> set_material("metal/platnite");
}
    if(!present("dagger")) {
    ob = new("/d/damned/virtual/dagger_1.weapon");
    ob -> set("short", "electric dagger");
    ob -> set("long","This is a short dagger that's blade is surounded by tiny electric bolts as you look closer it almost appears to pulse with energy. It is used by new players to help them explore and understand the world of DayBreak");
    ob -> set("id", ({ "dagger", "electric dagger","cheap electric dagger","knife" }));
    //ob -> set_wc(35,"impaling");
    //ob -> set_wc(35,"electricity");
    ob->set_decay_rate(1000);
    ob -> set_hit_bonus(50);
    ob -> set_parry_bonus(50);
    ob -> set_material("metal/platnite");
    ob->move(this_object());
}
    if(!present("footman's mace")) {
    ob = new("/d/damned/virtual/footman's-mace_1.weapon");
    ob -> set("short", "electric footman's mace");
    ob -> set("long","This is a footman's mace that is surounded by tiny electric bolts as you look closer it almost appears to pulse with energy. It is used by new players to help them explore and understand the world of DayBreak");
    ob -> set("id", ({ "mace","footman's mace", "electric footman's mace","cheap electric footman's mace", "electric mace","cheap electric mace" }));
    //ob -> set_wc(40,"crushing");
    //ob -> set_wc(40,"electricity");
    ob->set_decay_rate(1000);
    ob -> set_hit_bonus(50);
    ob -> set_parry_bonus(50);
    ob -> set_material("metal/platnite");
    ob->move(this_object());
}
    if(!present("quarter staff")) {
    ob = new("/d/damned/virtual/quarter-staff_1.weapon");
    ob -> set("short", "electric quarter staff");
    ob -> set("long","This is a quarter staff that is surounded by tiny electric bolts as you look closer it almost appears to pulse with energy. It is used by new players to help them explore and understand the world of DayBreak");
    ob -> set("id", ({ "staff","quarter staff", "electric quarter staff","cheap electric quarter staff", "electric staff","cheap electric staff" }));
    //ob -> set_wc(45,"crushing");
    //ob -> set_wc(45,"electricity");
    ob->set_decay_rate(1000);
    ob -> set_hit_bonus(50);
    ob -> set_parry_bonus(50);
    ob -> set_material("metal/platnite");
    ob->move(this_object());
}
    if(!present("hand axe")) {
    ob = new("/d/damned/virtual/hand-axe_1.weapon");
    ob -> set("short", "electric hand axe");
    ob -> set("long","This is a hand axe that is surounded by tiny electric bolts as you look closer it almost appears to pulse with energy. It is used by new players to help them explore and understand the world of DayBreak");
    ob -> set("id", ({ "axe","hand axe", "electric hand axe","cheap electric hand axe", "electric axe","cheap electric axe" }));
    //ob -> set_wc(42,"cutting");
    //ob -> set_wc(42,"electricity");
    ob->set_decay_rate(1000);
    ob -> set_hit_bonus(50);
    ob -> set_parry_bonus(50);
    ob -> set_material("metal/platnite");
    ob->move(this_object());
    }
}
