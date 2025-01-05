#include <std.h>

inherit MONSTER;

create() {
  ::create();
    set_name("mammoth");
    set_id( ({ "mammoth"}) );
    set("race", "mammoth");
    set_short("A mammoth");
    set_long("The mammoth is sort of like a furry elephant. The difference is, the elephant will usually run when attacked. This thing will trample you.");
    set_body_type("quadruped");
    set_level(10);
    set_stats("intelligence", 10);
    set_stats("dexterity", 90);
    set_speed(50);
    set_moving(1);
}
