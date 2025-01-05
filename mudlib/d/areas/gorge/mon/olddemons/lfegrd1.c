//       Demon by Sinclair for use in the gorge
//     demon lifeguard



inherit MONSTER;




object money;
create() {
     ::create();
     set_name("Demon");
     set_id( ({"Demon", "demon", "lifeguard"}) );
     set_short("a Demon lifeguard");
     set_level(27);
     set_max_hp(1950);
     set_hp(1950);

     set("long", "This is a slim demon, with rippling muscles as any lifeguard should have.  All demons cannot swim  you know.\n");
     set_gender("male");
     set("race", "demon");

     set_alignment(0);
     set_body_type("human");
     set_overall_ac(85);
     set_wielding_limbs( ({"right hand","left hand"}) );
     set_emotes(5,
     ({ "The lifeguard blows his whistle at a demon.",
       }),0 );
     set_achats(50,
     ({ "The Demon grins at you.",
     "The lifeguard tries to hit you with some sunscreen.", }));
//spells
     set_combat_chance(70);
     add_spell("chaos ball","$A");
     set_spell_level("chaos ball", 6);
     add_spell("haste", "$(ME)");
     set_spell_level("haste", 6);
     add_spell("power word, stun", "$A");
     set_spell_level("power word, stun", 6);
//skills
     add_skill("magery", 120);
     add_skill("chaos magic",110);
     set_skill("resist stun",110);
     set_skill("concentrate",100);
     set_skill("two handed blunt",140);
     set_skill("two handed polearm",110);
     set_skill("two handed flail",110);
     set_skill("two handed blade",110);
     set_skill("parry",140);
     set_skill("defense", 130);
     set_skill("dodge",125);
     set_skill("melee",150);
//Money
     money=new("std/obj/coins");
     money->set_money("gold",(random(100)+100));
     money->move(this_object());







     force_me("wield war hammer in right hand and left hand");
     force_me("use concentrate");


     set("aggressive", 0);
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
