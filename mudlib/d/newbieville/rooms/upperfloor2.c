//#include "../newbieville.h"
#include <daybreak.h>
#include <std.h>
#include <rooms.h>
#include <security.h>


#define WEAPONS ({ "long-sword", "short-sword", "bastard-sword", \
  "two-handed-sword", "halberd", "glaive", "dagger", "footman's-mace", \
  "footman's-flail", "quarter-staff", "great-axe", "hand-axe", \
  "morning-star" })
#define TORSO_ARMOUR ({ "breast-plate", "leather-jacket", "chain-mail", "studded-leather-jacket", "corslet", "leather-vest" })
#define LEG_ARMOUR ({ "chain-greaves", "iron-greaves", "scale-greaves", "leather-pants", "studded-leather-pants" })
#define HEAD_ARMOUR ({ "great-helm", "chain-coif" })
#define SHIELDS ({ "large-shield", "buckler-shield", "small-shield" })
#define FEET_ARMOUR ({ "metal-boots" })

inherit "/std/vault";


//inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "Upper Level of The Castle of Tailwind");
    set("long", "This is the upper floor of the castle. You see before you scattered many pieces of leather armour left by other adventures.\n%^B_RED%^If you are a new player you should%^RESET%^ %^COLOR120%^stop%^RESET%^ wait at least 10 secounds and\ntype %^RESET%^ %^YELLOW%^read sign%^RESET%^%^RESET%^\nAfter you gather the armour and other supplies\n%^BOLD%^%^RED%^you should go %^YELLOW%^up or 'u' for short%^RESET%^%^RESET%^\n\n you can also %^YELLOW%^'look sign'%^RESET%^ for further directions");
    add_exit("/d/newbieville/rooms/upperfloor", "down");
    add_exit("/d/newbieville/rooms/upperfloor3", "up");
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
"This sign is to help you get all items and equip\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
"If this room is empty wait 10 secounds in this room it will respawn. After it respawns type %^YELLOW%^'look'%^RESET%^ or %^YELLOW%^'l'%^RESET%^ for short to see what is on the ground\n\n"
"You can type %^YELLOW%^'get (item)'%^RESET%^ to pick up a item\n\n"
"Once you have a item you can type just one word %^YELLOW%^'equip'%^RESET%^ or you can type 'wear armour' in a certain limb such as right hand or left hand for gloves example %^YELLOW%^wear glove on right hand%^RESET%^\n\n"
"You can also type %^YELLOW%^'get all'%^RESET%^ to gather all the items in the room\n\n"
"for better light as a new player you can type %^YELLOW%^'light lantern'%^RESET%^ to provide you a better light sorce during the night. Be aware it only has so much fuel before you need more oil to refuel it.\n\n"
"You also have rations for food type %^YELLOW%^'get ration from pack'%^RESET%^ to get the food from the pack and type %^YELLOW%^'eat ration'%^RESET%^ to consume it\n\n"
"You can message a player or wizard with %^YELLOW%^who%^RESET%^ then type %^YELLOW%^tell (person) msg%^RESET%^\n\n"

"You can also type %^YELLOW%^help protection%^RESET%^ and read up on ac protection while you wait type %^YELLOW%^protection%^RESET%^ or type %^YELLOW%^protection limbs%^RESET%^";
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
if(!present("pack")) {
ob = new("/std/diewarzau/obj/misc/rations_pack");
ob->set_rations(5, 1);
ob->move(this_object());
}
if(!present("chain coif")) {
ob = new("/d/damned/virtual/chain-coif.armour");
    ob->move(this_object());
}
if(!present("leather vest")) {
ob = new("/d/damned/virtual/leather-vest.armour");
    ob->move(this_object());
}
if(!present("iron bracer")) {
    ob = new("/d/damned/virtual/iron-bracer.armour");
    ob->move(this_object());
    ob = new("/d/damned/virtual/iron-bracer.armour");
    ob->move(this_object());
}
if(!present("padded glove")) {
    ob = new("/d/damned/virtual/padded-glove.armour");
    ob->move(this_object());
    ob = new("/d/damned/virtual/padded-glove.armour");
    ob->move(this_object());
}
if(!present("leather pants")) {
    ob = new("/d/damned/virtual/leather-pants.armour");
    ob->move(this_object());
}
if(!present("leather boots")) {
    ob = new("/d/damned/virtual/leather-boots.armour");
    ob->move(this_object());
}
if(!present("lantern")) {
    ob = new("/std/obj/lantern");
    ob->move(this_object());
}
if(!present("crystal")) {
    ob = new("/d/1tlny/loot/crystal/pet_bear.c");
    ob->move(this_object());
    ob = new("/d/1tlny/loot/crystal/pet_rabbit.c");
    ob->move(this_object());
    }

}
