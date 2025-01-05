#include <std.h>
#include "../a1.h"
inherit WEAPON;
create() {
    ::create();
    set_id(({ "axe", }));
    set_name("axe");
    set_short("axe");
    set("long", "The blade has a large, warped cross-guard, adding just enough weight to make sure the blade sits firmly in the owner's hand and protecting those same hands as well. The cross-guard has a jeweled cross on each side, a clear sign this weapon belongs to a champion.");
    set_weight(1000);
    set_value(150);
    set_wc(15, "cutting");
    //set_wc(15, "crushing");
    set_ac(3);
    set_quality(6);
    set_type("axe");
    set_verb("chop");
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

