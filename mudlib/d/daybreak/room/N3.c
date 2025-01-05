
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95

inherit "/std/guilds/skill_room_any";

void create() {

  ::create();

  set("short", "Training Room");
  set("long", "This is a room that you can train global skills for armour for all players. You need to join a guild to train skills for a specific guild to learn attack skills or spells. Come back at level 30 or higher this room has hidden skills\n");

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

  add_exit("/d/daybreak/room/N2", "south");

  
  //  All the rest is adding the skills.  The add_skill lines are of the
  //  following form:
  //  	add_skill(string skill, int level, int flag)
  //	skill 		The name of the skill which is being added
  // 	level		The level at which the player may begin
  //			developing the skill.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.



   add_skill("inscribe lifta", 30);
   add_skill("inscribe crusha", 30);
   add_skill("inscribe cutta", 30);
   add_skill("inscribe impala", 30);
   add_skill("inscribe impacta", 40);
   add_skill("inscribe stressa", 40);
   add_skill("inscribe fira", 40);
   add_skill("inscribe colda", 40);
   add_skill("inscribe vacumma", 50);
   add_skill("inscribe electricita", 60);
   add_skill("inscribe disrupta", 70);
   add_skill("inscribe plasa", 80);

   add_skill("inscribe aetha", 100);
   add_skill("inscribe holya", 100);
   add_skill("inscribe unholya", 100);
   add_skill("inscribe inferna", 100);
   add_skill("inscribe strika", 100);


  
  return;
}



