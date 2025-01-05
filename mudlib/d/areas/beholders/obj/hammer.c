#include <std.h>
#include "../a1.h"
inherit WEAPON;
create() {
    ::create();
    set_id(({ "hammer", }));
    set_name("hammer");
    set_short("hammer");
    set("long", "Many Battle-Brothers balance the clumsy nature of attempting to parry with a Thunder Hammer by pairing it with a Storm Shield which is surrounded by a glowing blue field of protective energy which emits crackling lightning when the Space Marine parries the blow. ");
    set_weight(1000);
    set_value(150);
    set_wc(15, "cutting");
    //set_wc(15, "crushing");
    set_ac(3);
    set_quality(6);
    set_type("blunt");
    set_verb("bash");
    set_wield((: call_other, this_object(), "check_undead" :));
    return;
}

int check_undead() {

  if((string)this_player()->query_race() != "undead") {

    write("%^ORANGE%^This weapon can only be wielded by the templars of doom.%^RESET%^");
	remove();
    return 0;
  }
return 1;
}

