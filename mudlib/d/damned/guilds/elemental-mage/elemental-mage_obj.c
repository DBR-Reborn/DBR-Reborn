inherit "/std/guilds/guildmaster_obj";

void create() {
  ::create();
  set_name("elemental-mage object");
  set_short("The symbol of the Elemental-mage Guildmaster");
  set_id(({ "guildmaster object", "elemental-mage object", "symbol" }) );
  set_long(
	"This symbol takes the form of a small bejeweled wand. "
	"Type 'help guildmaster' for help.");
  set_join_room("/d/damned/guilds/join_rooms/elemental-mage_join");
  return;
}

