inherit "/std/guilds/skill_room";

void create() {
    object ob;
    ::create();
    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id(({ "board", "assassin board" }));
    ob->set_board_id("assassin board");
    ob->set_max_posts(25);
    ob->set_location("/d/damned/guilds/assassin/rooms/skill_room_1");
    ob->set_short("Assassin Board");
    ob->set_long("A rotted board which provides the shadowy assassins of Daybreak Ridge to post many different messages of varying importance and topic.\n");
    set_short("The Assassin Guild Central Training Chamber");
    set_long("This is a noticeably large chamber, complete with numerous skilled trainers and a large bulletin board located somewhere near the center. Exits branch off in every direction from this room, with most of those leading to various seperate training chambers of specialized assassin fields. The up exit leads back to the entrance and treasury level of the guild.\n");
    set_property("light", 1);
    set_property("indoors", 1);
    set_join_room("/d/damned/guilds/join_rooms/assassin_join");
    add_exit("/d/damned/guilds/assassin/rooms/foyer_room.c", "up");
    //add_exit("/d/damned/guilds/assassin/rooms/skill_room_2.c", "west");
    //add_exit("/d/damned/guilds/assassin/rooms/skill_room_3.c", "north");
    //add_exit("/d/damned/guilds/assassin/rooms/skill_room_4.c", "east");
    //add_exit("/d/damned/guilds/assassin/rooms/skill_room_5.c", "south");
    add_exit("/d/damned/guilds/assassin/rooms/spell_room", "down");
    add_skill("swimming", 1);
    add_skill("parry", 1);
    add_skill("knife", 1);
    add_skill("blade", 1);
    add_skill("perception", 1);
    add_skill("trade lore", 1);
    add_skill("attack", 1);
    add_skill("axe", 1);
    add_skill("flail", 1);
    add_skill("blunt", 1);
    add_skill("compare", 1);
    add_skill("dodge", 4);
    add_skill("detect magic", 5);
    add_skill("concentrate", 5);
    add_skill("spell sense", 12);
    add_skill("melee", 1);
    add_skill("consider", 1);
    add_skill("magic mastery", 1);
    add_skill("offhand training", 15);
    add_skill("vision magic", 4);
    add_skill("paralysis magic", 7);
    add_skill("blade magic", 9);
    add_skill("assassin's magic", 12);
//from skill room 2
   add_skill("hide in shadows", 1);
   add_skill("stealth", 10);
   add_skill("stalk", 15);
//from skill room 3
    add_skill("invulnerability mastery", 1);
    add_skill("phase", 25);
    add_skill("resist stun", 35);
    add_skill("soul channel", 45);
    add_skill("dark will", 60);
//from skill room 4
    add_skill("duel mastery", 1);
    add_skill("swiftness", 15);
    add_skill("assassin's desire", 23);
    add_skill("lightning strike", 41);
    add_skill("forbidden fury", 46);
    add_skill("eternal rage", 53);
//from skill room 5
    add_skill("strike mastery", 1);
    add_skill("stab", 3);
    add_skill("assassinations", 12);
    add_skill("pain strike", 27);
    add_skill("mortal attack", 46);

    return;
}

void init() {
    ::init();
    add_action("train", "train");
}


//ADD
int train(string str) {
//from skill room 1
    if(str == "magic mastery" && this_player()->query_base_skill("magic mastery") >= 350) {
	message("info", "You have mastered this path of training and do not need to train this skill further.", this_player());
	return 1;
    }
//from Skill room 3
    if(str == "invulnerability mastery" && this_player()->query_base_skill("invulnerability mastery") >= 400) {
	message("info", "You have mastered this path of training and do not need to train this skill further.", this_player());
	return 1;
    }
    if(str == "phase" && this_player()->query_base_skill("invulnerability mastery") < 150) {
	message("info", "You must have at least 150% base skill in invulnerability mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "resist stun" && this_player()->query_base_skill("invulnerability mastery") < 225) {
	message("info", "You must have at least 225% base skill in invulnerability mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "soul channel" && this_player()->query_base_skill("invulnerability mastery") < 300) {
	message("info", "You must have at least 300% base skill in invulnerability mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "dark will" && this_player()->query_base_skill("invulnerability mastery") < 400) {
	message("info", "You must have at least 400% base skill in invulnerability mastery to train this skill.", this_player());
	return 1;
    }
//add skill room 4
 if(str == "duel mastery" && this_player()->query_base_skill("duel mastery") >= 350) {
	message("info", "You have mastered this path of training and do not need to train this skill further.", this_player());
	return 1;
    }
    if(str == "swiftness" && this_player()->query_base_skill("duel mastery") < 125) {
	message("info", "You must have at least 125% base skill in duel mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "assassin's desire" && this_player()->query_base_skill("duel mastery") < 175) {
	message("info", "You must have at least 175% base skill in duel mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "lightning strike" && this_player()->query_base_skill("duel mastery") < 250) {
	message("info", "You must have at least 250% base skill in duel mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "forbidden fury" && this_player()->query_base_skill("duel mastery") < 300) {
	message("info", "You must have at least 300% base skill in duel mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "eternal rage" && this_player()->query_base_skill("duel mastery") < 350) {
	message("info", "You must have at least 350% base skill in duel mastery to train this skill.", this_player());
	return 1;
    }
//add from skill room 5
if(str == "strike mastery" && this_player()->query_base_skill("strike mastery") >= 300) {
	message("info", "You have mastered this path of training and do not need to train this skill further.", this_player());
	return 1;
    }
    if(str == "assassination" && this_player()->query_base_skill("strike mastery") < 100) {
	message("info", "You must have at least 100% base skill in strike mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "pain strike" && this_player()->query_base_skill("strike mastery") < 200) {
	message("info", "You must have at least 200% base skill in strike mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "mortal attack" && this_player()->query_base_skill("strike mastery") < 300) {
	message("info", "You must have at least 300% base skill in strike mastery to train this skill.", this_player());
	return 1;
    }
}
//end add
