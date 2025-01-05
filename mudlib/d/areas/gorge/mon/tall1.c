//       Demon by Sinclair for use in the gorge
//      a tall Demon



inherit MONSTER;


object money;
create() {
     ::create();
     set_name("Demon");
     set_id( ({"Demon", "demon", "tall demon", "tall Demon"}) );
     set_short("[26]Tall Demon");
     set_level(26);
     set_max_hp(1700);
     set_hp(1700);
     set("long", "This demon must be at least 7 foot tall.  His red eyes glow blood red. His wings span out to almost block your view.\n");
     set_gender("male");
     set("race", "demon");
     set_alignment(0);
     set_body_type("human");
     set_overall_ac(85);
     set_wielding_limbs( ({"right hand","left hand"}) );







//spells
     set_combat_chance(70);
     add_spell("chaos ball","$A");
     set_spell_level("chaos ball", 6);
     add_spell("heal", "tall demon");
     set_spell_level("heal", 6);
     add_spell("enlarge", "tall demon",1,200);
     set_spell_level("enlarge", 6);
// Skills
    set_max_mp(2000);
     set_mp(2000);
     add_skill("magery",110);
     add_skill("chaos magic",110);

     add_skill("conjuration", 130);
     set_skill("resist stun",110);
     set_skill("concentrate",100);
     set_skill("two handed blunt",110);
     set_skill("two handed polearm",140);
     set_skill("two handed flail",110);
     set_skill("two handed blade",110);
     set_skill("parry",135);
    set_skill("melee",135);
     set_property("melee damage", (["disrpution" :20]));
     set_skill("attack",120);
     set_skill("defense",110);
     set_skill("dodge",125);
//Money
     money=new("std/obj/coins");
     money->set_money("gold",(random(25)+25));
     money->move(this_object());



//Misc


     force_me("use concentrate");
new("/d/damned/virtual/halberd_6.weapon")->move(this_object());
     force_me("wield halberd in right hand and left hand");



     set("agressive", 0);
}
int no_other_monsters(object who) {
     if(who->is_player() || who->is_pet()) return 1;
       else return 0;
}
