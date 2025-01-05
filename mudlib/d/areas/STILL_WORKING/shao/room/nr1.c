#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Northern Row");
set("night long","%^RESET%^Soft candle light "
"flows from the "
      "open door of the building to the south onto the cobble stone"
      " street.  To the west the bright lights of the north western "
      "city gate can be seen.\n"
      "\n"
      "Northern Row continues east into the city...\n");
set("day long","%^RESET%^%^ORANGE%^You stand "
"at the west most end of Northern Row.\n"
"The large gates of %^RESET%^Black Dagger Arena "
"%^RESET%^%^ORANGE%^can "
      "be seen a block or so to the north.  The bulding directly to "
"the south looks to be baracks of some sort. "
"The cobble stones on this street seem very worn down, "
"suggesting a lot of traffic on it.\n"
      "\n"
      "City gates lay to the west and Northern Row continues east "
      "towards the library and Knights Inn.\n");
    add_exit("nw_entrance", "west");
    add_exit("nr2", "east");
    add_exit("G_bar1", "south");
    add_exit("ar1", "north");

}
