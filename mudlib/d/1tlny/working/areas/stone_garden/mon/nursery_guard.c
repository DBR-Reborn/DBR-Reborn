//  Wizard:   Shade Maelstorm
// reminder : guards weapon is to have +10 weapon enchance to +15 impact crushing and
// reminder : +5 crushing +5 impact +5 impaling
//  Monster:  Stone Nursery Guard

#include <std.h>

inherit MONSTER;

create() {
  object money;
object weap;
  ::create();
    set_name("Stone Guard");
    set_id( ({ "guard","stone guard" }) );
    set_level(15);
    set_short("Nursery Guard");
     set_long("The nursery guard stands on duty, warning of any who try to enter "
     " the sacred nursery to the north, and only allowing in those of the order "
     " of the sacred Basilisk "); 
    set("race", "Creature of Stone");
    set_gender("male");
    set_body_type("human");
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    set_property("melee damage", ([ "crushing" : 40]));
    set_overall_ac(6);
    set_skill("melee", 120);
    set_skill("dodge", 100);
    set_skill("parry", 100);
    set_skill("attack", 120);
    set_skill("reverse stroke" ,40);
    set_skill("resist stun",50);
    set_skill("whirlwind attack",70);
    set_skill("shield bash", 70);
    set("c awareness", 1);
    set_wimpy(0);
    set_alignment(300);
    weap = new("/d/damned/virtual/long-sword_5.weapon")->
      move(this_object());
   force_me("wield sword in left hand");
    new("/d/damned/virtual/breast-plate.armour")->
    move(this_object());
    force_me("wear breast plate");
    new("/d/damned/virtual/large-shield.armour")->
     move(this_object());
     force_me("wear shield on right hand");
    new("/d/damned/virtual/iron-bracer.armour")->
    move(this_object());
    set_material("metal/steel");
    force_me("wear bracer on right arm");
    new("/d/damned/virtual/iron-bracer.armour")->
    move(this_object());
    set_material("metal/steel");
    force_me("wear bracer on left arm");
    money=new("std/obj/coins");
    money->set_money("gold",(random(20)+50));
    money->move(this_object());
    set_emotes(5, ({
     "The Stone guard walks back and forth.."
     "The stone guard stops, listening for any intruders."
    "The stone guard stands still in front of the nursery entrance"
	}),1);
}

 varargs void heart_beat(int flag) {
 if(query_current_attacker() && !random(4) == 1) {
     force_me("use shield bash at
     "+(string)(query_current_attacker()->query_name()));
   }
  ::heart_beat(flag);
 }
