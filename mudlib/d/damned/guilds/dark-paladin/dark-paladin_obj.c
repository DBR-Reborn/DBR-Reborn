inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("dark-paladin object");
  set_id(({ "guildmaster object", "dark-paladin object" }) );
  set_short("The symbol of the Dark-Paladin Guildmaster");
  set_long(
"Type 'help guildmaster' for instructions.");
  set_join_room("/d/damned/guilds/join_rooms/dark-paladin_join");
  return;
}
