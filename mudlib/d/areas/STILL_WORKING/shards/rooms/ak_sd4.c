#include "../shards.h"
inherit "std/room";

void reset() {
        ::reset();
        if(!present("demon"))
  new(MON+"demon")->move(this_object());
        }

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_egate", "south");
//    add_exit("/d/damned/guilds/join_rooms/tinker_join", "west");
    set("short","A Trail of Blood");
    set("long","This street probably had some guild houses on it at one point, but apparently, whatever hit this city took care of those pretty well. The way north is so covered in rubble that you can't even go that way. South of you are the eastern gates to the city.");
}
