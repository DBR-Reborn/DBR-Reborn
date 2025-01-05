//  Wizard: Shade Maelstorm
//  Area: Stone Garden
//  Theme: This is a stone garden, in which basilisks and other stoning
// creatures will play.

//  Monsters: The monsters will include caretakers, guards, gardeners, baby
//  basilisks, and other smaller insects, as well as some stone statues.

#include <std.h>
#include <stone_garden.h>

inherit ROOM;


void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
      set("short", "Inside Stone Garden");
  set("long","As you walk further into the park, you notice the number of statues that are in this garden. There are statues everywhere, all have one thing in common, hideously scared faces. You start to sense something is very wrong here, yet the overall appearance of the park, aside from the statues is one of a peaceful, tranquil place, of immense beauty. The path continues to the west and south here.");
 add_item("path","The path is made of closely tiled blocks of stone. The path itself is quite smooth, and also quite cold.");
 add_item("statues","There are many statues around, all hard as stone to the touch, and provide a stark contrast to the rest of this beautiful garden.");
 add_item("faces","The faces on the statues are one of extreme terror. Either the creators of these statues delighted in seeing others in pain, or something is decidely not what it seems.");
 add_item("face", "The face on this statue is just one of many, all have one thing in common, expressions of sheer terror are imprinted on the statues faces.");
  add_exit("sg_room3","west");
  add_exit("sg_room1","south");
}


 void reset(){
   ::reset();
   if(!present("caretaker"))
new(MON_PATH+"caretaker")->move(this_object());
   }

