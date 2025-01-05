#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	
if (!present("rat")) {
	  new("/d/newbieville/mon/rat2.c")->move(this_object());
    new("/d/newbieville/mon/rat2.c")->move(this_object());
    new("/d/newbieville/mon/rat2.c")->move(this_object());
	}

}


void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "Upper Level of The Castle of Tailwind");
    set("long", "This is the upper floor of the castle. For helpful tips '%^YELLOW%^read sign%^RESET%^' in this room");
    add_exit("/d/newbieville/rooms/newbie3", "east");
    //add_exit("/d/newbieville/rooms/newbie4", "up");

set_items( (["sign": (: call_other, this_object(), "read_sign" :)]) );
return;
}

int read_sign() {
string msg;

  msg = @ext
You will notice that you will have to type many times. To help speed things up you can learn about aliases type '%^YELLOW%^help alias%^RESET%^' to learn more about it

I like to speed things up so you can do a alias like this '%^YELLOW%^alias k kill $*%^RESET%^' this will make it now so every time you type '%^YELLOW%^k%^RESET%^' and then a argumet such as a target for example '%^YELLOW%^k rat%^RESET%^' you will do the same thing as 'kill rat' but shorter

You can also if you really want to be lazy type '%^YELLOW%^alias kr kill rat $*%^RESET%^' this will now make it so every time you type '%^YELLOW%^kr%^RESET%^' you will attack and kill a rat you can also type '%^YELLOW%^kr 3%^RESET%^' with that argument to kill rat number 3 the $* means anything you type after kr will be the argument that will be implemented after your alias

To see all your aliases type just '%^YELLOW%^alias%^RESET%^' you can also remove aliases with '%^YELLOW%^unalias%^RESET%^' see the help files on them to learn more things you can do.

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

