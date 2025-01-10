inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("voidwalker object");
  set_id(({ "guildmaster object", "voidwalker object" }) );
  set_short("The symbol of the Voidwalker Guildmaster");
  set_long(
"Type 'help guildmaster' for instructions.");
  set_join_room("/d/damned/guilds/join_rooms/voidwalker_join");
  return;
}
