#include <std.h>
inherit "/std/pet";

create() {
    ::create();
    set_name("elf");
    set_id(({"elf"}));
    set_class("thief");

    set("race", "aquatic-elf");
    set_short("%^GREEN%^" +
      "Little elf " + "%^RED%^" + "helper");
    set_long("This elf is adorned in green and red.  " +
      "He looks like he is ready to make christmas toys");
    set_level(1);
    set_body_type("human");

    set_max_hp(1);
    set_hp(1);
    set_gender("male");
}


