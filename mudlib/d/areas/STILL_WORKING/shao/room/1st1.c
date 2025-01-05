#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "1st Street");
set("night long","%^RESET%^The oil lantern lining the"
" street "
      "flicker, and "
      "sputter making nearbye shadows appear to move and dance.  "
      "The homes of citizens line the east and west sides of 1st Street "
      "most of them falling apart as you stand and watch.\n"
      "The dark street continues to the north, while an intersection "
      "lay to the south.%^RESET%^");
set("day long","%^RESET%^%^ORANGE%^The homes of "
"citizens line the east and west sides "
      "of 1st Street, both appear to be in bad shape, one is boarded up.\n"
      "1st Street continues north while an intersection lay to the south.\n");
    add_item(("home, homes"), "There are two, an east home and a west home ");
    set_items( ([ "west home":(:this_object(),"look_whome":) ]) );
    set_items( ([ "east home":(:this_object(),"look_ehome":) ]) );
    add_exit("cit8","west");
    add_exit("cit16","east");
    add_exit("1street","south");
    add_exit("1st2","north");

}

