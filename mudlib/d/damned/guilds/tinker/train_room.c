//	An example skill training room for the fighter's guild.
// room improved by Excelsior 4-5-96
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room";

void create() {
  object ob;
  ::create();
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({"board", "tinker_board"}) );
  ob->set_board_id("tinker_board");
  ob->set_max_posts(25);
  ob->set_location("d/damned/guilds/tinker/train_room");
  ob->set("short","tinker Board");
  ob->set("long","A board for players to post notes.\n");
  set("short", "The tinkers' Training Room");
  set("long", 
"This room is lined with book cases. At a glance you can tell that these books "+
"teach the ways of the tinker. In the center of the room is an "+
"anvil, a hammer, and several other important tinker tools. "+
"This is the room where tinkers learn their skills and "+
"practice them as well!  A staircase leads down.\n");
  //  "\n" important here, too.
	set_items(([
"staircase":"It spirals down right through the floor.",
"treasury":"It is to your west"]));

  set_property("light", 2);
set_property("no scry", 1);
set_property("no summon", 1);
set_property("no teleport", 1);

  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/tinker_join");

  set_exits( ([ "down" : "/d/damned/guilds/join_rooms/tinker_join",
	     "west" : "/d/damned/guilds/tinker/forge_room",
	     "east" : "/d/damned/guilds/tinker/train_room2", ]));
  
  //  All the rest is adding the skills.  The add_skill lines are of the
  //  following form:
  //  	add_skill(string skill, int level, int flag)
  //	spell 		The name of the skill which is being added
  // 	level		The level at which the player may begin
  //			developing the skill.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.

    add_skill("blade", 1);
    add_skill("blunt", 1);
    add_skill("knife", 1);
    add_skill("two handed blade", 1);
    add_skill("two handed blunt", 1);
    add_skill("two handed flail", 3,1);
    add_skill("blacksmith", 1);
    add_skill("carpentry", 1);
    add_skill("parry", 1);
    add_skill("block", 1);
    add_skill("prospecting", 1);
    add_skill("perception", 1, 1);
    add_skill("attack", 1);
    add_skill("consider", 1);
    add_skill("compare", 1);
    add_skill("swimming", 1);
    add_skill("melee", 1);
    add_skill("repair weapon", 1);
    add_skill("repair wood weapon", 1);
    add_skill("body block", 1);
    add_skill("trade lore", 1);
    add_skill("combat awareness",16,1);

    add_skill("minning", 1);
    add_skill("lumberjack", 1);
    add_skill("axe",1);

    add_skill("skin corpse", 3);
    add_skill("dodge", 3);
    add_skill("leather craft",3);

    add_skill("inscribe zalm lit", 4);
    add_skill("engrave",4);

    add_skill("install lock", 5);
    add_skill("inscribe malsa koren", 5);
    add_skill("inscribe aldara zet", 5);
    add_skill("whirlwind attack", 5);

    add_skill("inscribe xen mora", 7);
    add_skill("forge armour", 7);
    add_skill("forge weapon", 7);
    add_skill("woodwork weapon", 7);
    add_skill("woodwork armour", 7);

    add_skill("inscribe malsa bonnes", 8);
    add_skill("offhand training", 8);

    add_skill("inscribe anck athin",10);

    add_skill("balance weapon", 11);

    add_skill("inscribe malsa xen", 12);
    add_skill("inscribe malsa sen zora", 12);
    add_skill("inscribe harah lit", 12);

    add_skill("dual attack", 13);
    add_skill("reverse stroke", 13);

    add_skill("rune lore", 14);

//NEW TLNY2020 See train_room2
/* 
   add_skill("inscribe crusher", 17);
   add_skill("inscribe crusha", 17);
   add_skill("inscribe strika", 17);

   add_skill("inscribe cutter", 18);
   add_skill("inscribe cutta", 18);

   add_skill("inscribe impaler", 19);
   add_skill("inscribe impala", 19);

   add_skill("inscribe impacter", 20);
   add_skill("inscribe impacta", 20);

   add_skill("inscribe stresser", 21);
   add_skill("inscribe stressa", 21);

   add_skill("inscribe firer", 22);
   add_skill("inscribe fira", 22);

   add_skill("inscribe colder", 23);
   add_skill("inscribe colda", 23);

   add_skill("inscribe vacummer", 24);
   add_skill("inscribe vacumma", 24);

   add_skill("inscribe electriciter", 25);
   add_skill("inscribe electricita", 25);
   add_skill("inscribe disrupter", 25);
   add_skill("inscribe disrupta", 25);

   add_skill("inscribe plasmer", 26);
   add_skill("inscribe plasa", 26);

   add_skill("inscribe paree", 30);
   add_skill("inscribe preciser", 30);
   add_skill("inscribe quickness", 30);
   add_skill("inscribe lifta", 30);

   add_skill("inscribe aether", 45);
   add_skill("inscribe inferner", 44);
   add_skill("inscribe striker", 43);
   add_skill("inscribe holyer", 42);
   add_skill("inscribe unholyer", 41);

   add_skill("inscribe aetha", 40);
   add_skill("inscribe holya", 40);
   add_skill("inscribe unholya", 40);
   add_skill("inscribe inferna", 40);
*/

  return;
}

