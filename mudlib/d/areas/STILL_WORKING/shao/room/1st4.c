#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "1st Street");
set("night long","%^RESET%^The oil lanterns "
"lining the street "
      "flicker, and "
      "sputter making nearbye shadows appear to move and dance.  "
      "The homes of citizens line the east and west sides of 1st Street "
      "you see a dim light in the house to the west, the one to the east "
"is pitch black.  "
      "The dark street continues south while an intersection "
      "lay to the south.%^RESET%^");
    set("day long", "%^RESET%^%^ORANGE%^The homes of citizens line the east and west sides "
      "of 1st Street, judging by the boards on the doors, and windows, "
      "they both look abandoned.  "
      "This cobble stone street continues north towards the center of town, "
      "and south to Commoners Row, Peon Row, and the south gate.\n");
    add_exit("cit19","west");
    add_exit("cit20","east");
    add_exit("1st5","north");
    add_exit("1st3","south");

}
