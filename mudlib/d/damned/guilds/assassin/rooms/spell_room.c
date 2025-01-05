inherit "/std/guilds/spell_room";

void create() {
    ::create();
    set_short("Assassin's Training Chamber of Magic");
    set_long("You are now in a medium sized but extremely dark basement, the end of a stone stairway from the upstairs central training room. It is here that the powerful death artists train all of their magic which they use in all different types of combat situations.\n\nNOTE: Some of the spells require prerequisite base values however to train, which are listed in the spell help files.\n");
    set_property("light", 1);
    set_property("indoors", 1);
    set_join_room("/d/damned/guilds/join_rooms/assassin_join");
    add_exit("/d/damned/guilds/assassin/rooms/skill_room_1.c", "up");
    add_spell("eye seal", 4);
    add_spell("black vision", 4);
    add_spell("keen detection", 10);
    add_spell("blackout", 18);
    add_spell("mind freeze", 7);
    add_spell("stun blast", 14);
    add_spell("pain", 42);
    add_spell("force blade", 12);
    add_spell("striking point", 16);
    add_spell("edge of inertia", 26);
    add_spell("assassination blade", 38);
   // add_spell("pain blade", 51); (missing files, Honspron)
    add_spell("enemy vision", 12);
    add_spell("mental lock", 16);
    add_spell("teleportation", 17);
    add_spell("fade", 19);
    add_spell("total vanish", 34);
    add_spell("alternate body", 37);
    add_spell("time leap", 40);
    return;
}

void init() {
    ::init();
    add_action("train", "train");
}

int train(string str) {
    if(str == "teleportation" && this_player()->query_base_skill("magic mastery") < 75) {
	message("info", "You must have at least 75% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
    if(str == "keen detection" && this_player()->query_base_skill("magic mastery") < 75) {
	message("info", "You must have at least 75% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
    if(str == "blackout" && this_player()->query_base_skill("magic mastery") < 150) {
	message("info", "You must have at least 150% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
    if(str == "stun blast" && this_player()->query_base_skill("magic mastery") < 100) {
	message("info", "You must have at least 100% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
    if(str == "pain" && this_player()->query_base_skill("magic mastery") < 250) {
	message("info", "You must have at least 250% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
    if(str == "striking point" && this_player()->query_base_skill("magic mastery") < 100) {
	message("info", "You must have at least 100% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
    if(str == "edge of inertia" && this_player()->query_base_skill("magic mastery") < 175) {
	message("info", "You must have at least 175% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
    if(str == "assassination blade" && this_player()->query_base_skill("magic mastery") < 250) {
	message("info", "You must have at least 250% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
    if(str == "pain blade" && this_player()->query_base_skill("magic mastery") < 350) {
	message("info", "You must have at least 350% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
    if(str == "fade" && this_player()->query_base_skill("magic mastery") < 100) {
	message("info", "You must have at least 100% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
    if(str == "total vanish" && this_player()->query_base_skill("magic mastery") < 200) {
	message("info", "You must have at least 200% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
    if(str == "time leap" && this_player()->query_base_skill("magic mastery") < 225) {
	message("info", "You must have at least 225% base skill in magic mastery to train this spell.", this_player());
	return 1;
    }
}
