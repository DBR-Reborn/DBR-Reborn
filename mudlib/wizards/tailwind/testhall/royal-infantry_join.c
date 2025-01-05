//  	A join room for fighters, well commented and intended fo use as
//	an example room of this type.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

//	NOTE:  Before coding any guild, Diewarzau must know the filename
//	of the join_room so he can set the file privs accordingly.

inherit "/std/guilds/vault_join_room";

void create() {
  //  IMPORTANT:  The following MUST appear before ::create();
  set_class_name("royal-infantry");

  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
new("d/damned/guilds/join_rooms/tcan")->move(this_object());
     set_related_guilds(({ "merchant", "mercenary" }));
  set("short", "The Royal-Infantry Recruitment Office");
  set("long", "This one-room building houses the recruitment offices "+
      "of Daybreak Ridge's Royal-Infantry, the protectors of the city. "+
    "The walls are filled with posters extolling the virtues of joining"+
    "the infantry. You feel like you can almost hear the drilling "+
    "from right here, despite that the training camp is in the "+
    "mountains to the north.\n");
  //  The "\n" is important at the end of the long desc.

    add_exit("/d/damned/daybreak/rooms/ridge1", "west");

  set_guild_obj("/d/damned/guilds/royal-infantry/ri_obj");
  //  This file points to the guildmaster object.

  //  The following lines set the properties for the guild.

  set_property("base hp regen", 10);
  set_property("base mp regen", 2);
  //  Base heling per tick.  Note that the default is 3 for both.
  //  Keep in mind that this increases with level.

  set_property("hp advance", 45);
  set_property("mp advance", 4);
  //  Base advance per level im max mp/hp.  Default is 10.

  set_property("guild mods",
	([ "strength" :  10, "constitution" : 10 ]) );
  //  Stat mods received upon joining.

  //  The following line is necessary:
  this_object()->reset();
  return;
}
