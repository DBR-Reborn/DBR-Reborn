
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The ladder to Savanah");
    set_long(  "\nThere is a rope ladder hanging down "
   "from the floating plateau looming over you. You tense, for it appears"
   " that at any moment, you will be crushed by the floating island. "
   "As you gaze at the breathtaking sight before you, you remember stories "
   "from your youth about Morodin and Balrog's eon long fight, and Morodin's"
   " desperate self sacrifice, which created the floating island."
    );
    set_exits( ({ "ladder.c", "/d/damned/akkad/ak_center.c" }),
      ({ "ladder", "leave" })
    );
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "Off in the distance, you can hear the "  
    "galloping of horses.");
     add_item("island", "This monstrosity of magic looms above you with menacing intent threatening to crush you at the slightest mistep. It obscures your view of the sun, casting a dreadful shadow on the land near it.");
     add_item("ladder", "This long rope ladder looks quite sturdy, but sways in the wind, with each little gust.");
  }
