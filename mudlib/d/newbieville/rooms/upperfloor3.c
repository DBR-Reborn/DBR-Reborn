#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	
if (!present("rat")) {
	  new("/d/newbieville/mon/rat.c")->move(this_object());
	}

}


void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "Upper Level of The Castle of Tailwind");
    set("long", "This is the upper floor of the castle. You see before you a rat that glares at you menacingly.\n%^B_RED%^If you are a new player you should%^RESET%^ %^YELLOW%^read sign%^RESET%^%^RESET%^\nAfter you learn about basic combat and how to get items from the corpse\n%^BOLD%^%^RED%^you should go %^YELLOW%^down or 'd' for short%^RESET%^ and then keep going down to the bottom floor and read the sign at the bottom floor for further instructions%^RESET%^%^RESET%^\n\n you can also %^YELLOW%^'look sign'%^RESET%^ for further directions");
    add_exit("/d/newbieville/rooms/upperfloor2", "down");
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

  msg = @ext
You can type %^YELLOW%^'look rat'%^RESET%^ to see and understand what type of monster this is and to see if it is carrying anything

I suggest that for now you type %^YELLOW%^'kill rat'%^RESET%^ you will then begin auto combat and start to fight the rat. Note many skills can help you define combat such as combat skills and combat spells you must first join a guild that has these skills or spells to use them.

After the creature dies you can type %^YELLOW%^'get all from corpse'%^RESET%^ to gather all the items from the corpse or %^YELLOW%^'get helm from corpse'%^RESET%^ to get a single item

notice that if you do not type the command fast enough the corpse will decay and all loot on the corpse will disapear so you must be quick.

You will also notice that after you kill this monster and looted everything you now have a few silver pieces that you can use to buy and trade from shopkeepers or players. type %^YELLOW%^'score'%^RESET%^ to see your player profile you can also type 'skills' or 'spells' to see if you have any skills or spells.

Also if you have already tried it if you type 'equip' the great helm you picked up does not auto replace the 'chain coif' you must 'remove coif' and then 'wear helm' to wear the better piece of armour. You can also 'drop coif' since it is no longer needed.

ext;
  this_player()->more(explode(msg, "\n"));
return 1;
}

void init() {
  ::init();
  add_action("read_it", "read");
  call_out("reset",200,this_player());
  return;
}

int read_it(string str) {
   if(str == "sign") {
      read_sign();
   return 1;
   }
   return 0;
} 

