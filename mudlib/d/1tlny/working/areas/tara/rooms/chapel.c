inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"


void init() {
  ::init();
   add_action("pray", "pray");
}
void create() {
  ::create();
   set_property("light", 2);
   set_property("night light", 1);
   set_property("indoors", 1);
   set("short", "A small chapel");
   set("day long", @DAY
This is a small chapel built into the hillside of Tara.
There are only a few pious halflings in the town, but they
are enough to keep the building up.  A few row's of pews stand
before a large altar.  You can see no specific sign of what God is
worshiped here, perhaps this is just a place for people of all
beliefs to come and pray.
DAY
);
   set("night long", @NIGHT
This small chapel is built into the hillside, because there are few
religious halflings, the church is not very fancy.  Only a few
rows of pews stand before a large alter at the center of the
chapel.  You can see no sign of what God is worshiped here,
maybe it is just a place for people of all beliefs to come and
pray.  It is void of people because it is night.
NIGHT
);
   add_item("pews", "A few rows of cheap pews for people to sit "+
   "during services.");
   add_item("altar", "This large altar has been built to be "+
   "prayed in front of.");
   set_listen("default","The songs of worship can be heard.");
   set_smell("default","The air smells of insense.");
}

int pray() {
  if(!this_player()->query_ghost()) {
   notify_fail("You pray, but nothing happens.\n");
   return 0;
   }
   write("You pray to the God you worship for your soul.");
   say(this_player()->query_cap_name()+" prays for his God "+
   "to revive him from his ghostly form.\n");
   this_player()->stop_hunting();
   this_player()->revive();
   this_player()->set_hp(20);
   this_player()->set_heart_beat(1);
   return 1;
}
