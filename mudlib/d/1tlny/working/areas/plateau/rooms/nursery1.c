
#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "A Centaur Nursery");
   set_long(
    " The nursery before you is very clean and large enough for about eight "
    "centaur children. There is a fenced in area, for the younger kids, and "
    "a playground for the older kids. There is a fountain here, and a kitchen"
    " in one corner."
    );
     add_exit("plat31", "out");
    set_smell("default", "The various smells that young children make fill the air..");
    set_listen("default", "The various sounds small children make fill the air.");
  }


void reset()    {
     ::reset();
     new(PLATMON + "ckid")->move(this_object());
     new(PLATMON + "ckid")->move(this_object());
     new(PLATMON + "ckid")->move(this_object());
     new(PLATMON + "ckid")->move(this_object());
     new(PLATMON + "ckid")->move(this_object());
     new(PLATMON + "ckid")->move(this_object());
     new(PLATMON + "ckid")->move(this_object());
     new(PLATMON + "ckid")->move(this_object());
      new(PLATMON + "ctmom")->move(this_object());
      new(PLATMON + "ctmom")->move(this_object());
   if(!present("fountain"))
    new("/d/nocte/kuril/misc/fountain")->move(this_object());
}


