//      Edited by Tailwind
//
//      Blessed ReturnLIB
//      Tailwind 10/28/98

inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("alchemist object");
  set_id(({ "guildmaster object", "alchemist object", "symbol" }) );
  set_short("The symbol of the Alchemist Guildmaster");
  set_long(
"Type 'help guildmaster' for instructions.");
  set_join_room("/d/damned/guilds/join_rooms/alchemist_join");
  return;
}
