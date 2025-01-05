//       Demon by Sinclair for use in the gorge
//        Demon guard



inherit MONSTER;


object money;
create() {
     ::create();
     set_name("Demon Guard");
     set_id( ({"Demon", "Demon Guard", "demon", "guard"}) );
     set_short("A Demon Guard");
     set_level(30);
     set_max_hp(3000);
     set_hp(3000);
     set("long", "This is a extremely bulky Demon.  He is guarding whatever is behind that door.  It must be something valuable for him to be standing there all the time.  He seems not to care about you except if you try to get by him.");
     set_gender("male");
     set("race", "demon");
     set_alignment(0);
     set_body_type("human");
     set_overall_ac(100);
     set_wielding_limbs( ({"right hand","left hand"}) );
     set_emotes(5,
           ({ "The guard shakes his head to stay alert."}),0 );


     set_achats(50,
     ({ "The guard slaps you back with an open hand.",
     "The guard tries to kick you in the groin but he misses.",}));
//spells
     set_combat_chance(70);
     set_casting_chance(0);
     add_spell("chaos ball","$A");
     set_spell_level("chaos ball", 6);


     add_spell("blur", "Demon Guard");
     set_spell_level("blur", 6);
     add_spell("mad rage", "Demon Guard");
     set_spell_level("mad rage", 6);
//skills
     add_skill("magery", 150);
     add_skill("illusionism",110);
     add_skill("chaos magic",110);
     set_skill("resist stun",110);
     set_skill("concentrate",100);
     set_skill("two handed blunt",110);
     set_skill("two handed sword", 150);
     set_skill("two handed polearm",110);
     set_skill("two handed flail",110);
     set_skill("two handed blade", 150);
     set_skill("parry", 140);
     set_skill("defense",110);
     set_skill("dodge", 140);
     set_skill("attack", 150);
     set_skill("melee",150);
     set_property("melee damage", ([ "disruption" : 40]));

//Money
     money=new("std/obj/coins");
     money->set_money("gold",(random(100)+200));
     money->move(this_object());



//Misc
new("/d/damned/virtual/scimitar_6.weapon")->move(this_object());
     force_me("wield sword in right hand and left hand");
new("/d/damned/virtual/chain-mail.armour")->move(this_object());
     force_me("wear chain mail");

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





