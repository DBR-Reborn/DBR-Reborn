#include <std.h>
#include "../a1.h"
inherit WEAPON;
create() {
    ::create();
    set_id(({ "axe", "choppa" }));
    set_name("axe");
    set_short("choppa");
    set("long", "Orks use a bewildering variety of bladed, spiked, jagged, serrated, barbed and notched weapons in close combat. Large, heavy and deadly in Ork hands, they usually look like an axe or a broad knife, but can take almost any form - from massive cleavers to huge rusty pipes equipped with additional spikes for extra damage. Not really choosy, Orks consider anything they can cut their enemies to pieces with as a choppa.");
    set_weight(1000);
    set_value(150);
    set_wc(15, "cutting");
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

