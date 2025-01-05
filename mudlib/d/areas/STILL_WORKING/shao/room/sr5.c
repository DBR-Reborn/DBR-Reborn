#include <shao.h>
inherit "std/vault";


void create() {
  ::create();
    set_property("light",2);
    set_property("night light", 1);
add_exit(PATH+"sr4","west");
add_exit(PATH+"Ex_square","east");
set_door("south door", PATH+"cloth_shop","south",
"cloth shop");
	  set_open("south door", 1);
	  set_locked("south door", 0);
          set_open_function("open_door", "5:00:00");
    set_close_function("close_door", "16:30:00");
add_exit(PATH+"cloth_shop","south");
set_items(([
"door": "It looks quite sturdy", "south door":
"it looks quite sturdy.",
"building": "There are three of them that you can see...\n"+
"One directly north, one on southwest corner, "
"and one directly south of you...\n"]));
set("short","Southern Row");
set("night long","%^RESET%^A street lantern "
"baths this "
"section of the road with a dim yellow light.  "
"Looking to the north and south of where you stand, "
"you see two buildings, since this is the busness "
"district you assume they are shops of some sort. "
"The northern building isn't facing you, but you notice "
"that the building to the south is pitch black inside. "
"Looking down the street to the east you see what looks "
"like a massive blade in the infamous Execution square. "
"You can't see much to the west, it's too dark.\n");
set("day long", "%^RESET%^%^ORANGE%^The "
"cobble stoned road feels warm under "
"your feet.  To the south you see what looks like a "
"shop of some sort, a sign is hanging over the entrance "
"to it. "
"Another building is to the north, but from here all"
" you can see is one of its large stone walls, "
"it must face some other road.  To the east is Execution "
"square.\n"
"\n"
"A street sign reads : %^RED%^<--== Southern Row ==-->"
"\n");
    return;
}

void close_door() {
call_other(PATH+"cloth_shop","close_door");
  return;
}

void open_door() {
call_other(PATH+"cloth_shop","open_door");
  return;
}

