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
    set("long", "This is the upper floor of the castle. You see before you a rat that glares at you menacingly.\n\nTo learn how to engage in combat type '%^YELLOW%^read sign%^RESET%^'\n\nAfter you learn about basic combat and how to get items from the corpse you should go%^RESET%^ '%^YELLOW%^up%^RESET%^' or '%^YELLOW%^u%^RESET%^' for short%^RESET%^");
    add_exit("/d/newbieville/rooms/newbie2", "down");
    add_exit("/d/newbieville/rooms/newbie3_u", "up");

    add_exit("/d/newbieville/rooms/newbie3_n", "north");
    add_exit("/d/newbieville/rooms/newbie3_e", "east");
    add_exit("/d/newbieville/rooms/newbie3_w", "west");
    add_exit("/d/newbieville/rooms/newbie3_s", "south");

set_items( (["sign": (: call_other, this_object(), "read_sign" :)]) );
return;
}

int read_sign() {
string msg;

  msg = @ext
You can type '%^YELLOW%^look rat%^RESET%^ 'you will notice it is carrying a item.

I suggest you be fully equiped first if you are then type '%^YELLOW%^kill rat%^RESET%^' you will then engage in auto combat.

After the creature dies you can type '%^YELLOW%^get all from corpse%^RESET%^' to gather all the items from the corpse or '%^YELLOW%^get helm from corpse%^RESET%^' to get a single item from the corpse. 

You will also notice that after you kill this monster and looted everything you now have a few silver pieces you can type '%^YELLOW%^score%^RESET%^' to see how much money you have or type '%^YELLOW%^money%^RESET%^'

Now that you have a new helm you can type '%^YELLOW%^wear helm%^RESET%^' notice that certain armour types can stack on each other but you can't wear 2 metal pieces or 2 leather peices on the same body part.

You can go up or engage in more combat with low level creatures by going %^YELLOW%^ n, e, w, s%^RESET%^ after your done practicing you can come back here and go '%^YELLOW%^up%^RESET%^'.

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

