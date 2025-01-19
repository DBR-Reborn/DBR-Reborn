#include <std.h>
#include <guildguard.h>

inherit MONSTER;

create() {
  ::create();
    set_name("knight");
    set_id( ({ "knight" }) );
    set_short("A, Holy Knight");
     set("race", "human");
    set_long(
"A holy knight stands gaurd before the most evil of prense emiting from the hole to the west.");
    set_body_type("human");
    set_level(30);
    set_overall_ac(GUARD_AC);
    set_property("magic resistance", GUARD_RESIST);
    set_property("enhance criticals", GUARD_ENHCRIT);
    set_skill("block", 125);
    set_stats("strength", 300);
    set_property("handedness", "right hand");
    set_skill("conjuration", 95);
    set_spell_level("blizzard", 6);
    add_spell("blizzard", "", 1);
    set_combat_chance(150);
    //new("/d/damned/virtual/long-sword_5.weapon")->
     // move(this_object());
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
    force_me("wear mail");
    force_me("wield sword in right hand");
    force_me("wear shield on left hand");
    force_me("wear greaves");
    force_me("wear bracer 2 on right arm");
    force_me("wear bracer on left arm");
new("/d/damned/guilds/paladin/proom/p_holy_badge")->
		move(this_object());
	force_me("wear badge");
add_money("mithril", 30 + random(30));
}

void init() {
  ::init();
add_action("block_exit", "west");
  return;
}

int block_exit() {
  int gld;
  string p_name;
  object join_room, *inv;

  if(wizardp(this_player())) return 0;
   if((string)this_player()->query_class() != "child") {
     write("The Holy Knight says in Common: Do not try to pass my what I guard is the most vile of creatures stepping into the room will unleash distruction on everyone in daybreak!");
    return 1;
  }
  inv = filter_array(all_inventory(this_player()), "locker_filter",
        this_object());
  if(sizeof(inv)) {
    write("The Knight says in Common: We do not allow storage devices in here.");
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
