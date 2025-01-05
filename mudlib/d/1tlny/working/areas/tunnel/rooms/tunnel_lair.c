//          Wizard: Delsius
//          tunnel_lair
//          May 97

#include <std.h>
#include "/wizards/delsius/defs/defs.h"
inherit ROOM;

void create() {
     ::create();
     set_property("indoors",1);
     set_property("light",2);
     set("short", "Throne Room");
     set("long", "You have entered what seems to be the heart of the "
                 "tunnel system.  Numerous carcasses and skeletons "
                 "are lying throughout the room.  The blood-stained "
                "walls and floor (not to mention the stench) cause a "
                 "sudden sense of nausea within you.  In the center "
                 "of this slaughterhouse rages a large fire.  Along "
                 "the opposite wall of this room, you notice a "
                 "gigantic throne and a huge spider web.");
     set_smell("default", "You smell the foul stench of death and smoke.");
     set_listen("default", "You hear something moaning and the "
                "crackling of a large fire.");
     set_items(([ ({"carcasses","carcass"}): "The gutted remains of "
                    "many species lay scattered around the floor.  "
                    "Some of these unfortunate adventurers have been "
                    "amputated while others are decapitated... the "
                    "outcome was still the same.  As you glance over "
                    "the remains, you notice a young man that is "
                    "barely clinging to life.",
                  ({"young man","man"}): "The man peers up at your with "
                    "terror in his eyes.  He coughs a few times then "
                    "says, 'Beware the web...' before finally resting "
                    "in peace.",
                  ({"skeleton","skeletons"}):  "The skeletal remains "
                    "of various species are strewn about.  Wonder what "
                    "brought about their demise?",
                  ({"walls","wall"}): "The walls are literally painted in "
                    "blood.",
                  ({"floor","ground"}): "Small puddles of blood are "
                    "everywhere.  Various scuff marks are made on the "
                    "ground indicating a struggle of some type.",
                    "blood": "It's normal %^RED%^blood%^RESET%^ and "
                    "it's everywhere!",
                      "fire": "The fire blazes brightly and warms the "
                    "air around you.  As you stare at the hypnotic "
                    "flames, you think you see something in there.",
                    "throne": "A gigantic throne rests along the "
                    "southern wall.  It's apparent that whoever or "
                    "whatever sits there is HUGE!",
                  ({"spider web","web"}): "The spider web extends from "
                    "the ground all the way to the ceiling.  It's "
                    "strands glisten from the light of the fire and "
                    "vibrate sparingly.  If a spider has made this "
                    "place it's home, I definitely wouldn't want to "
                    "confront it."]));
     set_exits((["north":TUN_ROOMS+"tunnel_05"]));
}
void init() {
   ::init();
   add_action("search_fire","search");
}
int search_fire(string str) {
   if(!str) {
     notify_fail("Search for what?\n");
     return 0;
   }
   if(str != "fire") {
     notify_fail("There is nothing of importance there!\n");
     return 0;
   }
   write("%^YELLOW%^You search around the fire and singe your arm in the process... YEOW!%^RESET%^");
     say(this_player()->query_cap_name()+" gets too close to the fire and gets burned!", this_player());
   this_player()->add_hp(-10);
   return 1;
}
