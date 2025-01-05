// wiztower   10    //
// Coded by Glitch  //
// xx-xx-00         //
// for DBR          //
//////////////////////

#include <std.h>
#include "../wiztower.h"

inherit "/std/room";

void create() {
   ::create();
   set_property("indoors", 1);
   set_property("light", 1);
   set("short", "Inner Sanctum.");
   set("long", "The wizards inner sanctum seems to pulse with hidden power. The sanctum is filled with various items of archane lore. Books and tombs line the shelves. Several Greater Familiars stand ready to defend their master.");
   add_exit(ROOMS+"wiztower7","down");
   set_items( ([ ({"sanctum", "inner sanctum" }) : "This is where the wizard does his studying and spell casting.",
      ({ "power", "hidden power" }) : "The room seems to be filled with power. It's more of an electric feeling than anything visable.",
      ({ "items", "items of archane lore" }) : "Beakers, jars, crystal balls, wands etc.",
      ({ "beaker", "beakers" }) : "It's filled with a bubbling liquid.",
      ({ "liquid", "bubbling liquid" }) : "A light blue liquid. You've no clue what it is or what it does.",
      ({ "jar", "jars" }) : "They are filled with various substances.",
      ({ "crystal ball", "crystal balls" }) : "The balls are very clear and show nothing at the moment.",
      ({ "books", "tomes" }) : "These books are the meat of any spell casters library.",
      ({ "library" }) : "So many books line the shelves that you could consider this a library.",
      ({ "familiars", "greater familiars", "familiar" }) : "Perhaps you should examine them.",
      ]) );
   new(MOBS+"agulz")->move(this_object());
}

