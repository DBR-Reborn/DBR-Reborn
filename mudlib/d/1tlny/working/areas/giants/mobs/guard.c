// Storm-giant guard for quarry in storm-giant village
// This dude is pretty buff, and his shield bash makes
// him even more bad...

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
normal human you should not feel an urge to trouble him.
His body is very muscular and he seems to be well-versed
in combat.
EndText
);
    set_body_type("human");
    set_level(17);
    set_property("melee damage", ([ "impact" : 40]));
    set_skill("melee", 140);
    set_skill("dodge", 105);
    set_skill("block", 105);
    set_stats("strength", 170);
    set_skill("whirlwind attack", 80);
    set_skill("resist stun", 80);
    set_skill("shield bash", 100);
    set_overall_ac(60);
    ob = new("/d/damned/virtual/tower-shield.armour");
    ob -> move(this_object());
    ob -> set("short", "A huge shield");
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
    force_me("use shield bash at "+(string)(query_current_attacker()->query_name()));
  
  ::heart_beat(flag);
  return;
}

// Makes the guard block northern exit

void init() {
   ::init();
   add_action("block_exit", "north");
}

// The following function is referenced whenever someone tries to go north

int block_exit(string null) {
  string name = capitalize((string)this_player()->query_name());
  
  if(wizardp(this_player())) return 0;
  force_me("speak common");
  if(!this_player()->query_invis()) {
    force_me("say You are not authorized to enter the quarry!");
  }
  return 1;
}


