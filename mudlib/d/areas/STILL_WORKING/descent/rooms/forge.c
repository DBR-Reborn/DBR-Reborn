#include "../descent.h"
inherit "/std/room";
void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"furnace", "west");
   add_exit(ROOMS+"road4", "east");
   set("short","The Forge");
   set("long", "This room is where the Gnomish tinkers hammer away at their weapon and armour blanks in order to make their incredible wares. The forge in the middle of the room is free for all to use. To your west is a massive furnace.");
}
void reset() {
object forge;
::reset();
if(!present("forge")) {
forge = new("/wizards/diewarzau/obj/misc/greater_forge_perm");
forge->set_weight(25000);
forge->move(this_object());
}
if(!present("can")) {
    new("/d/damned/guilds/join_rooms/tcan")->move(this_object());
}

}
