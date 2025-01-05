#include "../daybreak.h"
inherit "std/room";

void create() {
   ::create();
     set_property("light",3);
     set_property("night light", 2);
     add_exit(ROOM+"ridge5", "north");
     add_exit(ROOM+"square","south");
     set("short","Ridge Avenue");
     set("long","After the great war Daybreak Ridge was never completely rebuilt, perhaps because those in charge decided that it should be let as a stark reminder of what happened here, or perhaps it was due to lack of money, noone really knows.  The buildings here have been patched up, quite poorly in fact, some are missing parts of their rooves or even the whole roof itself, it is certainly a strange contrast from the rest of town which is so well maintained it is difficult to even spot any dirt.  To the north the town seems to get more and more desolate, while to the south you can see the fountain in the square as well as the market district.");
}
