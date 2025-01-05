inherit "/std/guilds/skill_room";

void create() {
    object ob;
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_short("Assassin's Training Chamber of Assassination");
    set_long("This is a perfectly circular chamber with a somewhat low ceiling, with many dark cloaked figures standing at posts holding various weapons. The Assassin in this room with those figures who serve as trainers practice their heavily artistic methods of lethal assassination, the initial and often strongest blow against their targets.\n\nNOTE: Some of the skills require a prerequisite base value in 'strike mastery', listed under the individual help files for each.\n");
    set_join_room("/d/damned/guilds/join_rooms/assassin_join");
    add_exit("/d/damned/guilds/assassin/rooms/skill_room_1.c", "north");
    ob = new("/d/damned/guilds/assassin/misc/dagger_statue.c");
    ob->move(this_object());
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

int train(string str) {
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
