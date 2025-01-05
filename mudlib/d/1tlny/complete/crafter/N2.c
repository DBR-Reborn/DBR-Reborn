
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room_any";

void create() {

  ::create();

  set("short", "Training Room");
  set("long", "This is a room that you can train global skills for all players. You need to join a guild to train skills for a specific guild to learn attack skills or spells.\n");

  set_property("light", 2);
  set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
  
  //  The following line is VERY, VERY important.
  //set_join_room("/d/damned/guilds/join_rooms/paladin_join");
  set_join_room("/d/damned/guilds/join_rooms/child_join");

  add_exit("/d/daybreak/room/db_square", "out");
  add_exit("/d/daybreak/room/N3", "north");

  
  //  All the rest is adding the skills.  The add_skill lines are of the
  //  following form:
  //  	add_skill(string skill, int level, int flag)
  //	skill 		The name of the skill which is being added
  // 	level		The level at which the player may begin
  //			developing the skill.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.



  add_skill("prospecting", 1, 1);
  add_skill("swimming", 1);
  add_skill("compare", 1);
  add_skill("trade lore", 1, 1);
  add_skill("repair weapon", 1);
   add_skill("engrave",5);

   add_skill("inscribe crusher", 30);
   add_skill("inscribe cutter", 30);
   add_skill("inscribe impaler", 30);
   add_skill("inscribe impacter", 30);
   add_skill("inscribe stresser", 30);
   add_skill("inscribe firer", 30);
   add_skill("inscribe colder", 30);
   add_skill("inscribe vacummer", 30);
   add_skill("inscribe electriciter", 33);
   add_skill("inscribe disrupter", 34);
   add_skill("inscribe plasmer", 35);

   add_skill("inscribe paree", 38);
   add_skill("inscribe preciser", 38);
   add_skill("inscribe quickness", 38);


   add_skill("inscribe aether", 50);
   add_skill("inscribe holyer", 50);
   add_skill("inscribe inferner", 50);
   add_skill("inscribe striker", 50);
   add_skill("inscribe unholyer", 50);

  return;
}




