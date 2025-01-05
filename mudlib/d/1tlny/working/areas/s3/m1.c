#include <std.h>
#include <guildguard.h>

inherit MONSTER;


   object ob;

create() {
  ::create();
    set_name("guard");
    set_id( ({ "guard", "orc" }) );
    set_short("[13]orc guard");
    set_long("A Guard stands before the door to the east");

    set_level(13);

   set_property("enhance criticals",-2);
   set_property("magic resistance", 60);
   set_overall_ac(65);
   set_body_type("human");
   set("race", "human");
   set_gender("male");
   set_alignment(-100);

   set_stats("strength", 90 + random(30));
   set_stats("dexterity", 90 + random(30));
   set_stats("constitution", 90 + random(20));
   set_stats("wisdom", 50 + random(20));
   set_stats("intelligence", 50 + random(20));
   set_stats("charisma", 50);
   set_skill("blunt", 90);
   set_skill("axe", 90);
   set_skill("blade", 90);
   set_skill("melee", 80);
   set_skill("attack", 80);
   set_skill("defense", 80);
   set_skill("dodge", 80);
   set_skill("reverse stroke", 80);
   set_skill("martial arts",80);
   set_skill("concentrate", 80);
   set_skill("perception", 80);
   set("concentrate", 1);
    set_skill("resist stun", 125);


    set_property("handedness", "right hand");

/*
    set_skill("conjuration", 95);
    set_spell_level("blizzard", 6);
    add_spell("blizzard", "", 1);
*/
    set_combat_chance(150);

   // new("/d/damned/virtual/long-sword_5.weapon")->
     // move(this_object());

   ob = new("/d/damned/virtual/hammer_5.weapon");
   ob->move(this_object());
   ob->set_wc(5, "electricity");
    new("/d/damned/virtual/large-shield.armour")->
      move(this_object());
    new("/d/damned/virtual/chain-mail.armour")->
      move(this_object());
    new("/d/damned/virtual/plate-greaves.armour")->
      move(this_object());
    new("/d/damned/virtual/plate-bracer.armour")->
      move(this_object());
    new("/d/damned/virtual/plate-bracer.armour")->
      move(this_object());
    force_me("equip");
  

add_money("gold", 100 + random(100));
}


void init() {
  ::init();
add_action("block_exit", "east");
  return;
}

int block_exit() {
  int gld;
  string p_name;
  object join_room, *inv;

  if(wizardp(this_player())) return 0;
   if((string)this_player()->query_class() != "child") {
     write("The Guard says in Common: Do not try to pass me!");
    return 1;
  }
  inv = filter_array(all_inventory(this_player()), "locker_filter",
        this_object());
  if(sizeof(inv)) {
    write("The Guard says in Common: We do not allow storage devices in here.");
    return 1;
  }
join_room = find_object_or_load("/d/damned/guilds/join_rooms/paladin_join");
  p_name = (string)this_player()->query_name();
  if(member_array("treasury restrict", (string *)join_room->
                  query_member_privs(p_name)) >= 0) {
    write("The Knight says in Common: You have been barred from the special room by the Guildmaster.");
    return 1;
  }

 return 0;
}

int locker_filter(object item) { return (int)item->query_is_locker(); }

