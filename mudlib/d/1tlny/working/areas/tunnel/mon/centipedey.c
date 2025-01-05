//          Wizard: Delsius
//          centipede
//          May 97

#include <std.h>
inherit MONSTER;

void init() {
   call_out("force_me",1,"kill worker");
   force_me("kill worker");
   ::init();
}
create () {
   string var;
   ::create();
   set_name("centipede");
   set_id( ({"centipede","worm"}) );
   set("race", "centipede");
   set_short("A large centipede");
   set_long("This worm-like creature is %^BOLD%^%^RED%^fiery red %^RESET%^with numerous "
            "%^BOLD%^%^BLUE%^blue %^RESET%^and %^BOLD%^%^YELLOW%^yellow%^RESET%^ spots adorning it's body.  Protruding "
            "from it's tough skin are 100 legs which compare to the "
            "size of your own.");
   set_level(16 + random(3));
   set_max_hp(1250);
   set_hp(1250);
   set_max_mp(1000);
   set_mp(1000);
   set_property("base mp regen", 75);
   set_property("base hp regen", 50);
   switch(random(2)) {
     case 0: var = "female"; break;
     case 1: var = "male"; break;
}
   set_gender(var);
   set_body_type("serpent");
   set_property("melee damage", (["crushing" : 25]));
   set_overall_ac(20);
   set_skill("melee", 100);
   set("gang bang", 0);
   set_skill("parry", 125);
   add_money("gold",5 + random(5));
   set_combat_chance(100);
   add_spell("instill poison", "$A");
   set_skill("body alteration", 75);
   set_spell_level("instill poison",6);
   set_emotes(5, ({"The centipede crawls towards you.",
                   "The centipede begins looking for food.",
                   "The centipede eyes your hungrily."}));
}
