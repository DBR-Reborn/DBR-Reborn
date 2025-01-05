#include <std.h>
#include "../a1.h"
inherit WEAPON;
create() {
    ::create();
    set_id(({ "axe", "choppa" }));
    set_name("axe");
    set_short("choppa");
    set("long", "Slugga is a huge high-calibre semi-automatic projectile firearm, usually fed from a hopper or clip of ammo. It is often crude, loud and brutish in design and designed to be used in a similar way. Sluggas have very limited accuracy, but huge stopping power, thanks to the massive shot they fire and dangerously large powder charges that propel them.");
    set_weight(300);
    set_value(150);
    set_wc(15, "impaling");
    //set_wc(15, "crushing");
    set_ac(3);
    set_quality(6);
    set_type("axe");
    set_verb("chop");
    set_wield((: call_other, this_object(), "check_ork" :));
    return;
}

int check_ork() {

  if((string)this_player()->query_race() != "ork") {

    write("%^ORANGE%^The weapon is beyond your ability to comprehend you decide to throw it in the trash.%^RESET%^");
	remove();
    return 0;
  }
return 1;
}

