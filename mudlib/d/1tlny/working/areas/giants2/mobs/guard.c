#include <std.h>

inherit MONSTER;

create() {
object shield, money, smail, sgreaves;

  ::create();
    set_name("guard");
    set_id( ({ "giant", "guard", "storm-giant" }) );
    set_short("Storm-giant guard");
    set("race", "storm-giant");
    set_languages(({ "stormspeak", "common" }));
    set_long(@EndText
This guard looks extremely bulky.
EndText
);
    set_body_type("human");
    set_level(20);
    set_property("melee damage", ([
       "impact" : 65,
       "crushing" : 40,
       "electricity" : 65 ]) );
 
    set_stats("strength", 160);    set_skill("attack", 130);
    set_skill("melee", 155);
    set_skill("dodge", 130);
    set_skill("perception", 135);
    set_skill("block", 110);
    set_skill("resist stun", 100);
    set_skill("shield bash", 90);
    set_max_hp(2500);
    set_overall_ac(70);
    sgreaves = new("/d/damned/virtual/scale-greaves.armour");
    sgreaves -> move(this_object());
    command("wear greaves");
    smail = new("/d/damned/virtual/scale-mail.armour");
    smail -> move(this_object());
    command("wear mail");
    money = new("/std/obj/coins");
    money -> set_money("gold", 150);
    money -> move(this_object());
    shield = new("/d/damned/virtual/large-shield.armour");
    shield -> move(this_object());
    command("wear shield on right hand");

// This is a cute little way to force a mob to use a skill in combat.
// In the future we will be upgrading monster.c such that they will
// automatically try to use such skills if they have them.
// varargs void heart_beat(int flag) {
//  if(query_current_attacker() && !random(4)) {
//    force_me("use shield bash at
// "+(string)(query_current_attacker()->query_name()));
//  }
//
//  ::heart_beat(flag);
//  return;
// }
}
