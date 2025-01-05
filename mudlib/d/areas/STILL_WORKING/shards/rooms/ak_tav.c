#include "../shards.h"
#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  add_exit(ROOMS+"ak_tavern2", "west");
  set_short("Broken Bars");
  set("long",
  "Judging from the many skeletons, tables, chairs, and shattered glasses lying around, it is quite probable that this was a bar at some point in time. You don't quite see where the bar itself is, but a menu does rest upon the wall still.");
    set_items(
        (["tables":"They are busted beyond repair.",
"menu": "You can barely read the menu, as it is splattered with ancient blood.",

	  "chairs" : "They're not exactly in shape to sit on.",
	  "patrons" : "Dead as hell, to be sure." ]) );
}

void reset() {
  ::reset();
    if(!present("crystal")) 
      new(OBJ+"bar_crystal")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

   if(!str) return 0;
    if(lower_case(str) != "menu") return notify_fail("There is no '"+str+"' here.\n");
    write("The following great foods are served here at the Last Dragon Restaurant.");
    write("--------------------------------------------------------------------");
write(sprintf("%30s %d silver", "A tankard of mead", (int)ob->get_price("mead")));
    write(sprintf("%30s %d silver", "A mug of ale", (int)ob->get_price("ale")));
    write(sprintf("%30s %d silver", "A shot of single malt whiskey", (int)ob->get_price("whiskey")));
    write(sprintf("%30s %d silver", "A loaf of bread", (int)ob->get_price("bread")));
    write(sprintf("%30s %d silver", "A leg of mutton", (int)ob->get_price("mutton")));
    write(sprintf("%30s %d silver", "A dragon steak", (int)ob->get_price("steak")));
    write("-----------------------------------------------------------");
    write("<buy item> gets you the food or drink.");
    return 1;
}

