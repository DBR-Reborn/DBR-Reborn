//  Wizard:  Khojem
//  Fir'nvillee Rock
//  rock.c
//  Altered by Tailwind for the Obstacle Course.
 
#include <std.h>
#include "../descent.h"

inherit OBJECT;
 
void create() {
  ::create();
    set_name("crystal");
    set_id( ({ "shiny crystal", "crystal" }) );
    set_short("a shiny crystal");
    set_long("You're not sure what this crystal is made of. It seems to have all the colors of the rainbow at once. You're sure it is quite valuable.");
    set_weight(1);
    set_value(1000);
}
