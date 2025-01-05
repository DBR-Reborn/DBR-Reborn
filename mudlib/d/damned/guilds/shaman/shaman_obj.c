inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("shaman object");
  set_short("The symbol of the Shaman Guildmaster");
  set_id(({ "guildmaster object", "shaman object", "symbol" }) );
  set_long(
"This symbol takes the form of a small black raven.  Type "
"'help guildmaster' for help.");
  set_join_room("/d/damned/guilds/join_rooms/shaman_join");
  return;
}

