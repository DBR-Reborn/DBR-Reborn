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
  set_class_name("elemental-mage");

  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
new("d/damned/guilds/join_rooms/tcan")->move(this_object());

//TLNY2024 Change for dual training
/*
    set_related_guilds(({ "sword-mage", "arch-mage", "elementalist" }));
    //Other:      "enchanter", "necromancer", "nethermancer"
    set_odd_guilds(({ "fighter", "thief", "tinker",  "cleric" }));
    set_hated_guilds(({ "chaotic-lord" }));
    set_no_guilds(({ "assassin", "nightblade", "dark-paladin",  "war-priest", "paladin", }));
*/	
  set("short", "The Elemental-mage's Guild Joining Room");
  set("long", 
"This is the Elemental-mage Guild.  Here can be found the deadliest "
"spell casters in the land.  Several magical items adorn the walls "
"here, and astute-looking magi lurk in the shadows.\n");
  //  The "\n" is important at the end of the long desc.


  set_items( ([ "items" : "They are very valuable, but well protected.",
        "magi" : "Several of them wear ornate robes and jewelry." ]));

add_exit("/d/daybreak/room/dbvl3", "north");
        add_exit("/d/damned/guilds/elemental-mage/skill_room", "south");


  set("guildmaster", "/d/damned/guilds/elemental-mage/elemental-mage_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/elemental-mage/elemental-mage_obj");
  //  This is the filename for the guild's guildmaster object, carried
  //  by the PC guildmaster if any.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 3);
  set_property("base mp regen", 15);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

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
