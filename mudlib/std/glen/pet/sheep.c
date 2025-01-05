#include <std.h>
inherit "/std/pet";

create() {
    ::create();
    set_name("sheep");
    set_id(({"sheep"}));
    set_class("thief");

    set("race", "sheep");
    set_short("Fluffy sheep");
    set_long("An omnipotent all powerfull sheep of doom.");
    set_body_type("quadruped");
    set_level(4);

    set_hp(5000);

    if(random(2))
	set_gender("male");
    else 
	set_gender("female");
}

