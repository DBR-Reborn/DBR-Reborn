inherit "/std/guilds/skill_room";

void create() {
    object ob;
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_short("Assassin's Training Chamber of Stealth");
    set_long("This relatively small room is by far the darkest in the entire guild, both in lighting level and color. It is in this chamber that all aspiring assassins train in the arts of stealth and shadowing, both very vital tools in their vast arsenal.\n\nNOTE: Some of the skills require a prerequisite base value in 'stealth mastery', listed under the individual help files for each.\n");
    set_join_room("/d/damned/guilds/join_rooms/assassin_join");
    add_exit("/d/damned/guilds/assassin/rooms/skill_room_1.c", "east");
    ob = new("/d/damned/guilds/assassin/misc/robe_statue.c");
    ob->move(this_object());
  // Removing broken skills and add the Night Blade skills...Honspron
   //add_skill("stealth mastery", 1);
   //add_skill("shadow walk", 1);
   //add_skill("shadow target", 12);
   //add_skill("invisible walk", 31);
   //add_skill("parasitic fixation", 37);
   //add_skill("master walk", 51);
   //add_skill("unseen mime", 54);
   add_skill("hide in shadows", 1);
   add_skill("stealth", 10);
   add_skill("stalk", 15);
    return;
}

void init() {
    ::init();
    add_action("train", "train");
}

int train(string str) {
    if(str == "stealth mastery" && this_player()->query_base_skill("stealth mastery") >= 325) {
	message("info", "You have mastered this path of training and do not need to train this skill further.", this_player());
	return 1;
    }
    if(str == "shadow target" && this_player()->query_base_skill("stealth mastery") < 75) {
	message("info", "You must have at least 75% base skill in stealth mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "invisible walk" && this_player()->query_base_skill("stealth mastery") < 175) {
	message("info", "You must have at least 175% base skill in stealth mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "parasitic fixation" && this_player()->query_base_skill("stealth mastery") < 225) {
	message("info", "You must have at least 225% base skill in stealth mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "master walk" && this_player()->query_base_skill("stealth mastery") < 300) {
	message("info", "You must have at least 300% base skill in stealth mastery to train this skill.", this_player());
	return 1;
    }
    if(str == "unseen mime" && this_player()->query_base_skill("stealth mastery") < 325) {
	message("info", "You must have at least 325% base skill in stealth mastery to train this skill.", this_player());
	return 1;
    }
}
