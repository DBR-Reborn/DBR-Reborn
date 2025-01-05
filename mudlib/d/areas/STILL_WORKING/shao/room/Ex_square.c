#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
set("short", "Exectution Square");
set("night long","%^RESET%^A few rays of moon "
"light catch "
      "the razor sharp blade edges of the "
      "guillotine causing the hair on the back of even the bravest "
      "of mortals neck to stand on end.  "
      "The shops that stand on the four corners of this square "
      "look dark inside, and appear to be closed for the night.  "
      "Southern Row runs east and west from here, and 1st street runs "
      "north and south.\n");
set("day long", "%^RESET%^%^ORANGE%^Your standing "
"in %^RED%^Exectution %^RESET%^%^ORANGE%^Square.\n"
"The notorious guillotine of Shao-tan sits in the center.\n"
"The "
      "amount of dried blood stains under it and on the cobblestones around "
      "it is stomach wrenching. "
      "Various shops and stores stand on the four corners of this square "
      "To the northwest is a weapons shop, to the northeast is an armour shop "
      "and to the southwest and southeast the clothing store and "
      "general store "
      "are located.\n"
      "Southern Row runs east and west from here, and 1st street runs north "
      "and south.\n");
    add_exit("sr5","west");
    add_exit("sr6","east");
    add_exit("1st6","south");
    add_exit("1st8","north");

}
