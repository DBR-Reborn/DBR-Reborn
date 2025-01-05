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
add_exit("tun2", "east");
     set_short("The demon Tavern");
  set("long",
"The Demon Tavern is a large room with several "
  "benches and tables and a bar at the back of the room.  "
  "The room is lit by a few lanterns which hang from the "
"walls.  Several demons and other things mill about "
"drinking and eating.  I would not cause any trouble "
"in here if I were you.  There is a menu on the wall.\n");
    set_items(
        (["benches":"They are sturdy and are fashioned of wood.",
"menu":(: call_other, this_object(), "read", "menu" :),

	  "lanterns" : "They are high-quality, but sadly, they look permanently attached.",
     "demons" : "Several look as though they've had a few too many." ]) );
}

void reset() {
  ::reset();
     if(!present("nezzit"))
     new("/wizards/sinclair/gorge/monster/nezzit")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

   if(!str) return 0;
    if(lower_case(str) != "menu") return notify_fail("There is no '"+str+"' here.\n");
     ob = present("nezzit");
    if(!ob) {
	write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
     write("The following great foods are served here at the Demon Restaurant.\n");
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

