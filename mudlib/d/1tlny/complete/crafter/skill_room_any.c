
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room_any";

void create() {

  ::create();

  set("short", "Training Room");
  set("long", "This is the room that you can train Global skills.\n");

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

  
  //  All the rest is adding the skills.  The add_skill lines are of the
  //  following form:
  //  	add_skill(string skill, int level, int flag)
  //	skill 		The name of the skill which is being added
  // 	level		The level at which the player may begin
  //			developing the skill.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.




   add_skill("inscribe crusher", 1);
   add_skill("inscribe cutter", 1);
   add_skill("inscribe impaler", 1);
   add_skill("inscribe impacter", 1);
   add_skill("inscribe stresser", 1);
   add_skill("inscribe firer", 1);
   add_skill("inscribe colder", 1);
   add_skill("inscribe vacummer", 1);
   add_skill("inscribe electriciter", 1);
   add_skill("inscribe disrupter", 1);
   add_skill("inscribe plasmer", 1);

// TOO powerful
/*
   add_skill("inscribe striker", 1);
   add_skill("inscribe holyer", 1);
   add_skill("inscribe unholyer", 1);
   add_skill("inscribe inferner", 1);
   add_skill("inscribe aether", 1);
*/
  
  return;
}




