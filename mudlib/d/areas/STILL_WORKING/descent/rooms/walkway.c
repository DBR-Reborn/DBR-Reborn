//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "On the walkway to the Elder's home.");
    set("long", "This peaceful path makes its way through the rocky grounds of the big house to the north of you. It is remarkable how the hustle and bustle to the east have not damaged this calm place.");
    add_exit(ROOMS+"ehouse", "north");
    add_exit(ROOMS+"road3", "east");
}
