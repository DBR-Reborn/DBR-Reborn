//       Demon by Sinclair for use in the gorge
//           a lurking demon



inherit MONSTER;


object money;
create() {
     ::create();
     set_name("Demon");
     set_id( ({"Demon", "demon", "lurking demon", "lurking Demon"}) );
     set_short(" A lurking Demon");
     set_level(26);
     set_max_hp(1700);
     set_hp(1700);
     set("long", "There are some things you just do not want to bother.  This demon is very large.  He does not seem to have any weapons.  He does not seem to care though.\n");
     set_gender("male");
     set("race", "demon");
     set_alignment(0);
     set_body_type("human");
     set_overall_ac(80);
     set_wielding_limbs( ({"right hand","left hand"}) );







//spells
     set_combat_chance(70);
     add_spell("chaos ball","$A");
     set_spell_level("chaos ball", 6);
     add_spell("shocking grasp", "$(ME)");
     set_spell_level("shocking grasp", 6);
//Skills
     add_skill("magery",110);
     add_skill("chaos magic",110);
     add_skill("conjuration", 130);
     set_skill("resist stun",110);
     set_skill("concentrate",100);
     set_skill("two handed blunt",110);
     set_skill("two handed polearm",110);
     set_skill("two handed flail",110);
     set_skill("two handed blade",110);
     set_skill("parry",140);
     set_skill("melee",145);
     set_property("melee damage", ([ "disruption" : 30]));
     set_skill("attack",110);
     set_skill("defense",110);
     set_skill("dodge",125);
//Money
     money=new("std/obj/coins");
     money->set_money("gold",(random(100)+100));
     money->move(this_object());



//Misc


     force_me("use concentrate");



     set("agressive", 0);
}
int no_other_monsters(object who) {
     if(who->is_player() || who->is_pet()) return 1;
       else return 0;
}
void die(object who) {
int current;
     if(query_property("master_room") != 0){
     current = ( (query_property("master_room"))->query_property("dead"));
     (query_property("master_room"))->set_property("dead",(current+1));
}
     ::die(who);
     return;
}
