// wounded scout

#include <std.h>

inherit MONSTER;

create() {
  ::create();
    set_name("scout");
    set_id( ({ "scout", "elf" }) );
    set_short("A wounded elf");
    set("race", "wild-elf");
    set_gender("male");
    set_long("The frightened elf cowers in the corner as you approach.  "+
        "you notice he is a member of the 'Falcon Division'.  He has "+
        "large wounds that have been tied up with blood soaked "+
        "bandages.  He looks like he has something to say.");
    set_body_type("human");
    set_level(12);
    set_skill("melee", 40);
    set_skill("dodge", 70);
    set_skill("parry", 60);
    set_overall_ac(40);
    set_stats("strength", 130);
    set_stats("dexterity", 130);
    set_max_hp(1000);
    set_hp(1000);
    set_property("handedness", "right hand");
    new("/d/damned/virtual/broad-sword_3.weapon")-> 
      move(this_object());
    new("/d/damned/virtual/breast-plate.armour")->
      move(this_object());
    force_me("wield sword in right hand");
    force_me("wear plate");
   set_emotes(5, ({
                   "The elf whimpers: Please, don't hurt me!",
                   "The elf shivers.",
                   "The elf exlaims: We were set up, this was all a "+ 
                   "cruel test!",
                   "The elf says: A ranger from Eagle Division knew "+
                   "about this all along.  If you find him, give him "+
                   "my regards.",
                   }), 0);
}
