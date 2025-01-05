// I stole this guardian from diewarzau to use as an example. Bleys
// It is well commented
//  ummmm and I'm like stealing it from deorwin, going 
// change it around lots and use it, cuz I'm tired of 
// trying to figure out the function this mob has...
// so instead of coping the function from to my mob...
// I'm copying this mob to my mob....
// Hood...


#include <std.h>

inherit MONSTER;

create() {
  object ob;
int zlevel;
  
  ::create();
    set_name("guard");
    set_id( ({ "weretiger", "weretiger guard", "guard" }) );
set_short("A Shao-tan Guard");
    set("race", "weretiger");
    set_languages(({ "elvish", "common" }));
set("long","%^RESET%^This weretiger has "
"an aggressive and piercing look in his "
"eyes. You suspect he may be one "
"of the elite. His massive body appears "
"to be very muscular, and toned, "
"without the slightest hint of fat. "
"His fur is an uncommon dark black from "
"head to toe. "
"The one distinguishing mark is a symbol "
"that appears to have been burned into "
"his skin over his right eye.\n");
    set_body_type("human");
zlevel=(35+random(6));
set_level(zlevel);
    set_property("melee damage", ([ "impaling" : 60]));

// Impaling melee damage rather then crushing 
// cuz I figure the dude has sharp claws
// and is more then strong enough to impale 
// with them..

    set_skill("melee", 125);
    set_skill("dodge", 110);
    set_skill("parry", 165);
    set_skill("block", 165);
    set_skill("blade", 195);
    set_stats("dexterity", 110);
    set_skill("whirlwind attack", 110);
    set_skill("resist stun", 100);
    set_skill("spell sense", 80);
    set_skill("shield bash", 110);
    set_property("enhance criticals", -2);
set_property("magic resistance",30);
// Resistance to magic is due to the 
// power of the shadow elemental that 
// is the *cough* unknown overlord of 
// Shao-tan and a few select creatures 
// that inhabit the city.. 
// this guard is one such creature.

set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(100);
    set("see invis", 1);

// the following is an example of setting up a custom weapon using the 
// virtual server
    ob = new("/d/damned/virtual/broad-sword_6.weapon"); // _6 is the quality
    ob->set_material("metal/neorolite");  // note the form is metal/<type>
    ob->set_property("brittle", 25);  // this simulates the existing magic
    ob->set_property("enchantment", 20); // major puissance 10
    ob->set_hit_bonus(25);    // major accuracy 12.5
    ob->set_wc(12, "fire");  // along with the puissance makes a nice wpn
    ob->set_wc(12, "electricity");
ob->set_long("This broadsword is crafted "
"to perfection, the blade is covered with "
"symbols and markings. The edges of the blade "
"appear to be of unsurpassed sharpness and "
"also have little tiny teeth that you "
"suspect would aid in severing vital limbs.\n");
    ob->move(this_object());
    force_me("wield sword in right hand");

// The following is an example of virtual armour
    ob = new("/d/damned/virtual/large-shield.armour");
    ob->set_material("metal/mithril");
    ob->set_property("brittle", 20);
    ob->set_property("enchantment", 20);
    ob->move(this_object());
    force_me("wear shield on left hand");
    set_combat_chance(200);
}


// The following fucntion handles forcing the guardian to attack 
// people before they can get their spells off...

void catch_tell(string str) {
  string who;
  object plyr, *inv;

  str = eliminate_colour(str);
  if(!this_object()->query_casting() && sscanf(str, "%s begins casting a spell.", who)) {
    if(who == "Someone") {
      inv = all_inventory(environment());
      inv = filter_array(inv, (: call_other :), "is_player");
      inv = filter_array(inv, (: call_other :), "query_invis");
      inv = filter_array(inv, (: call_other :), "query_casting");
      if(!sizeof(inv)) {
        return;
      }
      plyr = inv[0];
    }
    else
      plyr = present(lower_case(who), environment());
    if(!plyr) {
      return;
    }
    if(plyr->is_player() && (int)plyr->query_level() > 15) {
force_me("attack "+(string)plyr->query_name());
    }
    return;
  }
  if(str == "YOU CAN MOVE AGAIN!!!" && !query_casting() && (inv=query_attackers())) {
    if(sizeof(inv) >= 3)
      force_me("cast *6 elemental storm");
    else if(sizeof(inv))
      force_me("cast *6 greater elemental bolt at "+
        (string)inv[0]->query_name());
  }
  return;
}

void init() {
  ::init();

// the following adds the action 'north' to anyone who enters the
// room... due to the way commands are parsed, it will overrride the 
// normal exit, allowing the guardian to block the north exit of
// any room he happens to be in
   add_action("block_exit", "north");

// Since this is in init, it will eb called whenever the guardian
// enters a room, or whenever a mob or player enters the room with him.
  if(this_player()->is_player() && (int)this_player()->query_level() > 15 &&
    this_player()->query_casting() && !query_casting()) {
    force_me("speak common");
    force_me("say How dare you try to come into my domain, spell already casting?!  "
       "Die, "+capitalize((string)this_player()->query_name())+"!");
    force_me("cast *5 greater elemental bolt at "+(string)this_player()->query_name());
    kill_ob(this_player(), 1);
  }
  return;
}

// The following function is referenced whenever someone tries to go north
int block_exit(string null) {
  string name = capitalize((string)this_player()->query_name());
  
  if(!this_player()->is_player()) return 0;
  if(wizardp(this_player())) return 0;
  if((int)this_player()->query_level() <= 15) return 0;
  force_me("speak common");
  if(!this_player()->query_invis()) {
    force_me("say I must not allow such powerful players as you, "+name+", into "
        "the camp, for fear you would destroy it!");
  } else {
    write("To your great surprise, the elf guardian lays a hand on you invisible shoulder!");
    force_me("say I don't like such tom-foolery as invisibility.  You may not pass.");
  }
  return 1;
}

// This is a cute little way to force a mob to use a skill in combat.
// In the future we will be upgrading monster.c such that they will
// automatically try to use such skills if they have them.
varargs void heart_beat(int flag) {
  if(query_current_attacker() && !random(4)) {
    force_me("use shield bash at "+(string)(query_current_attacker()->query_name()));
  }
  ::heart_beat(flag);
  return;
}

