//#include "../newbieville.h"
#include <daybreak.h>
#include <std.h>
#include <rooms.h>
#include <security.h>

inherit "/std/vault";


//inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "Upper Level of The Castle of Tailwind");
    set("long", "This is the upper floor of the castle.\n\n%^B_RED%^If this room is empty%^RESET%^ wait at least 10 secounds and type%^RESET%^ '%^YELLOW%^look%^RESET%^' or '%^YELLOW%^l%^RESET%^' for short and you will see many peices of gear on the ground. Type '%^YELLOW%^read sign%^RESET%^' for further isntructions on how to gather the items and use them. After you have read the sign and gathered all the items and '%^YELLOW%^equip%^RESET%^' them you should go%^RESET%^ '%^YELLOW%^up%^RESET%^' or '%^YELLOW%^u%^RESET%^' for short%^RESET%^
");
    add_exit("/d/newbieville/rooms/newbie1", "down");
    add_exit("/d/newbieville/rooms/newbie3", "up");

set_items( (["sign": (: call_other, this_object(), "read_sign" :)]) );
return;
}

int read_sign() {
string msg;

  msg =
"This room is to help you get all items and equip them\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
"You can type '%^YELLOW%^get all%^RESET%^' to pick up all items in a room be careful you can also be overweight by doing this to often.\n\n"

"Once you have a item you can type just one word %^YELLOW%^'equip'%^RESET%^ or you can type for example '%^YELLOW%^wear glove on right hand%^RESET%^'\n\n"

"for better light as a new player you can type %^YELLOW%^'light lantern'%^RESET%^ to provide you a better light sorce during the night. Be aware it only has so much fuel before you need more oil to refuel it. The lanterns '%^BOLD%^%^RED%^do not save%^RESET%^' so if you log out in a dark area be aware of this.\n\n"

"if you picked up the ration packs you will need to eat type '%^YELLOW%^get ration from pack%^RESET%^' to get the food from the pack you will need to grab all 5 so type it 5 times and after type '%^YELLOW%^eat ration%^RESET%^' to consume them. You will also need to drink water type '%^YELLOW%^drink fountain%^RESET%^' and then type score to check your status drink more if needed.\n\n"

"Now that you have armour and equiped it can also type '%^YELLOW%^protection%^RESET%^' to see what protection and damage types are in the game. Also you can type '%^YELLOW%^protection limbs%^RESET%^' to see what protection you have on body parts you have.";
  this_player()->more(explode(msg, "\n"));
return 1;
}

void init() {
  ::init();
  add_action("read_it", "read");
  call_out("reset",9,this_player());
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

 if(!present("fountain")){
    new("/d/daybreak/obj/fountain.c")->move(this_object());
    }

if(!present("pack")) {
ob = new("/std/diewarzau/obj/misc/rations_pack");
ob->set_rations(5, 1);
ob->move(this_object());
}
if(!present("scroll")) {
ob = new("/d/1tlny/loot/crystal/scroll_tp");      
ob->move(this_object());
ob = new("/d/1tlny/loot/crystal/scroll_tp");      
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
    //ob = new("/d/1tlny/loot/crystal/pet_rabbit.c");
    //ob->move(this_object());
}

}
