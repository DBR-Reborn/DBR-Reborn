#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

inherit ROOM;

void reset() {
  ::reset();
   if(!present("sheriff")) {
     new(TARAMON+"sheriff")->move(this_object());
   }
}

void init() {
  ::init();
   add_action("read_message","read");
}

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",1);
   add_exit(TARAROOMS+"rm17", "south");
   set("short", "A sheriff's building");
   set("day long", @DAY
This is the towns law enforcement building, unlike most of
the towns structures, this one is built above ground.  This
might be to make having to stay in jail more unbearable for
halflings.  The jail is a small barred area in the corner of
the building.  There is a desk here, important files and notes
rest on it, placed to aid the sheriff in his duties.  There
is a board with a message that looks to be of interest.
DAY
);
   set("night long", @NIGHT
Although it is night, this building is still open and alive.
This is the towns law enforcement building, and because crime
never rests, it remains open all night.  There is a jail in the
corner of the room, a small barred structure.  A desk lies to the
left of the entrance, it's purpose to hold the files and notes
that the sheriff needs.  There is a board against the wall, it
has an interesting message on it.
NIGHT
);
   add_item("jail", "The jail is empty at the moment, this "+
   "speaks somewhat for the sheriff's ability to supress crime.");
   add_item("desk", "A simple desk, it has some files and notes "+
   "on the top.  A plate of bacon is here also.");
   add_item("notes", "A few notes have been scratched onto a piece "+
   "of paper: \n"+
   "Slon is trying to cover something, he is too eager "+
   "to answer my questions... someday I will have to search "+
   "his house and the surrounding area.");
   add_item("files", "Files of arrests and convictions.");
   add_item("bacon", "A plate of bacon lies on the desk.");
   add_item("board", "The board only holds one message on it "+
   "right now, try 'reading' it.");
   set_smell("default", "The air smells of cooked pigs.");
   set_listen("default", "You can hear a hushed conversation.");
}

int read_message(string str){
   if(str != "message") return 0;
   write("This message has been left by Donny, a wealthy "+
   "halfling: \n"+
   "Citizens of Tara, I offer a great reward to whoever can "+
   "find my golden pipe.  No questions will be asked where it "+
   "was found.  For more information, talk with the sheriff about "+
   "my 'golden pipe', or simple inquire about a 'quest'.  Thank "+
   "you.\n");
   return 1;
}
