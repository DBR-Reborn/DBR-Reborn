//          Wizard: Delsius
//          rubble
//          Jul 97
 
#include <std.h>

inherit OBJECT;

void create() {
     ::create();
     set_name("rubble");
     set_id(({"rubble","dust","ruins","pile"}));
     set_short("Pile of dust and rubble");
     set_long("This pile of dust and rubble is the remains of what "
              "used to be a massive rock statue.");
     set_weight(50);
     set_value(0);
}
