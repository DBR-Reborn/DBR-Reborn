#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "1st Street");
set("night long","%^RESET%^The oil "
"lanterns lining the street "
      "flicker, and "
      "sputter making nearbye shadows appear to move and dance.  "
      "An alley to the west leads into darkness between two buildings.  "
      "A dirt path to the east looks well groomed and is well lit "
      "by numerious oil lanterns hanging from the outsides of the buildings "
      "to the "
      "north and south of it.  1st Street continues north and south.%^RESET%^\n");
set("day long", "%^RESET%^%^ORANGE%^A dark alley "
"lay to the west in between some "
      "buldings.  A well lit dirt path is located to the east, and runs "
      "all the way up to the Shao-tan stables.  To the north you see "
      "the clothing shop and general store, and further down the road you "
      "can just make out a large stage at executioners square.\n");
add_exit("al1","west");
add_exit("path1","east");
add_exit("1st6","north");
add_exit("1st4","south");

}
