#include <std.h>

inherit MONSTER;

int levelrange=random(2);

create() {
    ::create();
    set_name("demon");
    set_id( ({"demon"}));
    set("race", "demon");
    set_body_type("winged-humanoid");
    set_short("A lil demon");
    set_long("This demon is not so old by demon standards, probably only 500
years or so, you can tell. Still, he is a tough-looking bastard, with big
sharp teeth, red skin, and claws that could probably rip you to bits. Seven
feet of killing machine, to summarize.");
}

