//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn35.c
#include <std.h>
inherit VAULT;
void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "East Of Market");
    set("long", "You stand just east of the famous Market! Overflow "
    				 "traffic and merchants sometimes stand here to conduct "
                "business and organize their property. The road here "
                "has recently been covered with cobblestones to support "
                "the traffic and provide a solid surface for all things. "
                "Further to the east you can see the renowned Verdes "
                "Statue Fountain!" );
    add_exit("newfirn47.c", "west");
    add_exit("newfirn36.c", "east");
    set_items(([
     ({ "market","fountain" }) :
        "Go there and look at it!",
     ({ "road","cobblestones" }) :
        "Due to the sometimes heavy amount of traffic, trading and "
        "other commerce here in New Firn'Ville, the road here and "
        "in the Market has been covered with beautiful cobblestones "
        "of various colors. They are large, probably eight inches a "
        "side each, and have rounded surfaces. A redish-gray mortar "
        "fills the cracks." ]));
    set_smell("default", "The air is a cornucopia of scents.");
    set_listen("default", "You can hear all sorts of chatter and "
    							  "undefinible noises.");
}
