inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("mercenary object");
  set_short("The symbol of the Mercenary Guildmaster");
  set_id(({ "guildmaster object", "mercenary object", "symbol" }) );
  set_long(
"This symbol takes the form of a pair of crossed daggers.  Type "
"'help guildmaster' for help.");
  set_join_room("/d/damned/guilds/join_rooms/mercenary_join");
  return;
}