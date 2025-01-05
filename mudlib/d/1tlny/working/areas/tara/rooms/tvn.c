inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

void init() {
  ::init();
   add_action("read", "read");
}

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",2);
   set_property("indoors", 1);
   set_short("Tara's Tavern");
   set("day long", @DAY
The building looks bigger from the outside.  It if packed full
of sweaty drunk halfling bodies, everyone crowded as close to the bar
as they can get.  Although it is crowed, the people seem to be
having a good time, eating, drinking, singing, and just relaxing
while they are not out working.  Bergin keeps his place clean,
the bar is spotless, and the tables close to it.  Pretty halfling
serving wenches bring food and drink to those waiting.
DAY
);
   set("night long", @NIGHT
The tavern is well lit with torches, Bergin making sure not
to scare off his late customers with darkness.  The tavern
is not as crowded as it is during the day, but there are enough customers
to make it worth while to Bergin to keep it open at night.  Some
of the hard core alcoholics lie slumped down against the bar,
prefering to pass out here then their own homes.  Most of the
wenches have gone to bed, leaving Bergin to tend the bar alone.
NIGHT
);
   add_item("menu","Try reading it.");
   add_item("halflings","They sit here drinking and eating.");
   add_item("bar","The bar is clean and shiny, many halflings sit "+
   "next to it.");
   add_item("building","One of the few buildings not built into the "+
   "hillside, it looks much bigger from the outside.");
   add_item("wenches","Pretty well filled out halfling wenches, "+
   "who's job is not only to serve food, but attract customers.");
   add_item("tables","Many tables for halflings to enjoy there "+
   "food and drink.");
   add_item("torches","Bergin pays for torches to keep the inside "+
   "and outside of the tavern well lit all night.");
   add_item("alcoholics","People who enjoy life more then you.");
   set_smell("default","The air smells of ale and stew.");
   set_listen("default","The sound of a bustline Tavern fills the air.");
   add_exit(TARAROOMS+"rm5", "west");
}

void reset() {
  ::reset();
    if(!present("bergin")) 
    new(TARAMON+"bergin")->move(this_object());
}

int read(string str) {
   object ob;
   int i;

   if(!str) return 0;
if(lower_case(str) != "menu") return notify_fail("There is no '"+str+"' here.\n");
    ob = present("bergin");
    if(!ob) {
  write("That's not a menu.  That's Bergin's will!");
  return 1;
    }
    write("Bergin serves the following beverages and foods.");

write("-----------------------------------------------------------");
write(sprintf("%30s %d silver", "A bowl of stew",
(int)ob->get_price("stew")));
    write(sprintf("%30s %d silver", "A mug of ale",
(int)ob->get_price("ale")));
    write(sprintf("%30s %d silver", "A glass of wine",
(int)ob->get_price("wine")));
    write(sprintf("%30s %d silver", "A large portion of beef",
(int)ob->get_price("beef")));
    write(sprintf("%30s %d silver", "A shot of tequila",
(int)ob->get_price("tequila")));
    write(sprintf("%30s %d silver", "A chunk of cheese",
(int)ob->get_price("cheese")));
    write("-----------------------------------------------------------");
    write("<buy item> gets you the food or drink.");
    return 1;
}
