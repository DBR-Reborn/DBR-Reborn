#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Northern Row");
set("night long","%^RESET%^An unlit dirt "
"road leads south into "
      "the darkness of night.  A Dim lantern sway from a street post "
      "on the south western side of the street.  In the distance "
      "to the north the bright lights of the %^RESET%^%^RED%^Black "
      "Dagger "
"Arena %^RESET%^can be seen. "
      "The stench of stale ale and sounds of loud ramblings to the "
      "east suggests a bar, to the far west a dim light can be seen "
      "comming from the north western city gate.\n");
set("day long","%^RESET%^%^ORANGE%^The sun warms "
"the cracked and worn cobble stones "
      "under yer feet.  An unlit lantern hangs on a light post on "
      "the south western side of the street.  To the east a building "
      "on the northern side of the street looks like a library, and "
      "a large stone building on the south side of the road looks like "
      "an Inn.  The large gates of the %^BOLD%^Black Dagger Arena "
"%^RESET%^%^ORANGE%^to the north look massive even "
"from a block away. An "
      "unnamed dirt road that separates the barracks from the Inn "
      "heads off to the south.\n");
    add_exit("nr1", "west");
    add_exit("nr3", "east");
    add_exit("p14", "south");
    add_exit("ar2", "north");

set_listen("default", "Sounds of batter are heard in the distance "
"to the north.\n");

}
