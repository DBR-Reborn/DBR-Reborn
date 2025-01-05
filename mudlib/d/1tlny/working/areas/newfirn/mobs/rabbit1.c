//Wizard:  Gellor
//Desc.:   A Rabbit
//File:    rabbit1.c
#include <std.h>
inherit MONSTER;
create() {
    ::create();
    set_name("rabbit");
    set_id("rabbit");
    set_short("A small grey rabbit");
    set_long("This is a cute little furry rabbit.");
    set_level(1);
    set_body_type("quadruped");
    set("race", "rabbit");
    set_skill("melee", 20);
    set_skill("dodge", 25);
    set_stats("strength", 10);
    set_stats("intelligence", 5);
    set_stats("dexterity", 40);
    set_stats("constitution", 20);
    set_stats("charisma", 5);
    set_stats("wisdom", 5);
    set_gender("male");
    set_emotes(5, ({"The grey rabbit itches its neck with its leg.",
    					  "The grey rabbit nibbles at some grass.",
                    "The grey rabbit sniffs the air attentively."}) );
    set_moving(3);
    set_speed(10);
}
