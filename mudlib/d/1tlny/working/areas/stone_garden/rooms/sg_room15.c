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
      set("short", "Dead end.");
  set("long", "You find your passage in this direction blocked by a huge stone wall. It is slightly overgrown and has a few scratches on its face. ");


   add_item("Podium","There is a small podium here, with an ugly statue on it.");
  add_item("statue","The statue is of a huge Gargoyle, with its wings outstretched. Its face has a mischevious and evil look on its face, and you wonder if you havent seen it somewhere before...");
  add_item("scratches","You examine the scratches on the wall. It seems as if someone of something has clawed marks into the solid stone wall.");

  add_item("gargoyle","The gargoyle seems to be looking at you. It may just be the reflection of light on the statue, but something about it makes you very nervous.");

  add_exit("sg_room14","west");
}


  void reset() {
   
    ::reset();
    seteuid(geteuid());
   if(!query_night()) {
       new(MON_PATH+"caretaker")->move(this_object());
}
   if(query_night()) {
   new(MON_PATH+"gargoyle2")->move(this_object());
   add_item("statue","There is no statue here!");
    add_item("podium","It is a highly polished marble statue. It doesnt appear to have anything on it.");
  add_item("podium","The podium is a small white podium. It has an indentation on the top, as if something very heavy was resting on it at one stage.");
     }
   }

