//      A join room for fighters, well commented and intended fo use as
//      an example room of this type.
//
//      DarkeLIB 0.1
//      -Diewarzau 8/8/95
//
//      Edited by Tailwind
//
//      Blessed ReturnLIB
//      -Tailwind 10/28/98

//      NOTE:  Before coding any guild, Diewarzau must know the filename
//      of the join_room so he can set the file privs accordingly.

#include <std.h>

inherit "/std/guilds/join_room";

void create() {
    //  IMPORTANT:  The following MUST appear before ::create();
    set_class_name("alchemist");

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    //set_related_guilds(({ "tinker", "enchanter" }));
    set("short", "The Alchemists' Guild Joining Room");
    set("long", "Many alchemical implements poke from the "+
      "walls here. Yourealize that this must be the famous "+
      "alchemist guild. You wonder if this is where you join. \n");
    //  The "\n" is important at the end of the long desc.

    set_exits( ([ "west" : "/d/daybreak/room/dbcc3",
	"north" : "/d/damned/guilds/alchemist/train_room" ]) );

    set("guildmaster", "/d/damned/guilds/alchemist/alchemist_gm");
    //  The guildmaster is automatically cloned if no pc guildmaster is
    //  found.

    set_guild_obj("/d/damned/guilds/alchemist/alchemist_obj");
    //  This file points to the guildmaster object.

    //  The following lines set the properties for the guild.

    set_property("base hp regen", 8);
    set_property("base mp regen", 7);
    //  Base healing per tick.  Note that the default is 3 for both.
    //  Keep in mind that this increases with level.

    set_property("hp advance", 25);
    set_property("mp advance", 25);
    //  Base advance per level im max mp/hp.  Default is 10.

    set_property("guild mods",
      ([ "wisdom" :  10, "intelligence" : 10 ]) );
    //  Stat mods received upon joining.

    //  The following line is necessary:
    this_object()->reset();
    return;
}

