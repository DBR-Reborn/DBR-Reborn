#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Northern Row");
set("night long","%^RESET%^Broken glass litters the "
"street here. "
      "The odd blood stain can be seen on the cobble stones, as a result"
      " of one of the common bar brawls wich randomly flow onto the "
      "street from the bar inside the Inn to the south.  "
      "A run down bulding to the north is dark inside. "
      "\n"
      "\n"
      "Northern row continues to the east and west.\n");
set("day long","%^RESET%^%^ORANGE%^The cobble stone "
"street is well worn here.\n"
      "A library is located to the north and an Inn and bar to the south.  "
      "Taking a glimps down the steet to the east you see city hall, "
      "a jail and way in the distance appears to be a church.  "
      "Towards the far west looks to be the city gate.\n");
    add_exit("nr2", "west");
    add_exit("nr4", "east");
    add_exit("Inn", "south");
    add_exit("library", "north");

set_smell("default", "The scent of stale beer and cigar smoke drifts "
      "onto the street from the bar to the south.\n");
}
