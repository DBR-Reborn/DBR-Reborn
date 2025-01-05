#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	
//if (!present("rat")) {
	  //new("/d/newbieville/mon/rat.c")->move(this_object());
	//}

}


void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "Lower Level of The Castle of Tailwind");
    set("long", "You see a sign here you should '%^YELLOW%^read sign%^RESET%^' ");
    add_exit("/d/newbieville/rooms/newbie1", "up");


set_items( (["sign": (: call_other, this_object(), "read_sign" :)]) );
return;
}

int read_sign() {
string msg;

  msg = @ext
Welcome new player. Your adventure begins.

Movement in Daybreak Ridge is simple as typing %^YELLOW%^north, east, west, south, up, or down%^RESET%^

The quick movement for these commands are %^YELLOW%^n, e, w, s, u, d%^RESET%^

For now I suggest you go '%^YELLOW%^up%^RESET%^' or '%^YELLOW%^u%^RESET%^' for short.


If you are a experienced player and wish to skip the tutorial you may type 'end tutorial' while in this room and a portal will appear taking you to Daybreak Ridge.
ext;
  this_player()->more(explode(msg, "\n"));
return 1;
}

void init() {
  ::init();
  add_action("read_it", "read");
  call_out("reset",200,this_player());
  add_action("exit_tutorial","end");
  return;
}

int read_it(string str) {
   if(str == "sign") {
      read_sign();
   return 1;
   }
   return 0;
} 


int exit_tutorial(string str){
    if(str == "tutorial"){
      write("You say the words 'open sesame' and the room changes before you a portal appears and as you look through it's glass like reflection you see the townsquare of Daybreak Ridge type 'portal' to leave the tutorial. %^B_RED%^Be warned once you leave you are not allowed to come back here to gather any further newbie gear%^RESET%^%^RESET%^\n");
      say(this_player()->query_cap_name()+"says 'open sesame' and a portal appears");
        add_exit("/d/daybreak/room/db_square", "portal");
        delayed_call("close_door",60);
      return 1;
    }
}
void close_door(){
   remove_exit("exit");
   tell_room(this_object(),"The portal vanishes before you.\n");
   return;
}

