#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 1);
    set( "short", "Behind the Clock's Face" );
    set( "long", @EndText
    You stand directly behind the clock's face looking out
through the dimmly shadeded glass. You can see the large
hands rotating, powered by the large gears all throughout
the tower. You stand at the top of the stairs. It is strongly
advised you do %^RED%^NOT%^RESET%^ jump.
EndText
);
     set_exits( ({ PATH+"clock3.c" }), ({ "down" }) );
}

void init()
{
    add_action( "jump", "jump" );
}
    
int jump()
{
    write("%^YELLOW%^You leap from the tower! Life must really suck pal.%^RESET%^\n");
    this_player()->move( PATH+"clock.c" );
    write( "%^RED%^You leap from the clock tower, smashing through the face landing with a SPLAT on the hard street.%^RESET%^ ");
     this_player()->add_hp(-500);
     environment(this_player(message("blah")));
     return 1;
}
