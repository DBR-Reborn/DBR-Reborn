//          Wizard: Delsius
//          fire_golem
//          May 97

#include <std.h>
inherit MONSTER;

create () {
     ::create();
     set_name("fire golem");
     set_id( ({"golem","fire golem"}) );
     set("race", "golem");
     set_short("A fire golem");
     set_long("Flames totally engulf this enchanted creature.  His "
              "coal black eyes stare right through you making your skin "
              "crawl.  Just standing near this guy gives a new definition "
              "to the word hell.");
     set_level(19);
     set_max_hp(2500);
     set_hp(2500);
     set_max_mp(3000);
     set_mp(3000);
     set_property("base mp regen",150);
     set_property("base hp regen", 100);
     set_gender("male");
     set_body_type("golem");
     set_property("melee damage", (["fire" : 30]));

     set_overall_ac(25);
     set_skill("melee",125);
     set_skill("dodge", 125);
     set_skill("parry", 100);
     set_stats("strength", 200);
     set_stats("dexterity", 175);

}
