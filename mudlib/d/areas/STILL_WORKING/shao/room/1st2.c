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
      "most of them falling apart as you stand and watch.\n"
      "The dark street continues south while an intersection "
      "lay to the north.%^RESET%^");
set("day long","%^RESET%^%^ORANGE%^The homes "
"of citizens line the east and west sides "
"of 1st Street, the one on the west side looks abandoned.\n"
      "1st Street continues south while an intersection lay to the north.\n");
    add_exit("cit1","west");
    add_exit("cit9","east");
    add_exit("1st1","south");
    add_exit("1st3","north");

}
