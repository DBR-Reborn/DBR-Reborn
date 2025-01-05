
#include "../ruins.h"
#include <std.h>
inherit "std/vault";
 void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 1);
set_exits( ([
"north":ROOMS+"ruins2.c",
]) );
add_exit(WORLD+".world", "plains");
set("short", "Runes Of An Ancient City");
set("day long", "The Ruins Of An Ancient City. This is the entrance of the
Ancient City. There is a wall all around the city but at this point. There
is an archway built into the wall in which to enter the city with. The
ground is covered in grass. The grass has been flattened in the middle of
the entrance which shows that some one or some thing has walked throw the
grass recently. To the south there is a forest which surrounding the city.
The grass path continues north. There is a sign here cover with a glowing
light.");
set("night long", "The Ruins Of An Ancient City. This is the entrance of
the Ancient City. There is a wall all around the city but at this point.
There is an archway built into the wall in which to enter the city with.
The ground is covered in grass. The grass has been flattened in the middle
of the entrance which shows that some one or some thing has walked throw
the grass recently. To the south there is a forest which surrounding the
city. The grass path continues north. There is a sign here cover with a
glowing light.");
set_smell("default", "The cold wind feels like death on your skin");
set_listen("default", "It is extremely quiet.");
set_items(([
({ "sign" }) :
"%^BOLD%^%^MAGENTA%^_%^GREEN%^.:%^RED%^*%^WHITE%^~%^RED%^*%^GREEN%^:.%^MAGENTA%^_%^GREEN%^.:%^RED%^*%^WHITE%^~%^RED%^*%^GREEN%^:.%^MAGENTA%^_%^GREEN%^.:%^RED%^*%^WHITE%^~%^RED%^*%^GREEN%^:.%^MAGENTA%^_%^GREEN%^.:%^RED%^*%^WHITE%^~%^RED%^*%^GREEN%^:.%^MAGENTA%^_%^GREEN%^.:%^RED%^*%^WHITE%^~%^RED%^*%^GREEN%^:.%^MAGENTA%^_%^GREEN%^.:%^RED%^*%^WHITE%^~%^RED%^*%^GREEN%^:.%^MAGENTA%^_%^GREEN%^.:%^RED%^*%^WHITE%^~%^RED%^*%^GREEN%^:.%^MAGENTA%^_",
({ "arch", "archway", "enterence" }) : 
"The archway is cover in thick vines.",
({ "grass", "grass road", "road", "passage" }) :
"The grass has grown to one foot off the ground. The grass also has been
flattened in the middle of the entrance showing that some one or some thing
has walked on the grass recently."
]));
new(ITEM+"sign.c")->move(this_object());
}
