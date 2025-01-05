//	An example skill training room for the fighter's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95
//
// Modified by TW for RI
//      -Tailwind 12/04/01

inherit "/std/guilds/skill_room";

void create() {
  object ob;
  ::create();
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({"board", "royal-infantry_board"}) );
  ob->set_board_id("royal-infantry_board");
  ob->set_max_posts(25);
  ob->set_location("d/damned/guilds/royal-infantry/train_room");
  ob->set("short","Royal-Infantry Board");
  ob->set("long","A board for players to post notes.\n");
  set("short", "The Royal-Infantry Training Tent");
  set("long", "This massive tent houses the training part of the encampment. All around you, you see members of the infantry hacking and slashing at wooden targets, and beating on one another with wooden practice weapons. Judging by the skill of these men, you know you wouldn't want to mess with them.");
  //  "\n" important here, too.
  set_property("light", 3);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/royal-infantry_join");
 add_exit("/d/damned/guilds/royal-infantry/tentcamp", "west");

  
  //  All the rest is adding the skills.  The add_skill lines are of the
  //  following form:
  //  	add_skill(string skill, int level, int flag)
  //	skill 		The name of the skill which is being added
  // 	level		The level at which the player may begin
  //			developing the skill.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.


// General Skills
  add_skill("consider", 1);
  add_skill("trade lore", 1, 1);
  add_skill("block", 1);
  add_skill("prospecting", 1, 1);
  add_skill("perception", 1);
  add_skill("swimming", 1);
  add_skill("body block", 1);
  add_skill("compare", 3);

// Weapon/Attack/Defense Skills
  add_skill("attack", 1);
  add_skill("melee", 1);
  add_skill("dodge", 3);
  add_skill("parry", 1);
  add_skill("blade", 1);
  add_skill("two handed blade", 1);
  add_skill("blunt", 1);
  add_skill("two handed blunt", 1);
  add_skill("flail", 1);
  add_skill("two handed flail", 1);
  add_skill("axe", 1);
  add_skill("two handed polearm", 1);
  add_skill("knife", 1);
  add_skill("thrown", 1);

// General Combat Skills
  add_skill("combat awareness", 9);
  add_skill("reverse stroke", 10);
  add_skill("resist stun", 10);
  add_skill("focused attack",16);

// General RI Skills
  add_skill("reflexes", 6);
  add_skill("team tactics", 2);
  add_skill("ripost", 5);
  add_skill("aerodynamic mastery", 4);

// Shield Bash Skills
  add_skill("royal insignia", 11);
  add_skill("spiked shield", 9);
  add_skill("fiery protector", 5);
  add_skill("shield bash", 3);
  add_skill("acid coat", 7);

// Law Enforcement Skills
  add_skill("behead", 12);
  add_skill("arrest", 4);
  add_skill("royal shocker", 20);

// Cleave Skills
  add_skill("cleave", 5);
  add_skill("scythe", 20);

  return;
}
