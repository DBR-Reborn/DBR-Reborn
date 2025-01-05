inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",1);
   set("short","A thin roadway");
   set("day long", @DAY
This thin roadway leads northeast to the poorer district of Tara.
A tavern lies off the road a little further northeast, it being
one of the only buildings in the city to be built outside of the hill.
Beyond that leads to where the lower class halflings live, there
houses tend to be much smaller then the richer people they work for.
Southwest leads to the main intersection.
DAY
);
   set("night long", @NIGHT
This roadway leads northeast towards a tavern, and the Tara's lower
class district.  The tavern has a few torches outside it's walls,
inviting late guests to come drink and dine.  Not much can be seen
in the darkened residential zone beyond the tavern at this late hour. 
To the southwest is a dark intersection.
NIGHT
);
   add_item("tavern","The halflings unwinding place, they go there to "+
   "get a bite to eat, or drink away there problems.");
   add_item("houses","The distant houses appear small, but comfortable");
   add_item("intersection","The towns main intersection lies to the "+
   "southwest");
   add_item("roadway","The worn roadway leads northeast into the "+
   "low class area.");
   set_listen("default","Mirthful sounds eminate from the tavern.");
   set_smell("default","The air smells faintly of ale and brew.");
   add_exit(TARAROOMS+"rm1", "southwest");
   add_exit(TARAROOMS+"rm5", "northeast");
}
