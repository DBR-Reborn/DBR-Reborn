//       Demon by Sinclair for use in the gorge
//            small demon



inherit MONSTER;


object money;
create() {
     ::create();
     set_name("Small Demon");
     set_id( ({"Demon", "demon", "small demon", "small Demon"}) );
     set_short("A small Demon");
    set_level(20);
     set_max_hp(1700);
     set_hp(1700);
     set("long", "The Demon is not large and has red glowing eyes. He seems pretty upset that you are barging into his home. "); 
     set_gender("male");
     set("race", "demon");
     set_alignment(0);
     set_body_type("human");
     set_overall_ac(80);
     set_wielding_limbs( ({"right hand","left hand"}) );
     set_emotes(10,
        ({ "The Demon paces back and forth as if waiting for something.",
        "The demon spreads his small wings out as if to stretch.",
       }),0 );
     set_achats(50,
     ({ "The Demon grins at you.",
      "The Demon laughs at your existance.", }));
//spells
     set_combat_chance(70);
     add_spell("chaos ball","$A");
     set_spell_level("chaos ball", 6);
     add_spell("haste", "$(ME)",1,500);
     set_spell_level("haste", 6);
//Skills
     add_skill("magery",110);
     add_skill("chaos magic",110);
     set_skill("resist stun",110);
     set_skill("concentrate",100);
     set_skill("two handed blunt",110);
    set_skill("two handed polearm", 130);
     set_skill("two handed flail",110);
     set_skill("two handed blade",110);
     set_skill("parry",110);
     set_skill("defense",110);
     set_skill("dodge", 130);
     set_skill("melee",130);
     set_property("melee damage", (["disrpution" :20]));

//Money
     money=new("std/obj/coins");
     money->set_money("gold",(random(100)+100));
     money->move(this_object());



//Misc
new("/d/damned/virtual/spear_6.weapon")->move(this_object()); 
     force_me("wield spear in right hand and left hand");
     force_me("use concentrate");
     set_moving(1);
     set_speed(60);
     set("aggressive",(: call_other,this_object(), "no_other_monsters" :) );
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
