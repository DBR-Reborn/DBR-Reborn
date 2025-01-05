#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("soul crystal");
    set_id(({ "crystal", "soul crystal", "nethermancer crystal", "molding crystal", "mold crystal" }));
    set_short("A soul crystal");
    set_long("This is a relatively large and shiny crystal, shaped like a perfect diamond and as clear as pure water. Contained within the glass you see three swirling souls moving about giving off a powerful stream of energy that seems to energize the object, making it feel terribly warm in your hands. A Nethermancer can magically mold this crystal into a powerful weapon of soulwood or a robe of soulhide, complete with the essences of the souls inside of it.");
    set_weight(75);
    set_value(1000);
    return;
}
