// Storm-giant guard for quarry in storm-giant village
// This dude is pretty buff, and his shield bash makes
// him even more bad...
// ripped a lot of code from elf guardian, but lowered 
// a bunch and altered shield bash function a bit to
// make him use it always
#include <std.h>

inherit MONSTER;

create() {
  object ob;
  
  ::create();
    set_name("guard");
    set_id( ({ "guard", "storm-giant", "storm giant" }) );
    set_short("A Storm-Giant Guard");
    set("race", "storm-giant");
    set_languages(({ "stormspeak", "common" }));
    set_long(@EndText
This is one of the much feared storm giant guards. He
stands some 20 feet tall and with fists the size of a 
barrel you should not feel an urge to trouble him. 
His body is very muscular and he seems to be well-versed
in combat.
EndText
);
    set_body_type("human");
    set_level(17);
    set_property("melee damage", ([ 
    "electricity" : 40,
    "impact" : 50]));
    set_skill("melee", 145);
    set_skill("dodge", 115);
    set_skill("block", 105);
    set_stats("strength", 170);
    set_skill("attack", 130);
    set_skill("resist stun", 100);
    set_skill("shield bash", 100);
    set_overall_ac(60);
    ob = new("/d/damned/virtual/tower-shield.armour");
    ob -> move(this_object());
    ob -> set("short", "Huge shield");
    ob -> set("long", "This is an abnormally huge shield.");
    command("wear shield on right hand");
    ob = new("/d/damned/virtual/scale-greaves.armour");
    ob -> move(this_object());
    command("wear greaves");
    ob = new("/d/damned/virtual/scale-mail.armour");
    ob -> move(this_object());
    command("wear scale mail");
    ob = new("/d/damned/virtual/great-helm.armour");
    ob -> move(this_object());
    command("wear helm");
    ob = new("std/obj/coins");
    ob -> set_money("gold", (100+random(200)));
    ob -> move(this_player());
}

// Makes the dude use shield bash every round in combat
// (though it will only happen every other round, cause
// thats how the skill limits it...) Thanks elfguardian-
// maker for the nice function :)

varargs void heart_beat(int flag) {
  if (query_current_attacker())
    force_me("use shield bash at
"+(string)(query_current_attacker()->query_name()));
  
  ::heart_beat(flag);
  return;
}

