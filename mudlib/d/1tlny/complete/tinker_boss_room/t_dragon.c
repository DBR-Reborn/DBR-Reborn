#include <std.h>
#include <guildguard.h>

inherit MONSTER;

create() {
  ::create();
    set_name("dragon");
    set_id( ({ "dragon" }) );
    set_short("A, scary dragon");
     set("race", "dragon");
    set_long(
"The dragon lies down in front of the small north exit.");
    set_body_type("human");
    set_level(30);
    set_overall_ac(GUARD_AC);
    set_property("magic resistance", GUARD_RESIST);
    set_property("enhance criticals", GUARD_ENHCRIT);
    set_languages(({ "elvish", "common", "dragonish" }));
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
new("/d/damned/guilds/tinker/t_dragon_scale")->
		move(this_object());
	force_me("wear scale");
add_money("mithril", 100 + random(100));
}

void init() {
  ::init();
add_action("block_exit", "north");
  return;
}

int block_exit() {
  int gld;
  string p_name;
  object join_room, *inv;

  if(wizardp(this_player())) return 0;
   if((string)this_player()->query_class() != "tinker") {
     force_me("speak common");
    force_me("say Only tinkers may pass.");
    return 1;
  }
if(wizardp(this_player())) return 0;
   if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     force_me("speak common");
    force_me("say How dare you try to come into in here at such a low level you must be at least level 16 tinker to come in here");
    return 1;
  }

  inv = filter_array(all_inventory(this_player()), "locker_filter",
        this_object());
  if(sizeof(inv)) {
     force_me("speak common");
    force_me("say We do not allow storage devices in here.");
    return 1;
  }
join_room = find_object_or_load("/d/damned/guilds/join_rooms/tinker_join");
  p_name = (string)this_player()->query_name();
  if(member_array("treasury restrict", (string *)join_room->
                  query_member_privs(p_name)) >= 0) {
    write("The Dragon says in Common: You have been barred from the special room by the Guildmaster.");
    return 1;
  }
  return 0;
}

int locker_filter(object item) { return (int)item->query_is_locker(); }
