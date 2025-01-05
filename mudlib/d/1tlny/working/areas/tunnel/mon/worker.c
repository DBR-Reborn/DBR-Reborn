//          Wizard: Delsius
//          worker
//          June 97

#include <std.h>
inherit MONSTER;

create () {
   string var;
   ::create();
   set_name("tunnel worker");
   set_id(({"gnome","tunnel worker","worker"}));
   set("race","gnome");
   set_short("A tunnel worker");
   set_long("Tunneling his way through these winding passageways and "
            "corridors, this worker peers over his shoulder with "
            "anxiety.  His eyes are filled with sheer terror as he "
            "surveys the area for other centipedes and spiders.");
   set_gender("male");
   set_level(15);
   set_hp(750);
   set_max_hp(750);
   set("gang bang", 0);
   set_body_type("human");
   set_languages(({"common"}));
   set_emotes(5, ({"The worker steps back and surveys his work.",
                   "The worker wipes sweat from his brow and continues "
                   "to work.",
                   "The worker sits down and rests his weary bones."}));
   set_speech(5, ({"Have you seen any centipedes or spiders?",
                   "A few of my comrades were attacked by some creatures "
                   "in these tunnels, unfortuantely they didn't survive.",
                   "Beware the area far to the north, horrid creatures "
                   "roam that area."}));
}
