#include <std.h>
#include "../a1.h"
inherit WEAPON;
create() {
    ::create();
    set_id(({ "sword", }));
    set_name("sword");
    set_short("sword");
    set("long", "A fairly small, thick, smooth blade made of ivory is held by a grip wrapped in fairly common, dark brown deerskin. With just one razor-sharp edge this weapon is the perfect choice for slicing and dicing while also offering you a way to effectively block attacks.");
    set_weight(1000);
    set_value(150);
    set_wc(15, "cutting");
    //set_wc(15, "crushing");
    set_ac(3);
    set_quality(6);
    set_type("sword");
    set_verb("slash");
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

