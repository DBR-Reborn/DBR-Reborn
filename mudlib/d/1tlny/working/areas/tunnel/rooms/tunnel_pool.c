//          Wizard: Delsius
//          tunnel_dome
//          May 97

#include <std.h>
#include "/wizards/delsius/defs/defs.h"
#include <def.h>
inherit ROOM;

object *players;
int statue_found;

void init() {
   ::init();
   add_action("fun_jump","jump");
}

int fun_jump(string str) {
   if(!str) return notify_fail("Jump to where?\n");
   if(str != "in pool")
      return notify_fail("You can't jump into that fool!\n");
   if(str == "in pool") {
      message("info","%^BOLD%^%^CYAN%^You dive into the pool with no regards for your life.%^RESET%^",
        TP);
      message("info","%^BOLD%^CYAN%^"+TPQCN+" dives into the pool with no regards for "+TP->query_possessive()+" life.%^RESET%^",ENV(TP),TP);
      TP->move_player(TUN_ROOMS+"tunnel_water","pool");
   }
}
void create() {
     ::create();
     set_property("indoors",1);
     set_property("light",-1);
     set("short", "Dome-shaped Room");
     set("long", "You are standing in a dimly lit dome-shaped "
                  "room.  Water drips from a small opening in the "
                  "ceiling into a rather large pool in the center of the "
                  "room.  The dripping of the water is amplified "
                  "immensely due to the room's acoustics.  A dark "
                 "shadow is cast just above the exit to the east.");
     set_smell("default", "You smell the decay of flesh and mildew in "
               "the air.");
     set_listen("default", "You hear the sounds of water dripping.");
     set_items(([ ({"room","area"}): "It's a dome-shaped room.",
                    "dome": "The dome portion of this room is raised a "
                    "good 25 meters above the ground.  The shape of the "
                    "dome causes the simplest sounds to be greatly "
                    "amplified.  Upon careful observation, you notice "
                    "some type of symbols etched in the surface.",
                  ({"symbol","symbols","surface"}): "You squint your "
                    "eyes to get a better look at the odd symbols on the "
                    "dome surface but your efforts are of no avail.  "
                    "However, you DO manage to make out a rather odd "
                    "word: eutats.",
                    "pool": "The small pool of water is circular and "
                    "about 10' in diameter.  The water within swirls "
                    "viciously forming a whirlpool on the surface.  "
                    "Judging by the way it looks, it's undertow must "
                    "be tremendous.  You peer into the water but it's "
                    "depth is unknown.  It wouldn't be a good idea to "
                      "jump in unless you are prepared to %^BOLD%^%^RED%^DIE%^RESET%^.",
                   "shadow": "The shadowy figure appears to be that of a rock "
                    "sculpture of some type.",
                    "opening": "The small opening allows a few drops of "
                    "water to fall almost rhythmically.",
                  ({"sculpture", "figure", "shadowy figure"}):
                    (:call_other,this_object(),"exa_statue":)]));
     set_exits((["east":TUN_ROOMS+"tunnel_30"]));
     add_pre_exit_function("east","release_statue");  
}


int exa_statue() 
{
  if(!present("statue") && statue_found)
  {
    message("info", "The statue seems to be in ruins.", this_player());
    message("info", this_player()->query_cap_name()+" examines the "
            "statue.", environment(this_player()), ({this_player()}) );  
     return 1;
  }
  message("info",this_player()->query_cap_name()+" examines the statue.",
              environment(this_player()), ({this_player()}) );  
  message("info", "The huge sculpture rests on an indentation in the " 
                  "wall just above the exit. It's age is apparent for " 
                  "it bears numerous cracks and imperfections.  It " 
                  "almost seems like the slightest touch or sound "   
                  "would cause it to crumble.", this_player());
// message after examining....
  message("info",
          "%^BOLD%^%^MAGENTA%^As you step closer to the statue, you notice it "
          "moves slightly.%^RESET%^", this_player());
  message("info",
          "%^MAGENTA%^As "+TPQCN+" steps closer to the statue, you notice it "
          "moves slightly.%^RESET%^",ENV(TP), TP);
  if(member_array(this_player(), players) == -1)
    players += ({ this_player() });
  return 1;
}

int release_statue() {
   if(!present("statue") && 
     (member_array(this_player(), players) != -1) && !statue_found) {
      new(TUN_MON+"statue")->move(this_object());
      message("info","%^BOLD%^%^YELLOW%^Suddenly, the statue hops down "
              "from above the doorway and blocks your exit to the "
              "east.%^RESET%^",environment(this_player()));
      statue_found = 1;
      return 0;
   }
   if(present("statue"))
   {
     message("info", "The statue blocks your way.", this_player());
     return 0;
   }
   return 1;
}

void reset()
{
  ::reset();
  statue_found = 0;
  players = ({});
}
