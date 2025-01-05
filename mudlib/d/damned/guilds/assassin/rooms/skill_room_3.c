inherit "/std/guilds/skill_room";

void create() {
    object ob;
    ::create();
    set_short("Assassin's Training Chamber of Invulnerability");
    set_long("This is a peculiarly shaped room with numerous sharp objects protruding from every part of the ceiling and walls. It is here the Assassin trains for skill with the sacred arts of invulnerability, the most powerful but also by far most expensive weapon in their arsenal.\n\nNOTE: Some of the skills require a prerequisite base value in 'invulnerability mastery', listed under the individual help files for each.\n"); 
    set_property("light", 1);
    set_property("indoors", 1);
    set_join_room("/d/damned/guilds/join_rooms/assassin_join");
    add_exit("/d/damned/guilds/assassin/rooms/skill_room_1.c", "south");
    ob = new("/d/damned/guilds/assassin/misc/shield_statue.c");
    ob->move(this_object());
    add_skill("invulnerability mastery", 1);
    add_skill("phase", 25);
    add_skill("resist stun", 35);
    add_skill("soul channel", 45);
    add_skill("dark will", 60);
    return;
}

void init() {
    ::init();
    add_action("train", "train");
}

int train(string str) {
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
}
