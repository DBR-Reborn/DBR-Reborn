inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",2);
   set("short","A thin roadway");
   set("day long", @DAY
The roadway leads northeast, into the realms of the less fortunate
halflings.  A row of houses down the road are small, yet kept in decent
repair.  Directly easy is the tavern, halflings go there to eat,
drink, and be merry.  The tavern stands out, because it is one of
the only buildings not built into the hill, the only one in this
section of town.
DAY
);
   set("night long", @NIGHT
The roadway is well lit by torches outside the tavern.  Although
the hour is late, Bergin manages to keep his business open.  Worn
out halflings come to the tavern, intent on relaxing and knocking
back a few drinks.  The houses to the northeast are dark at this time,
none of the tenants able to afford torches.
NIGHT
);
   add_item("tavern","The busy tavern, owned and operated by Bergin, "
   "it is a popular place for halflings to unwind.");
   add_item("houses","The small houses are well tended, even "+
   "the less fortunate halflings take pride in their yards.");
   set_listen("default","The sounds of happy halflings come from "+
   "the tavern.");
   set_smell("default","The air smells strongly of food and ale.");
   add_exit(TARAROOMS+"rm3", "southwest");
   add_exit(TARAROOMS+"tvn", "east");
}
