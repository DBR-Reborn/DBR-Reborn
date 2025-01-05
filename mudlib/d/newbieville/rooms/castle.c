#include "../newbieville.h"
#include <std.h>

inherit ROOM;
void create() {
  object ob;    

    ::create();

  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({"board", "castle board", "bets"}) );
  ob->set_board_id("newbieville_castle_board");
  ob->set_max_posts(50);
  ob->set_location(ROOMS+"castle");
  ob->set("short","Newbieville Bulletin Board");
  ob->set("long",@TEXT
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
This board is meant to help newbies out as they first begin their journeys
in Daybreak Ridge. Post guild tips, directions, or anything else that you
think will come in handy for them. You can also post advertisements for
wares or other services which may be appropriate for newbies.

Thanks!

-The Newbieville Management
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

TEXT
);

    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "The Castle of Tailwind");
    set("long", "This is the Castle of Lord Tailwind. You see a bulletin board in the center of the room, a staircase leading upwards, and nothing else.\n%^B_RED%^If you are a new player you should type %^YELLOW%^up or 'u' for short%^RESET%^%^RESET%^\n\n you can also %^YELLOW%^'look sign'%^RESET%^ for further directions");

    add_exit(ROOMS+"upperfloor", "up");
    add_exit(ROOMS+"townsquare", "out");

set_items( (["sign": (: call_other, this_object(), "read_sign" :)]) );

call_out("load_rooms", 1);
}

int read_sign() {
string msg;

  msg =
"Welcome new player! You should follow the rooms description and go up\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
"in this room you can %^YELLOW%^read board%^RESET%^ to see helpful posts from other players this is recommended if you are looking for what to do as a new player.\n\n"
"It is suggested that you follow the rooms description for now and go up one room and gather the items on the 2 upper flows and then come back here to read the board and then go %^YELLOW%^out%^RESET%^ and follow the directions of that sign\n\n"
"type in the command %^YELLOW%^'look sign'%^RESET%^ outside the castle and follow the directions on the next sign to travel to Daybreak\n";
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

int no_exit() { return 1; }


void load_rooms() {
	find_object_or_load("/d/newbieville/rooms/upperfloor");
	find_object_or_load("/d/newbieville/rooms/upperfloor2");
}
