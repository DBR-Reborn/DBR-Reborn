//  Wizard:  Shade Maelstorm
// A beautiful rose
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("wild rose");
 set_id( ({ "wild rose" }) );
set_short("%^GREEN%^wild %^RED%^rose"%^RESET%^");
set_long("This is a beautiful wild rose, many a maiden would swoon over such a gift.");
    set_weight(20);
    set_value(5);
}

