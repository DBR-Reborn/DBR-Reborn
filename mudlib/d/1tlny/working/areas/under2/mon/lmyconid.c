// Little myconid
// Vishnu Mob

#include <std.h>

inherit MONSTER;

void create() {
    ::create();
   set_name("Little Myconid");
    set("id", ({"myconid", "little myconid", "mushroom"}) );
    set_level(5+random(3));
    set("short", "Little Myconid");
    set("long",
    "The little mushroom stands about waist high to you.  His little "
    "cap glistens with sweat from his heavy playing.  Little myconids "
    "love to play with eachother.  This one really seems happy. "
    );
    set("race", "myconid");
    set_gender("neuter");
    set_combat_chance(50);
    set_body_type("human");
    set_wielding_limbs( ({"right hand"}) );
    set_emotes(5,
          ({
          "The Little myconid motions you to play with him.",
       "The Little Myconid trys to push you over, playfully.",
       "The little Myconid jumps around."
     }), 0);
}
