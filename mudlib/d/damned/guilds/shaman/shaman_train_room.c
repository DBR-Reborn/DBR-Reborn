//	An example skill training room for the fighter's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95
//
//      Edited by Tailwind
//
//      dbrLIB
//      Tailwind 01/25/01

#include <std.h>

inherit "/std/guilds/skill_room";

void create() {
  object ob;
  ::create();
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({"board", "shaman board"}) );
  ob->set_board_id("shaman_board");
  ob->set_max_posts(30);
  ob->set_location("/d/damned/guilds/shaman/shaman_train_room");
  ob->set("short","Shaman Board");
  ob->set("long","A board for players to post notes.\n");
  set("short", "The Shaman Training Room");
  set("long", "This is the room where the shamen come to practice their "+
        "essential skills.\nTo the east is the treasury.  A donation of "+
"5 silver per level is required to enter, but you may store items there.");
  //  "\n" important here, too.
  set_property("light", 2);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/shaman_join");

  set_exits( ([ "south" : "/d/damned/guilds/join_rooms/shaman_join",
                "east" : "/d/damned/guilds/shaman/shaman_treas",
		"west" : "/d/damned/guilds/shaman/shaman_spell_room" ]));
  
  //  All the rest is adding the skills.  The add_skill lines are of the
  //  following form:
  //  	add_skill(string skill, int level, int flag)
  //	skill 		The name of the skill which is being added
  // 	level		The level at which the player may begin
  //			developing the skill.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.
  add_skill("consider", 1);
  add_skill("trade lore", 1, 1);
  add_skill("forage", 3);
  add_skill("reverse stroke", 10);
  add_skill("dodge", 1);
  add_skill("attack", 1);
  add_skill("environmental control", 1);
  add_skill("environmental bonding", 1);
  add_skill("melee", 1);
  add_skill("build fire", 3);
  add_skill("prospecting", 1, 1);
  add_skill("two handed staff", 1);
  add_skill("perception", 1);
  add_skill("torch-making", 1);
  add_skill("swimming", 1);
  add_skill("make waterskin", 5);
  add_skill("erect totem", 7);
  add_skill("blanket weaving", 6);
  add_skill("body block", 1);
  add_skill("assaying", 10);
  return;              
}

void reset() {
  ::reset();
  if(!present("guard", this_object()))
    new("/d/damned/guilds/shaman/t_guard")->move(this_object());
  return;
}
