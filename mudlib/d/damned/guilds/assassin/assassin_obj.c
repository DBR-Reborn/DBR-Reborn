inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("assassin object");
  set_short("The symbol of the Assassin Guildmaster");
  set_id(({ "guildmaster object", "assassin object", "symbol" }) );
  set_long(
"This symbol takes the form of a small bejeweled sword.  Type "
"'help guildmaster' for help.");
  set_join_room("/d/damned/guilds/join_rooms/assassin_join");
  return;
}

