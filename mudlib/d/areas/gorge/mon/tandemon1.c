//       Demon by Sinclair for use in the gorge
//       tanning demon :P



inherit MONSTER;


object money;
create() {
     ::create();
     set_name("Demon");
     set_id( ({"Demon", "demon", "tanning demon", "tanning Demon"}) );
     set_short("[23]tanning Demon");
     set_level(23);
     set_max_hp(1700);
     set_hp(1700);
     set("long", "This Demon is trying hard to get a tan from the pool of magma it is laying next to.  You can actually see that he is much redder on one side. ");
     set_gender("male");
     set("race", "demon");
     set_alignment(0);
     set_body_type("human");
     set_overall_ac(70);
     set_wielding_limbs( ({"right hand","left hand"}) );
     set_emotes(5,
     ({ "The Demon turns over onto his other side to get an even tan."}),0 );





//spells
     set_combat_chance(70);
     add_spell("chaos ball","$A");
     set_spell_level("chaos ball", 6);
     add_spell("haste", "$(ME)");
     set_spell_level("haste", 6);
//Skills
     add_skill("magery",110);
     add_skill("chaos magic",110);
     set_skill("resist stun",110);
     set_skill("concentrate",100);
     set_skill("two handed blunt",110);
     set_skill("two handed polearm",110);
     set_skill("two handed flail",110);
     set_skill("two handed blade",110);
     set_skill("parry",130);
     set_skill("melee",130);
     set_property("melee damage", ([ "disruption" : 30]));
     set_skill("attack",110);
     set_skill("defense",110);
     set_skill("dodge",110);
//Money
     money=new("std/obj/coins");
     money->set_money("gold",(random(25)+25));
     money->move(this_object());



//Misc


     force_me("use concentrate");



     set("agressive", 0);
}
int no_other_monsters(object who) {
     if(who->is_player() || who->is_pet()) return 1;
       else return 0;
}
