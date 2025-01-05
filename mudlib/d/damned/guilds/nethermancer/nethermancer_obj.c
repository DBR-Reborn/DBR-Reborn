inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("nethermancer object");
  set_id(({ "guildmaster object", "nethermancer object", "symbol" }) );
  set_short("The symbol of the Nethermancer Guildmaster");
  set_long(
"Type 'help guildmaster' for instructions.");
  set_join_room("/d/damned/guilds/join_rooms/nethermancer_join");
  return;
}
