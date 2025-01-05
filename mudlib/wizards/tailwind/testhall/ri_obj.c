inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("royal-infantry object");
  set_id(({ "guildmaster object", "royal-infantry object", "symbol", "royal object", "infantry object" }) );
  set_short("The symbol of the Royal-Infantry Guildmaster");
  set_long(
"Type 'help guildmaster' for instructions.");
  set_join_room("/d/damned/guilds/join_rooms/royal-infantry_join");
  return;
}
