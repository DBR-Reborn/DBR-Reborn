#include <std.h>

inherit MONSTER;

create() {
     ::create();
     set_name("spider king");
     set_id( ({"spider","king","spider king"}) );
     set("race", "Arachnid");
     set_short("The Spider King");
     set_long("This massive spider peers at you with his glowing "
     "red eyes.  He also appears to be the ruler of this area and his "
     "distaste for trespassers is obvious.");
     set_level(100);
     set_gender("male");
     set_body_type("arachnid");
     set_overall_ac(150);
     set_max_hp(75000);
     set_hp(75000);
}
