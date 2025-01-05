//  	A join room for fighters, well commented and intended fo use as
//	an example room of this type.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95
//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.

inherit "/std/guilds/join_room";

void create() {
  //  IMPORTANT:  The following MUST appear before ::create();
  set_class_name("arch-mage");

  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  new("/d/damned/guilds/join_rooms/tcan")->move(this_object());
  set("short", "The Arch-Mage's Guild Joining Room");
  set("long", 
"This is the Arch Mage Guild.  Here, arch-magi hone their skills and "
"spells, and train to become deadly spellcasters.  You see a training "
"room to the south.\n");
  //  The "\n" is important at the end of the long desc.
//TLNY2024 Change for dual training
/*
    set_related_guilds(({ "elemental-mage", "elementalist" }));
    //Other:      "enchanter", "necromancer", "nethermancer"
    set_odd_guilds(({ "tinker",  "cleric", "war-priest", "paladin", }));
    set_hated_guilds(({ "fighter", "thief" }));
    set_no_guilds(({ "dark-paladin", "nightblade", "assassin", "chaotic-lord", "sword-mage" }));
*/
  set_exits( ([ 
              "north" : "/d/daybreak/room/dblw5",
	      "south" : "/d/damned/guilds/arch-mage/train_room" ]) );

  set("guildmaster", "/d/damned/guilds/arch-mage/arch-mage_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/arch-mage/arch-mage_obj");
  //  This is the filename for the guild's guildmaster object, carried
  //  by the PC guildmaster if any.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 3);
  set_property("base mp regen", 15);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  //set_property("hp advance", 7);
  //set_property("mp advance", 47);
  set_property("hp advance", 15);
  set_property("mp advance", 50);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
	([ "intelligence" :  10 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}
