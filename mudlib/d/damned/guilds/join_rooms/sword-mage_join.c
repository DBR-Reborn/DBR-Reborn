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
  set_class_name("sword-mage");

  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
new("d/damned/guilds/join_rooms/tcan")->move(this_object());

//TLNY2024 Change for dual training
/*
    set_related_guilds(({ "elementalist", "elemental-mage", }));
    //Other:      "arch-mage","fighter", "thief", "tinker", "enchanter" 
    set_odd_guilds(({ "paladin", "necromancer", "nethermancer" }));
    set_hated_guilds(({ "chaotic-lord", }));
    set_no_guilds(({ "nightblade", "dark-paladin", "assassin", "cleric", "war-priest" }));
*/	
	
  set("short", "The sword-mage's Guild Joining Room");
  set("long", 
"This is the sword-mage joining room. Here you "+
	"can join the sword-mages, a secret group of deadly "+
	"fighter-mages. The room is more of a cave then a "+
	"normal room, as the training room can be accessed "+
	"by going down from here.\n");
  //  The "\n" is important at the end of the long desc.

  set_exits( ([ 
              "west" : "/d/daybreak/room/dblw3",
	      "down" : "/d/damned/guilds/sword-mage/train_room" ]) );

  set("guildmaster", "/d/damned/guilds/sword-mage/sword-mage_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/sword-mage/sword-mage_obj");
  //  This is the filename for the guild's guildmaster object, carried
  //  by the PC guildmaster if any.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 5);
  set_property("base mp regen", 5);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  set_property("hp advance", 30);
  set_property("mp advance", 24);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
	([ "intelligence" :  5, "constitution" : 5 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}
