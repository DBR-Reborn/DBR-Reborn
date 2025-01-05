#include <std.h>
#include "../a1.h"
inherit WEAPON;
create() {
    ::create();
    set_id(({ "knife", }));
    set_name("knife");
    set_short("knife");
    set("long", "A Templar Knife is a scary weapon");
    set_weight(1000);
    set_value(150);
    set_wc(15, "cutting");
    //set_wc(15, "crushing");
    set_ac(3);
    set_quality(6);
    set_type("knife");
    set_verb("cut");
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

