//  	A join room for fighters, well commented and intended fo use as
//	an example room of this type.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95
//
//      Edited by Tailwind for the Shaman Guild
//
//      -Tailwind 9/18/99
//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.

#include <std.h>

inherit "/std/guilds/join_room";

void create() {
  //  IMPORTANT:  The following MUST appear before ::create();
  set_class_name("shaman");

  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
     //set_related_guilds(({ "cleric", "war-priest" }));
  set("short", "The Shaman Room");
  set("long", "An old man sits in this room, staring at you. He wears the natural armour of a shaman. You see a powerful staff to his side. If you so desire, you may 'join' him and become a shaman. \n");
  //  The "\n" is important at the end of the long desc.

  set_exits( ([ "south" : "/d/daybreak/room/dblw5",
	      "north" : "/d/damned/guilds/shaman/shaman_train_room", "west" : "/d/damned/guilds/shaman/shamanarea/rooms/forest4" ]) );
//Changed exit
//"out" : "/d/areas/shamanarea/rooms/forest5",

  set("guildmaster", "/d/damned/guilds/shaman/shaman_gm");
  //  The guildmaster is automatically cloned if no pc guildmaster is
  //  found.

  set_guild_obj("/d/damned/guilds/shaman/shaman_obj");
  //  This file points to the guildmaster object.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 3);
  set_property("base mp regen", 6);
  //  Base healing per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  set_property("hp advance", 20);
  set_property("mp advance", 35);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
	([ "wisdom" : 10 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}
