inherit "/std/guilds/skill_room";

void create() {
    object ob;
    ::create();
    set_short("Assassin's Training Chamber of Combat Enhancement");
    set_long("This significantly sized room is filled with numerous dummies, each of which are both armoured and positioned differently as if they signify every imaginable stance of combat. In this chamber the Assassin upgrades his or her talents in the general arts of war, which are in turn used as solid backup to their direct mortal assassination attempts should they fail to kill.\n\nNOTE: Some of the skills require a prerequisite base value in 'duel mastery', listed under the individual help files for each.\n");
    set_property("light", 1);
    set_property("indoors", 1);
    set_join_room("/d/damned/guilds/join_rooms/assassin_join");
    add_exit("/d/damned/guilds/assassin/rooms/skill_room_1.c", "west");
    ob = new("/d/damned/guilds/assassin/misc/axe_statue.c");
    ob->move(this_object());
    add_skill("duel mastery", 1);
    add_skill("swiftness", 15);
    add_skill("assassin's desire", 23);
    add_skill("lightning strike", 41);
    add_skill("forbidden fury", 46);
    add_skill("eternal rage", 53);
    return;
}

void init() {
    ::init();
    add_action("train", "train");
}

int train(string str) {
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
}
