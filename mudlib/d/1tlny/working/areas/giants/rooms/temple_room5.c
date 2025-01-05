//      Wizard:  Deorwin
//      K'az-ra's temple
//      temple_room5.c

#include <std.h>
#include <def.h>
#include "giants_paths.h"
inherit VAULT;

int tomb_found;

void reset(){
  if(tomb_found) tomb_found=0;
  if(query_open("tomb")) {
    set_open("tomb",0);
    find_object_or_load(ROOMS_PATH+"tomb1")->set_open("tomb",0);
    add_invis_exit("down");
  }
}

void create() {
    ::create();
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "The Inner Temple Chamber, By The Large Statue");
    set("long",@EndText
You are now at what seems to be the centre of the entire
temple. An enormous statue is towering against the northern
wall. Light from various sources all shine upon the statue,
enshrouding the room in billions of different colours and
shades. The floor is made out of prefectly rectangular stone
bricks. On the walls all around the room are different paint-
ings, showing episodes from K'az-ra's legendary life.
EndText
);
    set_search("floor",(: call_other, this_object(),"do_search" :));
    add_item("floor",(: call_other, this_object(), "look_at_floor" :));
    add_item("brick",(: call_other, this_object(), "look_at_floor" :));
    add_item("stone brick",(: call_other, this_object(), "look_at_floor"
:));
    add_item("paintings",
"Paintings showing different episodes from K'az-ra's life can be
seen on the temple walls. You can not make out the exact motives
from here though, you will have to move closer to the eastern or
western wall.");
    add_item("statue",
"This is a huge statue portraiting the great legendary storm-giant
warrior K'az-ra. He was the founder of this temple and of the Holy
Order. K'az-ra wears a shining black armour, and wields a huge dark
sword. The helm he is wearing hides most of his face, but you see
a faint glitter from his eyes, as if there was a burning fire in
them.");
    add_item("light",
"Light of numerous different shades reflect off the statue and fills
the room.");
    tomb_found = 0;
     set_exits( ({ ROOMS_PATH+"temple_room4", ROOMS_PATH+"temple_room2",
ROOMS_PATH+"temple_room6" }), ({ "west", "south", "east" }) );

}

void look_at_floor() {
  if(!tomb_found) return 0;
  if(query_open("tomb"))
    write(
"The large stone brick that once covered the entrance to the tomb
is open, revealing a tunnel under the floor!");
  else
    write(
"The loose brick on the floor is in place, covering the secrets
below. Maybe you can 'open' the tomb?");
  say(TPQCN+" carefully examines the loose brick on the temple floor. \n");
}

int do_tomb_open() {
  int stre;
  if(!tomb_found) return 0;
  stre=((int)this_player()->query_stat("strength"));
  if(!(this_player()->query_stats("strength") <= 125))
     {
     write(
"Your muscles bulge as you use every ounce of strength in your body
to push the loose stone brick aside, a tunnel is uncovered!");
     remove_invis_exit("down");
     find_object_or_load(ROOMS_PATH+"tomb1")->remove_invis_exit("up");
     say(this_player()->query_cap_name()+" uses every muscle in his body to
push the stone brick aside! \n");
     return 1;
     } else
        {
        write(
"You focus your strength and try to push the stone brick aside,
but to no use, the huge rock just wont move.");
        say(this_player()->query_cap_name()+" struggles hard to push the
stone brick aside, but fails! \n");
        return 0;
        }

}

int do_tomb_close() {
  if(!tomb_found) return 0;
  add_invis_exit("down");
  find_object_or_load(ROOMS_PATH+"tomb1")->add_invis_exit("up");
  write(
"You push the stone brick in place easily. The tunnel is covered again.");
  say(this_player()->query_cap_name()+" seals the tunnel shut by moving the
brick in
place. \n");
  return 1;
}

void do_search() {
  int skill;
  say(this_player()->query_cap_name()+" appears to be searching the
floor.\n");
  skill=((int)this_player()->query_skill("perception"));
  if(skill>(80+random(15))){
    write(
"You search the floor and find that one of the stone bricks can
be moved!");
    add_exit(ROOMS_PATH+"tomb1","down");
    set_door("tomb",ROOMS_PATH+"tomb1","down",0);
    set_func("tomb","open","do_tomb_open");
    set_func("tomb","close","do_tomb_close");
    tomb_found=1;
  }
  else
    write("Your search yields nothing.");
  return;
}

