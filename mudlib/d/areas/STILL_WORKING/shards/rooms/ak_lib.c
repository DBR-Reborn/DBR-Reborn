#include "../shards.h"
inherit "std/room";


void init() {
  ::init();
  add_action("read_fun", "read");
}


void create() {
  ::create();
    set_property("indoors",1);
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_res2", "east");
    set("short","Oasis of Knowledge");
    set("long","This must have been the City Library in the distant past. Incredibly, the books here have stayed intact, despite the destruction around them. The only possible explanation for this is magic, and powerful magic at that.");
    add_item("books","You see a history book, a note, and a self-help book");
    add_item("tomes","You see a history book, a note, and a self-help book");
    add_item("history book","A History of the World Pt. I");
    add_item("self-help book","Everything You Always Wanted to Know, But Were Afraid to Ask");
    add_item("note","Hmm, maybe you should read it.");
    
}


int read_fun(string str) 
{
  if (!str) {
    notify_fail("Read what?\n");
    return 0;
  }

  if (str == "history book") {
    this_player()->more("/wizards/mikus/history");
    return 1;
  }
  if (str == "self-help book") {
    this_player()->more("/doc/help/user/faq");
    return 1;
  }
if (str == "note") {
    this_player()->more(OBJ+"note");
    return 1;
  }

  notify_fail("You do not see that here!\n");
  return 0;
}
      
  










